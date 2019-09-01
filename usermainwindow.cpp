#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include <QTimer>
#include <QDateTime>

UserMainWindow::UserMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
}

UserMainWindow::~UserMainWindow()
{
    delete ui;
}

void UserMainWindow::on_pushButton_changeUser_clicked()
{
    this->hide();
    emit showLoginWindow();
}

void UserMainWindow::receiveLogin()
{
    SqlFuns sf;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);
    this->show();
}

void UserMainWindow::timerUpdate()  //显示当前时间
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_currentTime->setText(str);
}

void UserMainWindow::on_pushButton_editPersonalInfo_clicked()
{
    emit showInfoChangeWindow();
}

void UserMainWindow::infoChangeDone()
{
    SqlFuns sf;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);
}
