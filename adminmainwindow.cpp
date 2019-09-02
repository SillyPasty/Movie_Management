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
void AdminMainWindow::updateMovieTable(QSqlTableModel *model)
{

    ui->tableView_movie->setModel(model);
    ui->tableView_movie->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_movie->setSelectionBehavior(QAbstractItemView::SelectRows);
    //  设置部分显示
    ui->tableView_movie->setColumnHidden(0, true);
    ui->tableView_movie->setColumnHidden(1, true);
    ui->tableView_movie->setColumnHidden(17, true);
    ui->tableView_movie->setColumnHidden(18, true);
    ui->tableView_movie->setColumnHidden(19, true);

    ui->tableView_movie->resizeColumnsToContents();
    ui->tableView_movie->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void AdminMainWindow::updateHallTable(QSqlTableModel *model)
{
    ui->tableView_currentHall->setModel(model);
    ui->tableView_currentHall->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_currentHall->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置部分显示
    ui->tableView_currentHall->setColumnHidden(0, true);
    ui->tableView_currentHall->setColumnHidden(2, true);
    ui->tableView_currentHall->setColumnHidden(4, true);
    //  设置大小宽度
    ui->tableView_movie->resizeColumnsToContents();
    ui->tableView_movie->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void AdminMainWindow::receiveLogin()
{
    SqlFuns sf;
    // 初始化
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);



    updateMovieTable(sf.queryAdminMovie("",""));
    updateHallTable(sf.queryAdminHall(""));
    ui->comboBox_hall_2->clear();
    ui->comboBox_hall_2->addItem("");
    ui->comboBox_hall_2->addItems(sf.queryHallId(sf.queryCinema(global_userName)));
    ui->comboBox_hall->clear();
    ui->comboBox_hall->addItem("");
    ui->comboBox_hall->addItems(sf.queryHallId(sf.queryCinema(global_userName)));

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

void AdminMainWindow::receiveMovieInfoChange()
{
    SqlFuns sf;
    updateMovieTable(sf.queryAdminMovie("",""));
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

void AdminMainWindow::on_pushButton_search_2_clicked()
{
    SqlFuns sf;
    QString movieName = ui->lineEdit_movieName_2->text().trimmed();
    QString hallId = ui->comboBox_hall_2->currentText();
    updateMovieTable(sf.queryAdminMovie(movieName, hallId));
}


void AdminMainWindow::on_comboBox_hall_currentTextChanged(const QString &arg1)
{
    SqlFuns sf;
    QString hallId = ui->comboBox_hall->currentText();
    updateHallTable(sf.queryAdminHall(hallId));
}
