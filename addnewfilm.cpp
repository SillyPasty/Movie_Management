#include "addnewfilm.h"
#include "ui_addnewfilm.h"

AddNewFilm::AddNewFilm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewFilm)
{
    ui->setupUi(this);
    // 设定日期选择最小值
    QTime curTime = QTime::currentTime();
    ui->timeEdit_startTime->setMinimumTime(curTime);
    ui->timeEdit_endTime->setMinimumTime(curTime);
    QDate curDate = QDate::currentDate();
    ui->dateEdit_date->setMinimumDate(curDate);
}

AddNewFilm::~AddNewFilm()
{
    delete ui;
}

void AddNewFilm::on_pushButton_confirm_clicked()
{
    SqlFuns sf;
    // QDateTime dt;
    QString name = ui->lineEdit_name->text().trimmed();
    // 将时间转为字符串
    QString date = ui->dateEdit_date->date().toString("yyyy-MM-dd");
    QString startTime =  ui->timeEdit_startTime->time().toString("hh:mm:ss");
    QString endTime = ui->timeEdit_endTime->time().toString("hh:mm:ss");
    QString type = ui->lineEdit_type->text().trimmed();
    QString hall = ui->comboBox_hall->currentText();
    if(startTime < endTime)
    {
        float price = ui->lineEdit_price->text().trimmed().toFloat();
        int isRecommened = 0;
        if(ui->checkBox_isRecommened->isChecked())
            isRecommened = 1;
        int length =  ui->timeEdit_startTime->time().secsTo(ui->timeEdit_endTime->time());

        QString cinema = sf.queryCinema(global_userName);   //  数据库
        QString movieId = name + cinema + ui->timeEdit_startTime->time().toString("hhmmss") + ui->dateEdit_date->date().toString("yyyyMMdd");  //  自定义
        int ticketRemain = sf.queryHallSeates(hall); //  通过数据库查询
        QString seatMaps = sf.queryHallSeatMap(hall); //  数据库
        sf.addNewFilm(movieId, name, cinema, hall, startTime, endTime, length, price, ticketRemain, type, isRecommened, date, seatMaps);
        this->close();
    }
    else
        QMessageBox::critical(nullptr, "输入有误", "请重新输入");
}

void AddNewFilm::receiveAddNewFilm()
{
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
    SqlFuns sf;
    QString cinema = sf.queryCinema(global_userName);
    ui->lineEdit_type->setText(sf.queryType(arg1, cinema));
}
