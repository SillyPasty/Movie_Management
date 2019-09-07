/*
 * 用户注册界面
 * 利用密钥判断注册人是否拥有管理员身份
 * 使用正则表达式判断邮箱是否合法
 * 对可能出现的异常情况做出了判断
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    this->setMaximumSize(310, 370);
    this->setMinimumSize(310, 370);
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
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
    // 槽函数 清空当前输入栏内内容
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
            if(key == "admin")  //判断密钥是否正确
                isAdmin = 1;
            else
            {
                isAdmin = 0;
                cinema = "";
            }
            QString pattern("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$");  // 正则表达式判断邮箱是否合法
            QRegExp rx(pattern);
            if(phone.length() == 11  && 6 <= psd.length() && psd.length() <= 20 && rx.exactMatch(email) && 0 < name.length() && 6 <= userName.length() && userName.length() <= 10)
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
