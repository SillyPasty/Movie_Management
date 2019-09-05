#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员窗口");
    this->setMaximumSize(1058, 705);
    this->setMinimumSize(1058, 705);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(checkIsPlayed()));
    timer1->start(300000);
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
    ui->tableView_currentHall->resizeColumnsToContents();
    ui->tableView_currentHall->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

    QSqlTableModel * model = sf.queryAdminMovie("", "");
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<"长度(分钟)"<<"是否放映"<<"价格"<<"余票"<<"类型"<<"是否推荐"<<"总座位"<<"售率占比"<<"总收入"<<"日期"<<"行数"<<"列数"<<""<<"语言"<<"是否打折";
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);

    updateMovieTable(model);

    QSqlTableModel * model1 = sf.queryAdminHall("");
    QStringList head1;
    head1<<""<<"影厅名"<<"电影名"<<"总作为"<<""<<"行数"<<"列数"<<"种类";
    for(int i = 0; i < 8; i++)
        model1->setHeaderData(i, Qt::Horizontal, head1[i]);

    updateHallTable(model1);

    ui->tableView_movie->setSortingEnabled(true);
    ui->tableView_orders->setSortingEnabled(true);
    ui->tableView_currentHall->setSortingEnabled(true);

    ui->comboBox_hall_2->clear();
    ui->comboBox_hall_2->addItem("");
    ui->comboBox_hall_2->addItems(sf.queryHallId(sf.queryCinema(global_userName)));
    ui->comboBox_hall->clear();
    ui->comboBox_hall->addItem("");
    ui->comboBox_hall->addItems(sf.queryHallId(sf.queryCinema(global_userName)));
    QStringList head2;
    head2<<""<<""<<"用户"<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<"座位1"<<"座位2"<<"座位3"<<"是否支付"<<"价格";
    QSqlTableModel * model2 = sf.queryAdminOrder("", "", "", "", 0);
    for(int i = 0; i < 16; i++)
        model2->setHeaderData(i, Qt::Horizontal, head2[i]);
    updateOrdersTable(model2);

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
    QSqlTableModel * model = sf.queryAdminMovie("", "");
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<"长度(分钟)"<<"是否放映"<<"价格"<<"余票"<<"类型"<<"是否推荐"<<"总座位"<<"售率占比"<<"总收入"<<"日期"<<"行数"<<"列数"<<""<<"语言"<<"是否打折";
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);

    updateMovieTable(model);
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
    QSqlTableModel * model = sf.queryAdminMovie(movieName, hallId);
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<"长度(分钟)"<<"是否放映"<<"价格"<<"余票"<<"类型"<<"是否推荐"<<"总座位"<<"售率占比"<<"总收入"<<"日期"<<"行数"<<"列数"<<""<<"语言"<<"是否打折";
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);

    updateMovieTable(model);
}


void AdminMainWindow::on_comboBox_hall_currentTextChanged(const QString &arg1)
{
    SqlFuns sf;
    QString hallId = ui->comboBox_hall->currentText();
    QSqlTableModel * model1 = sf.queryAdminHall(hallId);
    QStringList head1;
    head1<<""<<"影厅名"<<"电影名"<<"总作为"<<""<<"行数"<<"列数"<<"种类";
    for(int i = 0; i < 8; i++)
        model1->setHeaderData(i, Qt::Horizontal, head1[i]);

    updateHallTable(model1);
}

void AdminMainWindow::updateOrdersTable(QSqlTableModel *model)
{
    float totalIncome = 0;
    for(int i = 0; i < model->rowCount(); i++)
        totalIncome += model->record(i).value("price").toFloat();
    QString tem;
    ui->label_totalIncome->setText(tem.sprintf("%.2f", totalIncome));
    ui->tableView_orders->setModel(model);
    ui->tableView_orders->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_orders->setSelectionBehavior(QAbstractItemView::SelectRows);

    //  设置部分显示
    ui->tableView_orders->setColumnHidden(0, true);
    ui->tableView_orders->setColumnHidden(1, true);
    ui->tableView_orders->setColumnHidden(3, true);

    ui->tableView_orders->resizeColumnsToContents();
    ui->tableView_orders->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
        QStringList head;
        head<<""<<""<<"用户"<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<"座位1"<<"座位2"<<"座位3"<<"是否支付"<<"价格";
        QSqlTableModel * model = sf.queryAdminOrder(movieName, userName, startDate, endDate, choice);
        for(int i = 0; i < 16; i++)
            model->setHeaderData(i, Qt::Horizontal, head[i]);
        updateOrdersTable(model);
    }
    else
        QMessageBox::critical(nullptr, "输入有误", "请重新输入");
}

void AdminMainWindow::receiveHallAdded()
{
    SqlFuns sf;
    QSqlTableModel * model1 = sf.queryAdminHall("");
    QStringList head1;
    head1<<""<<"影厅名"<<"电影名"<<"总作为"<<""<<"行数"<<"列数"<<"种类";
    for(int i = 0; i < 8; i++)
        model1->setHeaderData(i, Qt::Horizontal, head1[i]);

    updateHallTable(model1);
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

void AdminMainWindow::on_pushButton_viewDetail_clicked()
{
    SqlFuns sf;
    int row = ui->tableView_movie->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_movie->model();
    QString movieId = model->data(model->index(row, 1)).toString();
    emit showMovieDetail(movieId);
}

void AdminMainWindow::checkIsPlayed()
{
    SqlFuns sf;
    sf.checkIsPlayed();
}
