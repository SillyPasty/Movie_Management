/*
 * 本函数主要实现了管理员窗口的主要功能：
 * 添加新影厅、查看现有订单、添加新场次、查看电影
 * 利用mvc（movel-view controller）模型，对数据库中的信息进行了可视化显示
 * 方便用户操作的同时提高了鲁棒性，限制了选择，并对异常输入进行了判断
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
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
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
    // 每秒更新时间
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);
    // 每分钟更新电影是否播放情况
    QTimer *timer1 = new QTimer(this);
    connect(timer1, SIGNAL(timeout()), this, SLOT(checkIsPlayed()));
    timer1->start(60000);
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
    // 输入一个模型指针，利用mvc对模型进行可视化展示
    // 对电影展示view元素进行初始化
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
    // 输入一个模型指针，利用mvc对模型进行可视化展示
    // 对影厅展示view元素进行初始化
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
    // 槽函数，响应登陆信号
    // 初始化各个表格的表头、个人信息等
    SqlFuns sf;
    // 初始化信息
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);

    QSqlTableModel * model = sf.queryAdminMovie("", "");
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<"长度(分钟)"<<"是否放映"
       <<"价格"<<"余票"<<"类型"<<"是否推荐"<<"总座位"<<"售率占比"<<"总收入"<<"日期"<<"行数"<<"列数"<<""<<"语言"<<"是否打折";
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);

    updateMovieTable(model);
    // 初始化hall表格信息
    QSqlTableModel * model1 = sf.queryAdminHall("");
    QStringList head1;
    head1<<""<<"影厅名"<<"电影名"<<"总座位"<<""<<"行数"<<"列数"<<"种类";
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
    // 初始化订单表格信息
    head2<<""<<""<<"用户"<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"
        <<"座位信息"<<"座位1"<<"座位2"<<"座位3"<<"是否支付"<<"价格";
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

void AdminMainWindow::on_pushButton_editPersonalInfo_clicked() // 信息更改 释放信号
{
    emit showInfoChangeWindow();
}

void AdminMainWindow::on_pushButton_addNewMovie_clicked()  // 释放信号
{
    emit showAddNewFilmWindow();
}

void AdminMainWindow::on_pushButton_addNewHall_clicked()  //释放信号
{
    emit showAddNewHallWindow();
}

void AdminMainWindow::receiveMovieInfoChange()
{
    // 当电影信息数据库被修改时，更新页面
    SqlFuns sf;
    QSqlTableModel * model = sf.queryAdminMovie("", "");
    QStringList head;
    //  初始化电影展示表格
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<"长度(分钟)"<<"是否放映"
       <<"价格"<<"余票"<<"类型"<<"是否推荐"<<"总座位"<<"售率占比"<<"总收入"<<"日期"<<"行数"
      <<"列数"<<""<<"语言"<<"是否打折";
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);

    updateMovieTable(model);
}


void AdminMainWindow::infoChangeDone() // 槽函数
{
    // 当个人信息被修改后，更新信息
    SqlFuns sf;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]); 
}

void AdminMainWindow::on_pushButton_search_2_clicked()
{
    // 搜索符合条件对应电影场次
    SqlFuns sf;
    QString movieName = ui->lineEdit_movieName_2->text().trimmed();
    QString hallId = ui->comboBox_hall_2->currentText();
    QSqlTableModel * model = sf.queryAdminMovie(movieName, hallId);
    QStringList head;
    // 设置场次查看表格的表头
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<"长度(分钟)"<<"是否放映"
       <<"价格"<<"余票"<<"类型"<<"是否推荐"<<"总座位"<<"售率占比"<<"总收入"<<"日期"<<"行数"
      <<"列数"<<""<<"语言"<<"是否打折";
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);

    updateMovieTable(model);
}


void AdminMainWindow::on_comboBox_hall_currentTextChanged(const QString &arg1)
{
    // 查看不同影厅的信息
    SqlFuns sf;
    QString hallId = ui->comboBox_hall->currentText();
    QSqlTableModel * model1 = sf.queryAdminHall(hallId);
    QStringList head1;
    head1<<""<<"影厅名"<<"电影名"<<"总座位"<<""<<"行数"<<"列数"<<"种类";
    for(int i = 0; i < 8; i++)
        model1->setHeaderData(i, Qt::Horizontal, head1[i]);

    updateHallTable(model1);
}

void AdminMainWindow::updateOrdersTable(QSqlTableModel *model)
{
    // 传入一个订单模型指针，更新订单界面
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
    // 根据条件搜索电影
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
    // 在添加新影厅之后 刷新影厅展示界面
    SqlFuns sf;
    QSqlTableModel * model1 = sf.queryAdminHall("");
    QStringList head1;
    head1<<""<<"影厅名"<<"电影名"<<"总座位"<<""<<"行数"<<"列数"<<"种类";
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
    // 输入一个座位图字符串，在tablewidget中展示座位
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

void AdminMainWindow::on_tableView_currentHall_clicked(const QModelIndex &index) // 显示现有影厅座位图
{
    QAbstractItemModel *model = ui->tableView_currentHall->model();
    showSeat(model->data(model->index(index.row(), 4)).toString());
}

void AdminMainWindow::on_pushButton_viewDetail_clicked()  // 查看订单细节，释放信号
{
    SqlFuns sf;
    int row = ui->tableView_movie->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_movie->model();
    QString movieId = model->data(model->index(row, 1)).toString();
    emit showMovieDetail(movieId);
}

void AdminMainWindow::checkIsPlayed() // 计时器 检查是否被播放
{
    SqlFuns sf;
    sf.checkIsPlayed();
}
