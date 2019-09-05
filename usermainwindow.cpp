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
    this->setMaximumSize(1058, 705);
    this->setMinimumSize(1058, 705);
    QTimer *timer = new QTimer(this);
    QTimer *minute = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    connect(minute, SIGNAL(timeout()), this, SLOT(orderCheck()));
    timer->start(1000);
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
    SqlFuns sf;
    QString tem;
    ui->label_userInfo->setText(global_userName);
    QStringList infoList = sf.queryEmailPhonePsd(global_userName);

    ui->label_email->setText(infoList[0]);
    ui->label_phone->setText(infoList[1]);
    ui->label_password->setText(infoList[2]);

    ui->comboBox_type->addItems(sf.queryType());
    ui->comboBox_cinema->addItems(sf.queryCinema());

    ui->lineEdit_currentBalance->setText(tem.sprintf("%.2f", sf.queryBalance()));
    QStringList head;
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<""<<""<<"价格"<<"余票"<<"类型"<<""<<""<<""<<""<<"日期"<<""<<""<<""<<"语言"<<"是否打折";
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
    head1<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    for(int i = 0; i < 16; i++)
        model1->setHeaderData(i, Qt::Horizontal, head1[i]);
    updateOrdersTable(model1);

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

void UserMainWindow::on_pushButton_confirmTopUp_clicked()
{
    SqlFuns sf;
    QString tmp, addB = ui->lineEdit_topUp->text().trimmed();
    float amount = addB.toFloat();
    ui->lineEdit_currentBalance->setText(tmp.sprintf("%.2f",sf.changeUserBalance(amount)));
    ui->lineEdit_topUp->clear();
}

void UserMainWindow::updateMovieTable(QSqlTableModel *model)
{
    QStringList head;
    ui->tableView_movie->setModel(model);
    ui->tableView_movie->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_movie->setSelectionBehavior(QAbstractItemView::SelectRows);
    //  设置部分显示
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
    head<<""<<""<<"电影名"<<"影院"<<"影厅"<<"开始时间"<<"结束时间"<<""<<""<<"价格"<<"余票"<<"类型"<<""<<""<<""<<""<<"日期"<<""<<""<<""<<"语言"<<"是否打折";
    QSqlTableModel * model = sf.queryUserMovie(movieName, cinemaName, type, language);
    for(int i = 0; i < 22; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);
//    ui->tableView_movie->setHorizontalHeader();
    updateMovieTable(model);
}

void UserMainWindow::on_pushButton_buy_clicked()
{
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

//    int row = ui->tableView_movie->currentIndex().row();
//    QString orderId = model->data(model->index(row, 1)).toString();
    //  设置部分显示
    ui->tableView_orders->setColumnHidden(0, true);
    ui->tableView_orders->setColumnHidden(1, true);
    ui->tableView_orders->setColumnHidden(2, true);
    ui->tableView_orders->setColumnHidden(3, true);
    ui->tableView_orders->setColumnHidden(11, true);
    ui->tableView_orders->setColumnHidden(12, true);
    ui->tableView_orders->setColumnHidden(13, true);

    ui->tableView_movie->resizeColumnsToContents();
    ui->tableView_movie->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void UserMainWindow::on_pushButton_search_2_clicked()
{
    SqlFuns sf;
    QString cinema = ui->lineEdit_cinemaName_2->text().trimmed();
    QString movieName = ui->lineEdit_movieName_2->text().trimmed();
    QStringList head;
    head<<""<<""<<""<<""<<"电影名"<<"电影院"<<"开始时间"<<"结束时间"<<"日期"<<"影厅"<<"座位信息"<<""<<""<<""<<"是否支付"<<"价格";
    QSqlTableModel * model = sf.queryUserOrder(movieName, cinema);
    for(int i = 0; i < 16; i++)
        model->setHeaderData(i, Qt::Horizontal, head[i]);
    updateOrdersTable(model);
}

void UserMainWindow::on_pushButton_pay_clicked()
{
    SqlFuns sf;
    int row = ui->tableView_orders->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_orders->model();
    QString orderId = model->data(model->index(row, 1)).toString();
    QString movieId = model->data(model->index(row, 3)).toString();
    QString tmp;
    int tickets = 0;
    for(int i = 11; i < 14; i++)
        if(model->data(model->index(row, i)).toInt())
            tickets++;
    float bal = sf.queryBalance();
    float total = sf.queryPrice(movieId) * tickets;
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
        ui->lineEdit_currentBalance->setText(tmp.sprintf("%.2f",sf.changeUserBalance(-1 * total)));
    }
}

void UserMainWindow::on_pushButton_cancelOrder_clicked()
{
    SqlFuns sf;
    int row = ui->tableView_orders->currentIndex().row();
    QAbstractItemModel *model = ui->tableView_orders->model();
    QString orderId = model->data(model->index(row, 1)).toString();
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
