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
               "percent TEXT,"
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
               "orderId TEXT,"
               "userId TEXT,"
               "movieId TEXT,"
               "movieName TEXT,"
               "cinema TEXT,"
               "startTime TEXT,"
               "endTime TEXT,"
               "date TEXT,"
               "hallId TEXT,"
               "seat1pos INTEGER,"
               "seat2pos INTEGER,"
               "seat3pos INTEGER,"
               "isPaid INTEGER)");

    query.exec("CREATE TABLE hallTemplate ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "type TEXT,"
               "row INTEGER,"
               "column INTEGER,"
               "seatMap TEXT,"
               "totalSeats INTEGER)");
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

void SqlFuns::addNewHallTemplate()
{
    QSqlTableModel model;

    QString type = "VIP厅";
    int rows = 6;
    int column = 9;                        //
    QString seatMap = "222222222222222222222"
                      "222222222222222222222"
                      "222222222222222222222"
                      "222222000000000222222"
                      "222222002200000222222"
                      "222222222200000222222"
                      "222222222222222222222"
                      "222222000000000222222"
                      "222222000000000222222"
                      "222222222222222222222"
                      "222222222222222222222"
                      "222222222222222222222";
    int totalSeats = 0;
    model.setTable("hallTemplate");
    model.select();
    //  查询row
    int row = model.rowCount();
    for(int i = 0; i < 252; i++)
        if(seatMap[i] == "0")
            totalSeats++;
    model.insertRows(row, 1);
    model.setData(model.index(row, 1), type);
    model.setData(model.index(row, 2), rows);
    model.setData(model.index(row, 3), column);
    model.setData(model.index(row, 4), seatMap);
    model.setData(model.index(row, 5), totalSeats);
    model.submitAll();
}

QString SqlFuns::formal(QString str)
{
    // 将字符串格式化为数据库中TEXT形式
    QString sym = "'";
    return (sym + str + sym);
}

void SqlFuns::registerUser(QString userId, QString password, QString name, QString sex, QString phonenumber, QString email, int isAdmin, QString cinema)
{
    // 注册用户
    QSqlQuery query;
    QString or1 = "INSERT INTO user VALUES (NULL,";
    userId = formal(userId) + ",";
    password = formal(password) + ",";
    name = formal(name) + ",";
    sex = formal(sex) + ",";
    phonenumber = formal(phonenumber) + ",";
    email = formal(email) + ",";
    cinema = formal(cinema) + ")";

    // 判断是否为管理员
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
    // 查询用户名对应密码是否正确 若用户不存在返回空字符串
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
    // 登陆时查询用户是否拥有管理员权限，进入不同界面
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
    // 添加一个新电影
    QSqlTableModel model;
    model.setTable("movie");
    model.select();
    //  查询row
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
    model.setData(model.index(row, 14), "0%");
    model.setData(model.index(row, 15), 0);
    model.setData(model.index(row, 16), date);
    model.setData(model.index(row, 17), queryRow(hall, cinema));
    model.setData(model.index(row, 18), queryColumn(hall, cinema));
    model.setData(model.index(row, 19), seatMaps);
    model.setData(model.index(row, 20), language);
    model.submitAll();
}

int SqlFuns::queryHallSeates(QString hallId)
{
    // 查询某个hall拥有的座位
    // 需要更改
    QSqlTableModel model;
    model.setTable("hall");
    hallId = formal(hallId);
    QString cinema = queryCinema(global_userName);
    model.setFilter("hallId = " + hallId + " and cinema = " + formal(cinema));
    model.select();
    QSqlRecord record = model.record(0);
    return record.value("totalSeats").toInt();
}

void SqlFuns::addNewHall(QString hallId, QString cinema, int totalseats, int row, int column, QString seatMap, QString type)
{
    // 添加一个新的hall
    // 需要更改
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
    // 查询管理院对应的影院
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
     // 查询电影院中所有的hall名 返回一个字符串列表
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
    // 查询某个hall中的座位图 返回一个字符串儿
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
    // 查询某个hall的结构 返回行数
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
    // 查询某个hall的结构 返回列数
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
    // 查询某个hall可放映的电影类型
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
    //  查询user对应的个人信息 返回一个字符串列表
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
    // 更改个人信息
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
    // 管理员操作
    // 返回一个表模型指针
    // 若输入空字符串 返回所有电影院对应电影
    // 可按条件查找
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
    // 用户操作
    // 返回一个表模型指针
    // 若输入空字符串 返回所有电影
    // 可按条件查找
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("movie");

    // 按照推荐与否进行排序
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
    // 管理员操作
    // 返回一个表模型指针
    // 若输入空字符串 返回当前影院hall
    // 可按条件查找
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
    // 用户操作
    // 查询当前用户余额并返回
    QSqlTableModel model;
    model.setTable("user");
    QString userId = formal(global_userName);
    model.setFilter("userId = " + userId);
    model.select();
    return model.record(0).value("balance").toFloat();
}

float SqlFuns::changeUserBalance(float amount)
{
    // 用户操作
    // 更改当前用户余额 可增加 可支出
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
    // 初始化操作
    // 查询电影类型 并返回于comboBox中显示
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
    // 初始化操作
    // 查询电影院 并返回于comboBox中显示
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

QStringList SqlFuns::queryOrderInfo(QString movieId)
{
    // 用户操作
    // 查询订单信息 用于订单购买
    QSqlTableModel model;
    model.setTable("movie");
    movieId = formal(movieId);
    model.setFilter("movieId = " + movieId);
    model.select();
    QStringList qsl;
    qsl.append(model.record(0).value("cinema").toString());
    qsl.append(model.record(0).value("startTime").toString());
    qsl.append(model.record(0).value("endTime").toString());
    qsl.append(model.record(0).value("date").toString());
    qsl.append(model.record(0).value("hall").toString());
    return qsl;
}

QString SqlFuns::queryMovieName(QString movieId)
{
    // 后台操作
    // 用于查询电影名

    QSqlTableModel model;
    movieId = formal(movieId);
    model.setTable("movie");
    model.setFilter("movieId = " + movieId);
    model.select();
    return model.record(0).value("movieName").toString();
}

QString SqlFuns::addNewOrder(QString movieId, int seat1pos, int seat2pos, int seat3pos, QString curTimeDate)
{
    // 用户操作
    // 添加一新订单
    // 需要修改
    QSqlTableModel model;
    model.setTable("orders");
    model.select();
    //  查询row 和 col
    int rows = model.rowCount();
    model.insertRows(rows, 1);

    QString movieName = queryMovieName(movieId);
    QStringList info = queryOrderInfo(movieId);

    QString orderId;
    orderId = info[0] + info[4] + curTimeDate;

    model.setData(model.index(rows, 1), orderId);
    model.setData(model.index(rows, 2), global_userName);
    model.setData(model.index(rows, 3), movieId);
    model.setData(model.index(rows, 4), movieName);
    model.setData(model.index(rows, 5), info[0]);
    model.setData(model.index(rows, 6), info[1]);
    model.setData(model.index(rows, 7), info[2]);
    model.setData(model.index(rows, 8), info[3]);
    model.setData(model.index(rows, 9), info[4]);
    model.setData(model.index(rows, 10), seat1pos);
    model.setData(model.index(rows, 11), seat2pos);
    model.setData(model.index(rows, 12), seat3pos);
    model.setData(model.index(rows, 13), 0);
    model.submitAll();
    return orderId;
}

QSqlTableModel* SqlFuns::queryUserOrder(QString movieName, QString cinema)
{
    // 用户操作
    // 返回一个表模型指针
    // 若输入空字符串 返回当前用户所有订单
    // 可按条件查找
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("orders");
    model->setSort(9, Qt::DescendingOrder);
    QString ord = "userId = " + formal(global_userName);

    if(cinema != "")
    {
        cinema = formal(cinema);
        ord = ord + " and cinema = " + cinema;
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

void SqlFuns::changePaymentStage(QString orderId, int num, float price)
{
    // 用户操作 付款
    // 更新多项 需更改
    QSqlTableModel model;
    model.setTable("orders");
    model.setFilter("orderId = " + formal(orderId));
    model.select();
    QString movieId = model.record(0).value("movieId").toString();
    QString percentage;
    model.setData(model.index(0, 13), 1);
    model.submitAll();
    model.setTable("movie");
    model.setFilter("movieId = " + formal(movieId));
    model.select();
    int ticket = model.record(0).value("ticketRemain").toInt();
    int totalSeat = model.record(0).value("totalSeats").toInt();
    float totalIncome = model.record(0).value("totalIncome").toFloat();
    ticket -= num;
    totalIncome += price;
    float percent = (float)(totalSeat - ticket) / totalSeat;
    percentage.sprintf("%.2f%", percent);
    model.setData(model.index(0, 10), ticket);
    model.setData(model.index(0, 15), totalIncome);
    model.setData(model.index(0, 14), percentage);
    model.submitAll();
}

float SqlFuns::queryPrice(QString movieId)
{
    // 根据电影ID查询价格
    QSqlTableModel model;
    model.setTable("movie");
    model.setFilter("movieId = " + formal(movieId));
    model.select();
    float cur = model.record(0).value("price").toFloat();;
    return cur;
}

int SqlFuns::cancelOrders(QString orderId)
{
    // 取消订单 在数据库中删除订单
    QSqlTableModel model;
    model.setTable("orders");
    orderId = formal(orderId);
    model.setFilter("orderId = " + orderId);
    model.select();
    QSqlRecord record = model.record(0);
    int is_order_paid = record.value("isPaid").toInt();
    if(is_order_paid != 0)
        return -1;
    model.removeRow(0);
    return 1;
}

QSqlTableModel* SqlFuns::queryAdminOrder(QString movieName, QString userId, QString startDate, QString endDate, int isPlayed)
{
    // 管理员操作
    // 返回一个表模型指针
    // 若输入空字符串 返回当前影院对应订单
    // 可按条件查找
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("orders");
    model->setSort(9, Qt::DescendingOrder);
    QString cinema = queryCinema(global_userName);
    QString ord = "cinema = " + formal(cinema);
    QTime curTime = QTime::currentTime();
    QDate curDate = QDate::currentDate();

    if(isPlayed == 1)
        ord = ord + " and date >= " + formal(curDate.toString("yyyy-MM-dd")) + " and startTime > " + formal(curTime.toString("hh:mm:ss"));
    if(isPlayed == 2)
        ord = ord + " and date <= " + formal(curDate.toString("yyyy-MM-dd")) + " and startTime < " + formal(curTime.toString("hh:mm:ss"));

    if(userId != "")
    {
        userId = formal(userId);
        ord = ord + " and userId = " + userId;
    }

    if(movieName != "")
    {
        movieName = formal(movieName);
        ord = ord + " and movieName = " + movieName;
    }

    if(startDate != "")
    {
        startDate = formal(startDate);
        endDate = formal(endDate);
        ord = ord + " and date > " + startDate + " and date < " + endDate;
    }
    model->setFilter(ord);
    model->select();
    return model;
}

int SqlFuns::addNewFilmJudge(QString hallId, QString start_time, QString end_time, QString film_date)
{
    // 0 合法 1 冲突 2 不建议
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("movie");
    int start_time_to_int = returnMinute(start_time, film_date);
    int end_time_to_int = returnMinute(end_time, film_date);
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
    int item_num = model->rowCount();
    for(int i = 0; i < item_num; i++)
    {
        // 同一个影厅开始结束相差10分钟
        QSqlRecord record = model->record(i);
        int exist_film_entry_begin = returnMinute(record.value("startTime").toString(), record.value("date").toString()) - 10;
        int exist_film_exit_end = returnMinute(record.value("endtime").toString(), record.value("date").toString()) + 10;
        if(entry_begin_time >= exist_film_entry_begin && entry_begin_time <= exist_film_exit_end)
            return 1;
        if(entry_begin_time <= exist_film_entry_begin && exit_end_time >= exist_film_entry_begin)
            return 1;
    }
    ord = "cinema = " + cinema;
    model->clear();
    model->setTable("movie");
    model->setFilter(ord);
    model->select();
    item_num = model->rowCount();
    for(int i = 0; i < item_num; i++)
    {
        QSqlRecord record = model->record(i);
        int exist_film_start_time = returnMinute(record.value("startTime").toString(), record.value("date").toString());
        int exist_film_end_time = returnMinute(record.value("endTime").toString(), record.value("date").toString());
        if(abs(exist_film_start_time - start_time_to_int) <= 10)
            return 2;
        if(abs(exist_film_end_time - end_time_to_int) <= 10)
            return 2;
        if(abs(exist_film_end_time - start_time_to_int) <= 20)
            return 2;
        if(abs(end_time_to_int - exist_film_start_time) <= 20)
            return 2;
    }
    return 0;
}


int SqlFuns::returnMinute(QString time_to_convert, QString date_to_convert)
{
    int return_time_interval_by_min = 0;
    int day_interval = 0;
    QString convert_year = date_to_convert.section('-', 0, 0);
    int year_to_int = convert_year.toInt();
    QString convert_month = date_to_convert.section('-', 1, 1);
    int month_to_int = convert_month.toInt();
    QString convert_day = date_to_convert.section('-', 2, 2);
    QString convert_hour = time_to_convert.section(':', 0, 0);
    QString convert_minute = time_to_convert.section(':', 1, 1);
    for(int i = 1970; i < year_to_int; i++)
    {
        if((i % 4 == 0 && i % 100 != 0)||(i % 400 == 0))
            day_interval = day_interval + 366;
        else day_interval = day_interval + 365;
    }
    for(int i = 1; i < month_to_int; i++)
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
    day_interval = day_interval + (convert_day.toInt() - 1);
    return_time_interval_by_min = return_time_interval_by_min + (day_interval * 60 * 24);
    return_time_interval_by_min = return_time_interval_by_min + (convert_hour.toInt() * 60) + convert_minute.toInt();
    return return_time_interval_by_min;
}

QStringList SqlFuns::queryHallTemplateInfo()
{
    QSqlTableModel model;
    QStringList qsl;
    model.setTable("hallTemplate");
    model.select();
    for(int i = 0; i < model.rowCount(); i++)
        qsl.append(model.record(i).value("type").toString());
    return qsl;
}

QStringList SqlFuns::queryHallTemplateInfo(QString type)
{
    QSqlTableModel model;
    QStringList qsl;
    QString tmp;
    model.setTable("hallTemplate");
    model.setFilter("type = " + formal(type));
    model.select();
    qsl.append(model.record(0).value("type").toString());
    qsl.append(tmp.sprintf("%d", model.record(0).value("row").toInt()));
    tmp = "";
    qsl.append(tmp.sprintf("%d", model.record(0).value("column").toInt()));
    qsl.append(model.record(0).value("seatMap").toString());
    qsl.append(tmp.sprintf("%d", model.record(0).value("totalSeats").toInt()));
    return qsl;
}

QString SqlFuns::getHallId()
{
    QString cinema = queryCinema(global_userName);
    QSqlTableModel model;
    model.setTable("hall");
    model.setFilter("cinema = " + formal(cinema));
    model.select();
    int row = model.rowCount();
    QString id;
    id.sprintf("#%d", row + 1);
    return id;
}

QString SqlFuns::querySeatMap(QString movieId)
{
    QSqlTableModel model;
    model.setTable("movie");
    model.setFilter("movieId = " + formal(movieId));
    model.select();
    return model.record(0).value("seatMaps").toString();
}
