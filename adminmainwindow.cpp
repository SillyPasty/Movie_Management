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
    ui->dateEdit_inquire01->setCalendarPopup(true);
    ui->dateEdit_inquire02->setCalendarPopup(true);
    // 设置座位图选项
    ui->tableWidget_seatMaps->horizontalHeader()->hide();
    ui->tableWidget_seatMaps->verticalHeader()->hide();
    ui->tableWidget_seatMaps->setShowGrid(false);
    ui->tableWidget_seatMaps->verticalHeader()->setDefaultSectionSize(20);
    ui->tableWidget_seatMaps->horizontalHeader()->setDefaultSectionSize(20);
    ui->tableWidget_seatMaps->setStyleSheet("selection-background-color:white;");
    ui->tableWidget_seatMaps->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget_seatMaps->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

    ui->tableView_movie->setSortingEnabled(true);
    ui->tableView_orders->setSortingEnabled(true);
    ui->tableView_currentHall->setSortingEnabled(true);

    ui->comboBox_hall_2->clear();
    ui->comboBox_hall_2->addItem("");
    ui->comboBox_hall_2->addItems(sf.queryHallId(sf.queryCinema(global_userName)));
    ui->comboBox_hall->clear();
    ui->comboBox_hall->addItem("");
    ui->comboBox_hall->addItems(sf.queryHallId(sf.queryCinema(global_userName)));

    updateOrdersTable(sf.queryAdminOrder("", "", "", "", 0));

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
    emit showAddNewHallWindow();
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

void AdminMainWindow::updateOrdersTable(QSqlTableModel *model)
{

    ui->tableView_orders->setModel(model);
    ui->tableView_orders->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_orders->setSelectionBehavior(QAbstractItemView::SelectRows);

    //  设置部分显示
    ui->tableView_orders->setColumnHidden(0, true);
    ui->tableView_orders->setColumnHidden(1, true);
    ui->tableView_orders->setColumnHidden(3, true);

    ui->tableView_movie->resizeColumnsToContents();
    ui->tableView_movie->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void AdminMainWindow::on_pushButton_search_clicked()
{
    SqlFuns sf;
    QString userName = ui->lineEdit_userName->text().trimmed();
    QString movieName = ui->lineEdit_movieName->text().trimmed();
    QString startDate = "", endDate = "";
    int choice = 0;
    if(ui->checkBox_dateAvi->isChecked())
    {
        startDate = ui->dateEdit_inquire01->date().toString("yyyy-MM-dd");
        endDate = ui->dateEdit_inquire02->date().toString("yyyy-MM-dd");
    }
    if(startDate <= endDate)
    {
        if(ui->checkBox_isPlayed->isChecked())
            choice += 2;
        if(ui->checkBox_unPlayed->isChecked())
            choice += 1;
        updateOrdersTable(sf.queryAdminOrder(movieName, userName, startDate, endDate, choice));
    }
    else
        QMessageBox::critical(nullptr, "输入有误", "请重新输入");
}

void AdminMainWindow::receiveHallAdded()
{
    SqlFuns sf;
    updateHallTable(sf.queryAdminHall(""));
    ui->comboBox_hall_2->clear();
    ui->comboBox_hall_2->addItem("");
    ui->comboBox_hall_2->addItems(sf.queryHallId(sf.queryCinema(global_userName)));
    ui->comboBox_hall->clear();
    ui->comboBox_hall->addItem("");
    ui->comboBox_hall->addItems(sf.queryHallId(sf.queryCinema(global_userName)));
}

void AdminMainWindow::showSeat(QString seatMap)
{
    QChar choice;
    QList<QTableWidgetItem *> ql;
    for(int i = 0; i < 252; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        choice = seatMap[i];
        if(choice == "0")
        {
            item->setIcon(QPixmap(":/new/prefix1/avi1.png"));
            item->setData(Qt::UserRole, 1);
            item->setFlags(item->flags()& ~Qt::ItemIsSelectable);
        }
        else
        {
            item->setIcon(QPixmap(":/new/prefix1/blank.png"));
            item->setData(Qt::UserRole, 0);
            item->setFlags(item->flags() & !Qt::ItemIsEnabled & !Qt::ItemIsSelectable);
        }
        ql.append(item);
    }
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 21; j++)
            ui->tableWidget_seatMaps->setItem(i, j, ql[i * 21 + j]);
}

void AdminMainWindow::on_tableView_currentHall_clicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tableView_currentHall->model();
    showSeat(model->data(model->index(index.row(), 4)).toString());
}
