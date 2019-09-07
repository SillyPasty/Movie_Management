/*
 * 本文件内实现了更改个人信息功能
 * 利用正则表达式判断邮箱是否合法
 * 同时对其他信息合法性进行了判断
 *
 */
#include "infochange.h"
#include "ui_infochange.h"

InfoChange::InfoChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoChange)
{
    ui->setupUi(this);
    this->setWindowTitle("修改信息");
    this->setMaximumSize(284, 252);
    this->setMinimumSize(284, 252);
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
    ui->lineEdit_newPasd->setEchoMode(QLineEdit::Password);
}

InfoChange::~InfoChange()
{
    delete ui;
}

void InfoChange::on_pushButton_confirm_clicked()
{
    //  change the info
    SqlFuns sf;
    QString psd = ui->lineEdit_newPasd->text().trimmed();
    QString eml = ui->lineEdit_newEmail->text().trimmed();
    QString phn = ui->lineEdit_phoneNum->text().trimmed();
    QString pattern("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$"); //正则表达式判断邮箱是否合法
    QRegExp rx(pattern);
    if(phn.length() == 11 && 6 <= psd.length() && psd.length() <= 10 && rx.exactMatch(eml))
    {
        sf.changeUserInfo(eml, psd, phn);
        this->close();
        emit infoChanged();
    }
    else
        QMessageBox::critical(nullptr, "输入有误", "请重新输入");
}

void InfoChange::receiveInfoChange()
{
    ui->lineEdit_newPasd->clear();
    ui->lineEdit_newEmail->clear();
    this->show();
}
