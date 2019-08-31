#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_login_clicked()
{
    QString user = ui->lineEdit_userName->text().trimmed();
    QString pswd = ui->lineEdit_password->text().trimmed();
    SqlFuns sf;
    QString psw = sf.queryPassword(user);
    if(psw == pswd)
    {
        int flag = sf.queryIsadmin(user);
        if(flag)
            emit  showAdminMainWindow();
        else
            emit  showUserMainWindow();
        this->close();
    }
    else if(psw == "")
        QMessageBox::critical(nullptr, "用户不存在", "请重新输入");
    else
        QMessageBox::critical(nullptr, "密码错误", "请重新输入");
}

void LoginDialog::userExchange()
{
    this->show();
}

void LoginDialog::on_pushButton_register_clicked()
{
    emit showRegisterWindow();
}
