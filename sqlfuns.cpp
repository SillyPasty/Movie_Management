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
               "seatMaps TEXT,"
               "language TEXT)");

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

void SqlFuns::addNewFilm(QString movieId, QString name, QString cinema, QString hall, QString startTime, QString endTime, int length, float price, int ticketRemain, QString type, int isRecommened, QString date, QString seatMaps, QString language)
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
    model.setData(model.index(row, 20), language);
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

QSqlTableModel* SqlFuns::queryUserMovie(QString movieName, QString cinema, QString type, QString language)
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("movie");
    model->setSort(12, Qt::DescendingOrder);
    QString ord = "isPlayed = 0";

    if(cinema != "")
    {
        cinema = formal(cinema);
        ord = ord + " and cinema = " + cinema;
    }

    if(type != "")
    {
        type = formal(type);
        ord = ord + " and type = " + type;
    }

    if(language != "")
    {
        language = formal(language);
        ord = ord + " and language = " + language;
    }

    if(movieName != "")
    {
        movieName = formal(movieName);
        ord = ord + " and movieName = " + movieName;
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

float SqlFuns::queryBalance()
{
    QSqlTableModel model;
    model.setTable("user");
    QString userId = formal(global_userName);
    model.setFilter("userId = " + userId);
    model.select();
    return model.record(0).value("balance").toFloat();
}

float SqlFuns::changeUserBalance(float amount)
{
    QSqlTableModel model;
    model.setTable("user");
    QString userId = formal(global_userName);
    model.setFilter("userId = " + userId);
    model.select();
    float cur = model.record(0).value("balance").toFloat();
    cur += amount;
    model.setData(model.index(0, 7), cur);
    model.submitAll();
    return cur;
}

QStringList SqlFuns::queryType()
{
    QSqlTableModel model;
    QStringList qsl;
    qsl.append("全部");
    model.setTable("hall");
    model.select();
    for(int i = 0; i < model.rowCount(); i++)
        qsl.append(model.record(i).value("type").toString());
    qsl.removeDuplicates();
    return qsl;
}

QStringList SqlFuns::queryCinema()
{
    QSqlTableModel model;
    QStringList qsl;
    qsl.append("全部");
    model.setTable("hall");
    model.select();
    for(int i = 0; i < model.rowCount(); i++)
        qsl.append(model.record(i).value("cinema").toString());
    qsl.removeDuplicates();
    return qsl;
}
