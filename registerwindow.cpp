#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
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

    //  关闭窗口
    this->close();
}
