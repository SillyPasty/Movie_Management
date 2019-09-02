#include "sqlfuns.h"

SqlFuns::SqlFuns()
{
}

QString global_userName="";

void SqlFuns::createTables()
{
    //  创建表
    QSqlQuery query;
    query.exec("CREATE TABLE user ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "userId TEXT,"
               "password TEXT,"
               "name TEXT,"
               "sex TEXT,"
               "phoneNumber TEXT,"
               "email TEXT,"
               "balance REAL,"
               "isAdmin INTEGER,"
               "cinema TEXT)");

    query.exec("CREATE TABLE movie ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "movieId TEXT,"
               "movieName TEXT,"
               "cinema TEXT,"
               "hall TEXT,"
               "startTime TEXT,"
               "endTime TEXT,"
               "length INTEGER,"
               "isPlayed INTEGER,"
               "price REAL,"
               "ticketRemain INTEGER,"
               "type TEXT,"
               "isRecommened INTEGER,"
               "totalSeats INTEGER,"
               "percent REAL,"
               "totalIncome REAL,"
               "date TEXT,"
               "rowNum INT,"
               "coloumNum INT,"
               "seatMaps TEXT)");

    query.exec("CREATE TABLE hall ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "hallId TEXT,"
               "cinema TEXT,"
               "totalSeats INTEGER,"
               "seatMap TEXT,"
               "row INTEGER,"
               "column INTEGER,"
               "type TEXT)");

    query.exec("CREATE TABLE orders ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "userId TEXT,"
               "movieId TEXT,"
               "hallId TEXT,"
               "seat1pos INTEGER,"
               "seat2pos INTEGER,"
               "seat3pos INTEGER,"
               "isPaid INTEGER)");
}

bool SqlFuns::connect(const QString &dbName)
{
    //  连接并打开数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if (!db.open())
    {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"), db.lastError().text());
        return false;
    }
    return true;
}

QString SqlFuns::formal(QString str)
{
    QString sym = "'";
    return (sym + str + sym);
}

void SqlFuns::registerUser(QString userId, QString password, QString name, QString sex, QString phonenumber, QString email, int isAdmin, QString cinema)
{
    QSqlQuery query;
    QString or1 = "INSERT INTO user VALUES (NULL,";
    userId = formal(userId) + ",";
    password = formal(password) + ",";
    name = formal(name) + ",";
    sex = formal(sex) + ",";
    phonenumber = formal(phonenumber) + ",";
    email = formal(email) + ",";
    cinema = formal(cinema) + ")";
    QString isAd;
    isAd.sprintf("%d,", isAdmin);
    if (isAdmin)
        or1 = or1 + userId + password + name + sex + phonenumber + email + "NULL," + isAd + cinema;
    else
        or1 = or1 + userId + password + name + sex + phonenumber + email + "0," + isAd + "NULL)";
    query.exec(or1);
}

QString SqlFuns::queryPassword(QString userName)
{
    QSqlQuery query;
    QString ord = "SELECT password FROM user WHERE userId = ";
    userName = formal(userName);
    ord = ord + userName;
    query.exec(ord);
    if (query.next())
    {
        QString psd = query.value(0).toString();
        return psd;
    }
    else
        return "";
}

int SqlFuns::queryIsadmin(QString userName)
{
    QSqlQuery query;
    QString ord = "SELECT isAdmin FROM user WHERE userId = ";
    userName = formal(userName);
    ord = ord + userName;
    query.exec(ord);
    query.next();
    int flag = query.value(0).toInt();
    return flag;
}

void SqlFuns::addNewFilm(QString movieId, QString name, QString cinema, QString hall, QString startTime, QString endTime, int length, float price, int ticketRemain, QString type, int isRecommened, QString date, QString seatMaps)
{
    QSqlTableModel model;
    model.setTable("movie");
    model.select();
    //  查询row 和 col

    int row = model.rowCount();
    model.insertRows(row, 1);
    model.setData(model.index(row, 1), movieId);
    model.setData(model.index(row, 2), name);
    model.setData(model.index(row, 3), cinema);
    model.setData(model.index(row, 4), hall);
    model.setData(model.index(row, 5), startTime);
    model.setData(model.index(row, 6), endTime);
    model.setData(model.index(row, 7), length);
    model.setData(model.index(row, 8), 0);
    model.setData(model.index(row, 9), price);
    model.setData(model.index(row, 10), ticketRemain);
    model.setData(model.index(row, 11), type);
    model.setData(model.index(row, 12), isRecommened);
    model.setData(model.index(row, 13), ticketRemain);
    model.setData(model.index(row, 14), 0);
    model.setData(model.index(row, 15), 0);
    model.setData(model.index(row, 16), date);
    // 行数和列数
    model.setData(model.index(row, 17), queryRow(hall, cinema));
    model.setData(model.index(row, 18), queryColumn(hall, cinema));
    model.setData(model.index(row, 19), seatMaps);

    model.submitAll();
}

int SqlFuns::queryHallSeates(QString hallId)
{
    QSqlTableModel model;
    model.setTable("hall");
    hallId = formal(hallId);
    model.setFilter("hallId = " + hallId);
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("totalSeats").toInt();
}

void SqlFuns::addNewHall(QString hallId, QString cinema, int totalseats, int row, int column, QString seatMap, QString type)
{
    QSqlTableModel model;
    model.setTable("hall");
    model.select();
    //  查询row 和 col
    int rows = model.rowCount();
    model.insertRows(rows, 1);
    model.setData(model.index(rows, 1), hallId);
    model.setData(model.index(rows, 2), cinema);
    model.setData(model.index(rows, 3), totalseats);
    model.setData(model.index(rows, 4), seatMap);
    model.setData(model.index(rows, 5), row);
    model.setData(model.index(rows, 6), column);
    model.setData(model.index(rows, 7), type);
    model.submitAll();
}

QString SqlFuns::queryCinema(QString userId)
{
    QSqlTableModel model;
    model.setTable("user");
    userId = formal(userId);
    model.setFilter("userId = " + userId);
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("cinema").toString();
}

 QStringList SqlFuns::queryHallId(QString cinema)
 {
     QSqlTableModel model;
     QStringList qsl;
     model.setTable("hall");
     cinema = formal(cinema);
     model.setFilter("cinema = " + cinema);
     model.select();
     for(int i = 0; i < model.rowCount(); i++)
        qsl.append(model.record(i).value("hallId").toString());
     return qsl;
 }

QString SqlFuns::queryHallSeatMap(QString hallId)
{
    QSqlTableModel model;
    model.setTable("hall");
    hallId = formal(hallId);
    model.setFilter("hallId = " + hallId);
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("seatMap").toString();
}

int SqlFuns::queryRow(QString hallId, QString cinema)
{
    QSqlTableModel model;
    model.setTable("hall");
    hallId = formal(hallId);
    cinema = formal(cinema);
    model.setFilter("hallId = " + hallId + " and cinema = " + cinema);
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("row").toInt();
}

int SqlFuns::queryColumn(QString hallId, QString cinema)
{
    QSqlTableModel model;
    model.setTable("hall");
    hallId = formal(hallId);
    cinema = formal(cinema);
    model.setFilter("hallId = " + hallId + " and cinema = " + cinema);
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("column").toInt();
}

QString SqlFuns::queryType(QString hallId, QString cinema)
{
    QSqlTableModel model;
    model.setTable("hall");
    hallId = formal(hallId);
    cinema = formal(cinema);
    model.setFilter("hallId = " + hallId + " and cinema = " + cinema);
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("type").toString();
}

QStringList SqlFuns::queryEmailPhonePsd(QString userId)
{
    QSqlTableModel model;
    QStringList qsl;
    model.setTable("user");
    userId = formal(userId);
    model.setFilter("userId = " + userId);
    model.select();
    QSqlRecord record = model.record(0);
    qsl.append(record.value("email").toString());
    qsl.append(record.value("phoneNumber").toString());
    qsl.append(record.value("password").toString());
    return qsl;
}

void SqlFuns::changeUserInfo(QString email, QString passwd, QString phoneNum)
{
    QSqlTableModel model;
    model.setTable("user");
    QString userId = formal(global_userName);
    model.setFilter("userId = " + userId);
    model.select();
    model.setData(model.index(0, 2), passwd);
    model.setData(model.index(0, 6), email);
    model.setData(model.index(0, 5), phoneNum);
    model.submitAll();
}

QSqlTableModel* SqlFuns::queryAdminMovie(QString movieName, QString hallId)
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("movie");
    model->setSort(12, Qt::DescendingOrder);
    QString ord;
    QString cinema = queryCinema(global_userName);
    cinema = formal(cinema);
    ord = "cinema = " + cinema;
    if(movieName != "")
    {
        movieName = formal(movieName);
        ord = ord + "and movieName = " + movieName;
    }
    if(hallId != "")
    {
        hallId = formal(hallId);
        ord = ord + "and hall = " + hallId;
    }
    model->setFilter(ord);
    model->select();
    return model;
}

QSqlTableModel* SqlFuns::queryAdminHall(QString hallId)
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("hall");
    QString ord;
    QString cinema = queryCinema(global_userName);
    cinema = formal(cinema);
    ord = "cinema = " + cinema;
    if(hallId != "")
    {
        hallId = formal(hallId);
        ord = ord + "and hallId = " + hallId;
    }
    model->setFilter(ord);
    model->select();
    return model;
}

int SqlFuns::add_new_film_judge(QString hallId, QString start_time, QString end_time, Qstring film_date)
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("movie");
    int start_time_to_int = return_minute(start_time, film_date);
    int end_time_to_int = return_minute(end_time, film_date);
    int entry_begin_time = start_time_to_int - 10;
    int exit_end_time = end_time_to_int + 10;
    QString cinema = queryCinema(global_userName);
    cinema = formal(cinema);
    QString ord;
    ord = "cinema = " + cinema;
    if(hallId != "")
    {
        hallId = formal(hallId);
        ord = ord + "and hall = " + hallId;
    }
    model->setFilter(ord);
    model->select();     
    int item_num = model.rowCount();
    for(int i = 0; i < item_num; i++)
    {
        QSqlRecord record = model.record(i);
        int exist_film_entry_begin = SqlFuns::return_minute(record.value("starttime").toString(), record.value("date").toString()) - 10;
        int exist_film_exit_end = SqlFuns::return_minute(record.value("endtime").toString(), record.value("date").toString()) + 10;
        if(entry_begin_time > exist_film_entry_begin && entry_begin_time < exist_film_exit_end)
            return 1;    
        if(entry_begin_time < exist_film_entry_begin && exit_end_time > exist_film_entry_begin)
            return 1;    
    }
    ord = "cinema = " + cinema;
    if(hallId != "")
    {
        hallId = formal(hallId);
        ord = ord + "and hall != " + hallId;
    }
    model->setFilter(ord);
    model->select();     
    int item_num = model.rowCount();    
    for(int i = 0; i < item_num; i++)
    {
        QSqlRecord record = model.record(i);
        int exist_film_start_time = SqlFuns::return_minute(record.value("starttime").toString(), record.value("date").toString());
        int exist_film_end_time = SqlFuns::return_minute(record.value("endtime").toString(), record.value("date").toString());
        if(abs(exist_film_start_time - start_time_to_int) < 10)
            return 2;
        if(abs(exist_film_end_time - end_time_to_int) < 10)
            return 2;
        if(abs(exist_film_end_time - start_time_to_int) < 20)
            return 2;
        if(abs(end_time_to_int - exist_film_start_time) < 20)                
            return 2;
    }    
    return 0;
}


int SqlFuns::return_minute(QString time_to _convert, QString date_to_convert)
{
    int return_time_interval_by_min = 0;
    int day_interval = 0;
    QString convert_year = date_to_convert.section('-', 0, 0);
    int year_to_int = convert_year.toint();
    Qstring convert_month = date_to_convert.section('-', 1, 1);
    int month_to_int = convert_month.toint();
    Qstring convert_day = date_to_convert.section('-', 2, 2);
    Qstring convert_hour = time_to_convert.section(':', 3, 3);
    Qstring convert_minute = time_to_convert.section(':', 4, 4);
    for(int i = 1970; i < year_to_int; i++)
    {
        if((i % 4 == 0 && i % 100 != 0)||(i % 400 == 0))
            day_interval = day_interval + 366;
        else day_interval = day_interval + 365;    
    }
    for(int i = 1; i < month_to_int.toint(); i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10) // i < 12
            day_interval = day_interval + 31;
        else
            if(i == 4 || i == 6 || i == 9 || i == 11) // i < 12
                day_interval = day_interval + 30;
        else
        {
            if((year_to_int % 4 == 0 && year_to_int % 100 != 0)||(year_to_int % 400 == 0))
                day_interval = day_interval + 29;
            else day_interval = day_interval +28;
        }
    }
    day_interval = day_interval + (convert_day.toint() - 1);
    return_time_interval_by_min = return_time_interval_by_min + (day_interval * 60 * 24);
    return_time_interval_by_min = return_time_interval_by_min + (convert_hour.toint() * 60) + convert_minute.toint();
    return return_time_interval_by_min;
}