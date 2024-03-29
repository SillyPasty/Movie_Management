/*
 * 本函数实现了新增电影功能
 * 用户可自定义电影名称等信息，同时用comboBox限定了影厅的选择，避免了错误输入
 * 并且添加了电影日期和时间的限制，无法添加过去的电影，结束时间无法早于开始时间
 * 对每场电影的添加都进行了判断，为每场次预留10分钟入场出场时间，如果有冲突，会予以提示
 * 如果影厅时段有电影播放，会取消对新电影的添加
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */
#include "addnewfilm.h"
#include "ui_addnewfilm.h"

AddNewFilm::AddNewFilm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewFilm)
{
    ui->setupUi(this);
    this->setWindowTitle("新增电影");
    this->setMaximumSize(313, 384);
    this->setMinimumSize(313, 384);
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
    // 设定日期选择最小值
    QTime curTime = QTime::currentTime();
    ui->timeEdit_startTime->setTime(curTime);
    ui->timeEdit_endTime->setTime(curTime);
    QDate curDate = QDate::currentDate();
    ui->dateEdit_date->setMinimumDate(curDate);
}

AddNewFilm::~AddNewFilm()
{
    delete ui;
}

void AddNewFilm::on_pushButton_confirm_clicked()
{
    // 当确定按钮被点击时，进行合法性判断，并向数据库中添加电影信息
    SqlFuns sf;
    // QDateTime dt;
    QString name = ui->lineEdit_name->text().trimmed();
    // 将时间转为字符串
    QString date = ui->dateEdit_date->date().toString("yyyy-MM-dd");
    QString startTime =  ui->timeEdit_startTime->time().toString("hh:mm:ss");
    QString endTime = ui->timeEdit_endTime->time().toString("hh:mm:ss");
    QString type = ui->lineEdit_type->text().trimmed();
    QString hall = ui->comboBox_hall->currentText();
    QString language = ui->comboBox_language->currentText();
    QTime curTime = QTime::currentTime();
    QDate curDate = QDate::currentDate();
    QString currentTime = curTime.toString("hh:mm:ss");
    QString currentDate = curDate.toString("yyyy-MM-dd");
    int flg;
    // 进行合法性判断，并予以提示
    if(startTime < endTime && ((currentDate < date) || (currentDate == date && currentTime < startTime)))
    {
        flg = sf.addNewFilmJudge(hall, startTime, endTime, date);
        QMessageBox::StandardButton result = QMessageBox::No; // 返回选择的按钮

        if(flg == 1)
            QMessageBox::critical(nullptr, "与现有时间冲突", "请重新输入");
        else if (flg == 2)
            result = QMessageBox::question(this, "散场人数较多", "是否要添加？", QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton);

        if(result == QMessageBox::Yes || flg == 0)
        {
            float price = ui->lineEdit_price->text().trimmed().toFloat();
            int isRecommened = 0, isDiscount = 0;
            // 判断是否推荐
            if(ui->checkBox_isRecommened->isChecked())
                isRecommened = 1;
            int length =  ui->timeEdit_startTime->time().secsTo(ui->timeEdit_endTime->time());

            QString cinema = sf.queryCinema(global_userName);   //  数据库
            QString movieId = name + cinema + hall + ui->timeEdit_startTime->time().toString("hhmmss") + ui->dateEdit_date->date().toString("yyyyMMdd");  //  自定义
            int ticketRemain = sf.queryHallSeates(hall); //  通过数据库查询
            QString seatMaps = sf.queryHallSeatMap(hall); //  数据库
            if(ui->checkBox_isDiscount->isChecked())
                isDiscount = 1;
            sf.addNewFilm(movieId, name, cinema, hall, startTime, endTime, length, price, ticketRemain, type, isRecommened, date, seatMaps, language, isDiscount);
            emit movieInfoChange();
            this->close();
        }
    }
    else
        QMessageBox::critical(nullptr, "时间输入有误", "请重新输入");
}

void AddNewFilm::receiveAddNewFilm()
{
    // 槽函数 与管理员用户进行交互
    this->show();
    SqlFuns sf;

    ui->dateEdit_date->setCalendarPopup(true);

    // 给定cinema 通过user id
    QString cinema = sf.queryCinema(global_userName);
    ui->lineEdit_cinema->setText(cinema);
    ui->lineEdit_cinema->setReadOnly(true);
    ui->lineEdit_type->setReadOnly(true);
    // 给定hall id 在combobox 通过cinema查询
    ui->comboBox_hall->clear();
    ui->comboBox_hall->addItems(sf.queryHallId(cinema));
}

void AddNewFilm::on_comboBox_hall_currentTextChanged(const QString &arg1)
{
    // 槽函数 当前影厅改变时 改变相应信息
    SqlFuns sf;
    QString cinema = sf.queryCinema(global_userName);
    //  更改电影种类
    ui->lineEdit_type->setText(sf.queryType(arg1, cinema));
}
