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

    if(user == "admin")
        emit  showAdminMainWindow();
    else if(user == "user")
        emit  showUserMainWindow();
    this->close();
}

void LoginDialog::userExchange()
{
    this->show();
    //emit showMainWindow();
}

void LoginDialog::on_pushButton_register_clicked()
{
    emit showRegisterWindow();
}
