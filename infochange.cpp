#include "infochange.h"
#include "ui_infochange.h"

InfoChange::InfoChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoChange)
{
    ui->setupUi(this);
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
    QString pattern("^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$");
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
