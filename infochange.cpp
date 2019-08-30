#include "infochange.h"
#include "ui_infochange.h"

InfoChange::InfoChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoChange)
{
    ui->setupUi(this);
}

InfoChange::~InfoChange()
{
    delete ui;
}

void InfoChange::on_pushButton_confirm_clicked()
{
    //  change the info
    this->close();
}

void InfoChange::receiveInfoChange()
{
    this->show();
}
