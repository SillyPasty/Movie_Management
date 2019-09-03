/*
	By Silly Pasty 2019.
	本源文件包含所有涉及数据库操作的函数实现
	其中包括对五个数据库表user, movie, orders, hall，hallTemplate的新建、查询、修改、删除操作，以及其他需要调用数据库的函数，
	如判断用户选定的座位是否合法，判断管理员新增的影片是否合法等。
	其中，table为sqlite数据库中的表文件，在本程序中共使用四个表：
	user             用于存储用户和管理员的身份信息、密码等
	movie            用于存储某时段在某影院的某影厅播放的电影的信息，包括片名、上座率、选座情况、总收入等
	orders           用于存储用户建立的订单，其中包括订单指向的某一条电影记录，订单建立时间，订单购买的座位位置编号等
	hall             用于存储影院影厅的原始信息，包括所属的影院名，影厅名，影厅类型，座椅分布图等
	hallTemplate	 用于存储建立影厅时需要的影院座椅分布模板
	某些函数仅涉及单一数据库的操作，如查询等，但某些函数，如添加和删除订单，涉及多个数据库的交互
*/

#include "sqlfuns.h"

SqlFuns::SqlFuns()
{
}

QString global_userName=""; //在登陆后进入操作界面后，用户的id就被唯一确定下来。使用全局变量global_username可简化查询操作

void SqlFuns::createTables()
{
    //  创建表
	//	sql语言中，INTEGER为整数格式，相当于int型；TEXT为255位字符串格式；REAL为实型格式
	//  sql指令中，字符串格式数据需要前后加单引号，而其它格式则不需要
	//  CREATE TABLE为创建表指令
    QSqlQuery query;
    query.exec("CREATE TABLE user ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"  //	用户的数据库编号，数据库主键，用户不可操作              
               "userId TEXT,"							//	用户的唯一ID
               "password TEXT,"							//	用户的密码
               "name TEXT,"								//	用户的真实姓名
               "sex TEXT,"								//	用户的性别
               "phoneNumber TEXT,"						//	用户的联系电话
               "email TEXT,"							//	用户的电子邮箱
               "balance REAL,"							//	用户的余额	
               "isAdmin INTEGER,"						//	判断用户是否为管理员的标志
               "cinema TEXT)");							//	如果用户为管理员，该值为用户所属影院名；否则置为NULL	

    query.exec("CREATE TABLE movie ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"	//	本场次电影的数据库编号，数据库主键，用户不可操作
               "movieId TEXT,"							//	本场次电影的唯一编号
               "movieName TEXT,"						//	本场次电影名；不同场次电影的电影名可重复
               "cinema TEXT,"							//	本场次电影上映的影院
               "hall TEXT,"								//	本场次电影上映的影厅
               "startTime TEXT,"						//	本场次电影的开始时间，采用"HH:MM:SS"格式存储，精确到秒
               "endTime TEXT,"							//	本场次电影的结束时间，采用"HH:MM:SS"格式存储，精确到秒
               "length INTEGER,"						//	本场次电影长度，单位为秒
               "isPlayed INTEGER,"						//	本场次电影是否播放的标志
               "price REAL,"							//	本场次电影的价格，为实型
               "ticketRemain INTEGER,"					//	本场次剩余电影票张数
               "type TEXT,"								//	本场次电影的类型
               "isRecommened INTEGER,"					//	本场次电影是否被推荐的标志
               "totalSeats INTEGER,"					//	本场次电影的全部座位数
               "percent TEXT,"							//	本场次电影的上座率，为实型
               "totalIncome REAL,"						//	本场次电影的总收入
               "date TEXT,"								//	本场次电影的上映日期，采用"YYYY-MM-DD"格式存储，默认没有跨越24点的夜场电影
               "rowNum INT,"							//	本场次电影座区的行数
               "coloumNum INT,"							//	本场次电影座区的列数
               "seatMaps TEXT,"							//	本场次电影的座区详细分布，包括占用情况
               "language TEXT)");						//	本场次电影的语言

    query.exec("CREATE TABLE hall ("					
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"	//	本影厅的数据库编号，数据库主键，用户不可操作
               "hallId TEXT,"							//	本影厅的ID，同意影院内影厅ID不得重复，不同影院的影厅ID可以重复
               "cinema TEXT,"							//	本影厅所属的影院
               "totalSeats INTEGER,"					//	本影厅的总座位数
               "seatMap TEXT,"							//	本影厅的座位分布图	
               "row INTEGER,"							//	本影厅的行数
               "column INTEGER,"						//	本影厅的列数
               "type TEXT)");							//	本影厅的类型

    query.exec("CREATE TABLE orders ("					
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"	//	本订单的数据库编号，数据库主键，用户不可操作
               "orderId TEXT,"							//	本订单的唯一编号
               "userId TEXT,"							//	创建本订单的用户ID
               "movieId TEXT,"							//	本订单所属的电影场次
               "movieName TEXT,"						//	本订单所属的电影名
               "cinema TEXT,"							//	本订单所属的影院名
               "startTime TEXT,"						//	本订单所属的电影场次的开始时间，采用"HH:MM:SS"格式存储，精确到秒
               "endTime TEXT,"							//	本订单所属的电影场次的结束时间，采用"HH:MM:SS"格式存储，精确到秒	
               "date TEXT,"								//	本订单创建日期，采用"YYYY-MM-DD"的格式存储
               "hallId TEXT,"							//	本订单的所属的影厅ID
               "seat1pos INTEGER,"						//	本订单购买的第一个座位在所属影厅的座椅分布图中唯一位置编号，必须存在
               "seat2pos INTEGER,"						//	本订单购买的第二个座位在所属影厅的座椅分布图中唯一位置编号，可选，若不存在置为-1
               "seat3pos INTEGER,"						//	本订单购买的第三个座位在所属影厅的座椅分布图中唯一位置编号，可选，若不存在置为-1
               "isPaid INTEGER)");						//	本订单是否付款的标志

    query.exec("CREATE TABLE hallTemplate ("			
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"	//	影厅模板的数据库编号，数据库主键，用户不可操作
               "type TEXT,"								//	影厅模板的类型
               "row INTEGER,"							//	影厅模板的行数
               "column INTEGER,"						//	影厅模板的列数
               "seatMap TEXT,"							//	影厅模板的详细座位分布
               "totalSeats INTEGER)");					//	影厅模板的总座椅数
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
    int rows = 6;										//	rows为影厅的行数 
    int column = 9;										//	column为影厅的列数	
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
    int row = model.rowCount();							//	row为返回的查询结果数量
    for(int i = 0; i < 252; i++)
        if(seatMap[i] == "0")
            totalSeats++;
    model.insertRows(row, 1);							//	以下操作为在已有的结果下再新建一行记录并加入新数据
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
    // 查询管理员对应的影院
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
