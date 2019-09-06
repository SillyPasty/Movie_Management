/*
 * 本文件内实现了用户登陆界面的各项功能
 * 通过对数据库密码的查找并比对，实现了登陆功能
 * 并根据用户身份自动进入管理院界面或用户界面
*/
#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登陆");
    this->setMaximumSize(379, 311);
    this->setMinimumSize(379, 311);
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
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
    if(user == "" || pswd == "")
        QMessageBox::critical(nullptr, "请输入信息", "请重新输入");
    else if(psw == pswd)
    {
        int flag = sf.queryIsadmin(user);
        //对全局变量进行赋值
        global_userName = user;
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

void LoginDialog::userExchange() // 槽函数：接受切换用户信号
{
    ui->lineEdit_userName->clear();
    ui->lineEdit_password->clear();
    this->show();
}

void LoginDialog::on_pushButton_register_clicked()
{
    emit showRegisterWindow();
}
