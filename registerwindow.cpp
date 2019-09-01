#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->lineEdit_psd->setEchoMode(QLineEdit::Password);
    //  使管理员注册项不可用
    ui->lineEdit_cinemaId->setEnabled(false);
    ui->lineEdit_adminKey->setEnabled(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::receiveRegister()
{
    ui->lineEdit_userName->clear();
    ui->lineEdit_realName->clear();
    ui->lineEdit_psd->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_number->clear();
    ui->lineEdit_cinemaId->clear();
    ui->lineEdit_adminKey->clear();
    this->show();
}

void RegisterWindow::on_checkBox_isAdmin_clicked(bool checked)
{
    if(checked)
    {
        //  使管理员注册项可用
        ui->lineEdit_cinemaId->setEnabled(true);
        ui->lineEdit_adminKey->setEnabled(true);
    }
    else
    {
        //  使管理员注册项不可用
        ui->lineEdit_cinemaId->setEnabled(false);
        ui->lineEdit_adminKey->setEnabled(false);
    }
}

void RegisterWindow::on_pushButton_confirm_clicked()
{    
    //  向数据库中写入新信息
    SqlFuns sf;
    QString userName = ui->lineEdit_userName->text().trimmed();
    QString sex = ui->comboBox_sex->currentText();
    QString name = ui->lineEdit_realName->text().trimmed();
    QString psd = ui->lineEdit_psd->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString phone = ui->lineEdit_number->text().trimmed();
    QString cinema = ui->lineEdit_cinemaId->text().trimmed();
    QString key = ui->lineEdit_adminKey->text().trimmed();
    if(0 < userName.length())
    {
        QString flag = sf.queryPassword(userName);
        if(flag == "")
        {
            int isAdmin;
            if(key == "admin")
                isAdmin = 1;
            else
            {
                isAdmin = 0;
                cinema = "";
            }
            QString pattern("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$");
            QRegExp rx(pattern);
            if(phone.length() == 11  && 6 <= psd.length() && psd.length() <= 10 && rx.exactMatch(email) && 0 < name.length())
            {
                sf.registerUser(userName, psd, name, sex, phone, email, isAdmin, cinema);

                //  关闭窗口
                this->close();
            }
            else
                QMessageBox::critical(nullptr, "输入有误", "请重新输入");
        }
        else
            QMessageBox::critical(nullptr, "用户名已存在", "请重新输入");
    }
    else
        QMessageBox::critical(nullptr, "输入有误", "请重新输入");
}
