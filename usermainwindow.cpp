/*
 * 本函数主要实现了用户窗口的主要功能：
 * 查看现有场次 个人余额 当前订单 订单的购买
 * 利用mvc（movel-view controller）模型，对数据库中的信息进行了可视化显示
 * 方便用户操作的同时提高了鲁棒性，限制了选择，并对异常输入进行了判断
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */

#include "usermainwindow.h"
#include "ui_usermainwindow.h"
#include <QTimer>
#include <QDateTime>

UserMainWindow::UserMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("用户窗口");
    this->setMaximumSize(873, 595);
    this->setMinimumSize(873, 595);
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
    QTimer *timer = new QTimer(this);
    QTimer *minute = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    connect(minute, SIGNAL(timeout()), this, SLOT(orderCheck()));
    timer->start(1000);
    // 每30分钟检查一次订单是否过期
    minute->start(1800000);

    ui->lineEdit_currentBalance->setReadOnly(true);
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
    // 槽函数 接受登陆信息以后，初始化信息
    SqlFuns sf;
    QString tem;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);

    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);

    ui->comboBox_type->addItems(sf.queryType());
    ui->comboBox_cinema->addItems(sf.queryCinema());
    // 对场次展示进行初始化
    ui->lineEdit_currentBalance->setText(tem.sprintf("%.2f", sf.queryBalance()));
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<""<<""<<"价格"<<"余票"
       <<"类型"<<""<<""<<""<<""<<"日期"<<""<<""<<""<<"语言"<<"是否打折";
    QSqlTableModel * model = sf.queryUserMovie("", "", "", "");
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);
    updateMovieTable(model);
    ui->tableView_movie->setSortingEnabled(true);
    ui->tableView_orders->setSortingEnabled(true);
    ui->tableView_movie->setAlternatingRowColors(true);
    ui->tableView_orders->setAlternatingRowColors(true);
    QSqlTableModel * model1 = sf.queryUserOrder("", "");
    QStringList head1;
    // 对当前订单进行初始化
    head1<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"
        <<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    for(int i = 0; i < 16; i++)
        model1->setHeaderData(i, Qt::Horizontal, head1[i]);
    updateOrdersTable(model1);

    this->show();
}

void UserMainWindow::timerUpdate()
{
    //显示当前时间
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
    // 更新信息
    SqlFuns sf;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);
    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);
}

void UserMainWindow::on_pushButton_confirmTopUp_clicked()
{
    // 确认充值 并修改用户余额
    SqlFuns sf;
    QString tmp, addB = ui->lineEdit_topUp->text().trimmed();
    float amount = addB.toFloat();
    ui->lineEdit_currentBalance->setText(tmp.sprintf("%.2f",sf.changeUserBalance(amount)));
    ui->lineEdit_topUp->clear();
}

void UserMainWindow::updateMovieTable(QSqlTableModel *model)
{
    // 更新电影表格
    QStringList head;
    ui->tableView_movie->setModel(model);
    ui->tableView_movie->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_movie->setSelectionBehavior(QAbstractItemView::SelectRows);
    //  设置部分显示，隐藏非必要项
    ui->tableView_movie->setColumnHidden(0, true);
    ui->tableView_movie->setColumnHidden(1, true);
    ui->tableView_movie->setColumnHidden(7, true);
    ui->tableView_movie->setColumnHidden(8, true);
    ui->tableView_movie->setColumnHidden(12, true);
    ui->tableView_movie->setColumnHidden(13, true);
    ui->tableView_movie->setColumnHidden(14, true);
    ui->tableView_movie->setColumnHidden(15, true);
    ui->tableView_movie->setColumnHidden(17, true);
    ui->tableView_movie->setColumnHidden(18, true);
    ui->tableView_movie->setColumnHidden(19, true);

    ui->tableView_movie->resizeColumnsToContents();
    ui->tableView_movie->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void UserMainWindow::on_pushButton_search_clicked()
{
    // 搜索符合条件的电影名称
    SqlFuns sf;
    QString movieName = ui->lineEdit_movieName->text().trimmed();
    QString cinemaName = ui->comboBox_cinema->currentText();
    QString language = ui->comboBox_language->currentText();
    QString type = ui->comboBox_type->currentText();
    if(cinemaName == "全部")
        cinemaName = "";
    if(language == "全部")
        language = "";
    if(type == "全部")
        type = "";
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<""<<""<<"价格"<<"余票"
       <<"类型"<<""<<""<<""<<""<<"日期"<<""<<""<<""<<"语言"<<"是否打折";
    QSqlTableModel * model = sf.queryUserMovie(movieName, cinemaName, type, language);
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);
    updateMovieTable(model);                          // 更新电影表格
}

void UserMainWindow::on_pushButton_buy_clicked()
{
    // 购买界面 触发购买界面信号
    SqlFuns sf;
    int row = ui->tableView_movie->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_movie->model();
    QString movieId = model->data(model->index(row, 1)).toString();

    emit showPaymentWindow(movieId);
}

void UserMainWindow::updateOrdersTable(QSqlTableModel *model)
{

    ui->tableView_orders->setModel(model);
    ui->tableView_orders->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_orders->setSelectionBehavior(QAbstractItemView::SelectRows);
    //  设置部分显示，隐藏非必要信息
    ui->tableView_orders->setColumnHidden(0, true);
    ui->tableView_orders->setColumnHidden(1, true);
    ui->tableView_orders->setColumnHidden(2, true);
    ui->tableView_orders->setColumnHidden(3, true);
    ui->tableView_orders->setColumnHidden(11, true);
    ui->tableView_orders->setColumnHidden(12, true);
    ui->tableView_orders->setColumnHidden(13, true);

    ui->tableView_orders->resizeColumnsToContents();
    ui->tableView_orders->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void UserMainWindow::on_pushButton_search_2_clicked()
{
    // 根据条件搜索订单信息
    SqlFuns sf;
    // 读取输入信息
    QString cinema = ui->lineEdit_cinemaName_2->text().trimmed();
    QString movieName = ui->lineEdit_movieName_2->text().trimmed();
    QStringList head;                                                     // 设置表头
    head<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    QSqlTableModel * model = sf.queryUserOrder(movieName, cinema);
    for(int i = 0; i < 16; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);
    updateOrdersTable(model);
}

void UserMainWindow::on_pushButton_pay_clicked()
{
    // 槽函数 确认付款
    // 通过表格被选取行读入信息
    SqlFuns sf;
    int row = ui->tableView_orders->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_orders->model();
    QString orderId = model->data(model->index(row, 1)).toString();
    QString movieId = model->data(model->index(row, 3)).toString();
    QString tmp;
    int tickets = 0;
    for(int i = 11; i < 14; i++)  // 判断座位数量
        if(model->data(model->index(row, i)).toInt())
            tickets++;
    float bal = sf.queryBalance();
    float total = sf.queryPrice(movieId) * tickets;
    // 如果余额不足
    if(bal < total)
        QMessageBox::critical(nullptr, "余额不足", "无法购买");
    else
    {
        sf.changePaymentStage(orderId, tickets, total);
        QStringList head;
        head<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
        QSqlTableModel * model = sf.queryUserOrder("", "");
        for(int i = 0; i < 16; i++)
            model->setHeaderData(i, Qt::Horizontal, head[i]);
        updateOrdersTable(model);
        ui->lineEdit_currentBalance->setText(tmp.sprintf("%.2f",sf.changeUserBalance(-1 * total))); // 更新当前余额
        QStringList head1;
        head1<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<""<<""<<"价格"<<"余票"
           <<"类型"<<""<<""<<""<<""<<"日期"<<""<<""<<""<<"语言"<<"是否打折";
        QSqlTableModel * model1 = sf.queryUserMovie("", "", "", "");
        for(int i = 0; i < 22; i++)
            model1->setHeaderData(i, Qt::Horizontal, head1[i]);
        updateMovieTable(model1);                          // 更新电影表格
    }
}

void UserMainWindow::on_pushButton_cancelOrder_clicked()
{
    //取消订单
    SqlFuns sf;
    // 读取当前行
    int row = ui->tableView_orders->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_orders->model();
    QString orderId = model->data(model->index(row, 1)).toString();
    // 判断是否已支付
    if(sf.cancelOrders(orderId) == -1)
        QMessageBox::critical(nullptr, "已经支付", "无法取消");
    QSqlTableModel * model1 = sf.queryUserOrder("", "");
    QStringList head;
    head<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    for(int i = 0; i < 16; i++)
        model1->setHeaderData(i, Qt::Horizontal, head[i]);
    updateOrdersTable(model1);
}

void UserMainWindow::receiveBalanceChange()
{
    // 槽函数 余额改变
    SqlFuns sf;
    QString tmp;
    QSqlTableModel * model1 = sf.queryUserOrder("", "");
    QStringList head;
    head<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    for(int i = 0; i < 16; i++)
        model1->setHeaderData(i, Qt::Horizontal, head[i]);
    updateOrdersTable(model1);
    ui->lineEdit_currentBalance->setText(tmp.sprintf("%.2f",sf.queryBalance()));
}

void UserMainWindow::orderCheck()
{
    // 订单检查 检查订单是否过期 如果过期 删除
    SqlFuns sf;
    QDate curDate = QDate::currentDate();
    QTime curTime = QTime::currentTime();
    QString date = curDate.toString("yyyy-MM-dd");
    QString now_time = curTime.toString("hh:mm:ss");
    sf.delete_outdated_orders(now_time, date);
    QSqlTableModel * model = sf.queryUserOrder("", "");
    QStringList head;
    head<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    for(int i = 0; i < 16; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);
    updateOrdersTable(model);
}
