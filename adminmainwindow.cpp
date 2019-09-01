#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::receiveLogin()
{
    SqlFuns sf;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);
    this->show();
}

void AdminMainWindow::on_pushButton_changeUser_clicked()
{
    this->hide();
    emit showLoginWindow();
}

void AdminMainWindow::timerUpdate()  //显示当前时间
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_currentTime->setText(str);
}

void AdminMainWindow::on_pushButton_editPersonalInfo_clicked()
{
    emit showInfoChangeWindow();
}

void AdminMainWindow::on_pushButton_addNewMovie_clicked()
{
    emit showAddNewFilmWindow();
}

void AdminMainWindow::on_pushButton_addNewHall_clicked()
{
    SqlFuns sf;
    sf.addNewHall("#2LaserHall", "YouthLight", 150, 9, 21, "222000000000000022222200000000000000022222200000000000000022222200000000000000022222200000000000000022000200000000000000022000200000000000000022000200000000000000022000000000000000000000002", "3DImax");
    sf.addNewHall("#5Hall", "WanDaJGC", 71, 6, 13, "000000000002200000000000220000000000002000000000000200000000000020000000000000", "3D");
    sf.addNewHall("#7Hall", "WanDaJGC", 65, 7, 10, "00000000002000000000000000000020000000002000000000200000000020000000000", "3D");
    sf.addNewHall("LD3LaserDolByHall", "LUMIERE", 116, 9, 16, "200000000000000020000000000000002000000000000000200000000000222220000000000022222000000000002222200000000000222220000000000022000000000000000022", "Dolby Atmos/X-DMAX");
}

void AdminMainWindow::infoChangeDone()
{
    SqlFuns sf;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);
}
