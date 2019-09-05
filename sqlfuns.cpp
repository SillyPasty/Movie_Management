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

QString global_userName = ""; //在登陆后进入操作界面后，用户的id就被唯一确定下来。使用全局变量global_username可简化查询操作

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//                          数据库初始化函数区：连接数据库并建立所需的五个数据表文件							  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


//  创建表
//	sql语言中，INTEGER为整数格式，相当于int型；TEXT为255位字符串格式；REAL为实型格式
//  sql指令中，字符串格式数据需要前后加单引号，而其它格式则不需要
//  CREATE TABLE为创建表指令	QSqlQuery query;

void SqlFuns::createTables()
{
	query.exec("CREATE TABLE user ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT," //	用户的数据库编号，数据库主键，用户不可操作              
		"userId TEXT,"							//	用户的唯一ID
		"password TEXT,"						//	用户的密码
		"name TEXT,"							//	用户的真实姓名
		"sex TEXT,"								//	用户的性别
		"phoneNumber TEXT,"						//	用户的联系电话
		"email TEXT,"							//	用户的电子邮箱
		"balance REAL,"							//	用户的余额，如果为管理员，置为NULL	
		"isAdmin INTEGER,"						//	判断用户是否为管理员的标志
		"cinema TEXT)");						//	如果用户为管理员，该值为用户所属影院名；否则置为NULL	

	query.exec("CREATE TABLE movie ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT,"	//	本场次电影的数据库编号，数据库主键，用户不可操作
		"movieId TEXT,"							//	本场次电影的唯一编号
		"movieName TEXT,"						//	本场次电影名；不同场次电影的电影名可重复
		"cinema TEXT,"							//	本场次电影上映的影院
		"hall TEXT,"							//	本场次电影上映的影厅
		"startTime TEXT,"						//	本场次电影的开始时间，采用"HH:MM:SS"格式存储，精确到秒
		"endTime TEXT,"							//	本场次电影的结束时间，采用"HH:MM:SS"格式存储，精确到秒
		"length INTEGER,"						//	本场次电影长度，单位为秒
		"isPlayed INTEGER,"						//	本场次电影是否播放的标志
		"price REAL,"							//	本场次电影的价格，为实型
		"ticketRemain INTEGER,"					//	本场次剩余电影票张数
		"type TEXT,"							//	本场次电影的类型
		"isRecommened INTEGER,"					//	本场次电影是否被推荐的标志
		"totalSeats INTEGER,"					//	本场次电影的全部座位数
		"percent TEXT,"							//	本场次电影的上座率，为实型
		"totalIncome REAL,"						//	本场次电影的总收入
		"date TEXT,"							//	本场次电影的上映日期，采用"YYYY-MM-DD"格式存储，默认没有跨越24点的夜场电影
		"rowNum INT,"							//	本场次电影座区的行数
		"coloumNum INT,"						//	本场次电影座区的列数
		"seatMaps TEXT,"						//	本场次电影的座区详细分布，包括占用情况
		"language TEXT，"						//	本场次电影的语言
		"isDiscount INT)");						//	本场次电影是否打折

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
		"date TEXT,"							//	本订单创建日期，采用"YYYY-MM-DD"的格式存储
		"hallId TEXT,"							//	本订单的所属的影厅ID
		"seatsInfo TEXT,"
		"seat1pos INTEGER,"						//	本订单购买的第一个座位在所属影厅的座椅分布图中唯一位置编号，必须存在
		"seat2pos INTEGER,"						//	本订单购买的第二个座位在所属影厅的座椅分布图中唯一位置编号，可选，若不存在置为-1
		"seat3pos INTEGER,"						//	本订单购买的第三个座位在所属影厅的座椅分布图中唯一位置编号，可选，若不存在置为-1
		"isPaid INTEGER,";						//	本订单是否付款的标志
	"price REAL)");							//	本订单的总价

	query.exec("CREATE TABLE hallTemplate ("
		"id INTEGER PRIMARY KEY AUTOINCREMENT,"	//	影厅模板的数据库编号，数据库主键，用户不可操作
		"type TEXT,"							//	影厅模板的类型
		"row INTEGER,"							//	影厅模板的行数
		"column INTEGER,"						//	影厅模板的列数
		"seatMap TEXT,"							//	影厅模板的详细座位分布
		"totalSeats INTEGER)");					//	影厅模板的总座椅数
}

bool SqlFuns::connect(const QString& dbName)
{
	//  连接并打开数据库
	//	dbName为数据库名
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);
	//	如果数据库打开失败返回false
	if (!db.open())
	{
		QMessageBox::critical(nullptr, QObject::tr("Database Error"), db.lastError().text());
		return false;
	}
	//	如果数据库打开成功返回true

	return true;
}

//void SqlFuns::addNewHallTemplate()
//{
//    QSqlTableModel model;

//    QString type = "VIP厅";
//    int rows = 6;
//    int column = 9;                         //
//    QString seatMap = "222222222222222222222"
//                      "222222222222222222222"
//                      "222222222222222222222"
//                      "222222000000000222222"
//                      "222222002200000222222"
//                      "222222222200000222222"
//                      "222222222222222222222"
//                      "222222000000000222222"
//                      "222222000000000222222"
//                      "222222222222222222222"
//                      "222222222222222222222"
//                      "222222222222222222222";
//    int totalSeats = 0;
//    model.setTable("hallTemplate");
//    model.select();
//    //  查询row
//    int row = model.rowCount();
//    for(int i = 0; i < 252; i++)
//        if(seatMap[i] == "0")
//            totalSeats++;
//    model.insertRows(row, 1);
//    model.setData(model.index(row, 1), type);
//    model.setData(model.index(row, 2), rows);
//    model.setData(model.index(row, 3), column);
//    model.setData(model.index(row, 4), seatMap);
//    model.setData(model.index(row, 5), totalSeats);
//    model.submitAll();
//}


//	将字符串格式化为数据库中TEXT形式

QString SqlFuns::formal(QString str)
{
	//	将字符串前后加入单引号
	QString sym = "'";
	return (sym + str + sym);
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//                               添加函数区：根据传入的数据向数据库中添加新的元素							  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


//	注册用户
//	传入字符串形式的用户名userId，密码password，用户姓名name，用户性别sex，用户电话号码phonenumber，用户电子邮箱email
//	传入int型isAdmin，0表示不是管理员，1表示为管理员
//	传入字符串型cinema，若用户是管理员，则字符串非空，表示为用户分辖的电影院；若用户不是管理员，置为NULL
//	向数据库中user表插入以上信息

void SqlFuns::registerUser(QString userId, QString password, QString name, \
	QString sex, QString phonenumber, QString email, int isAdmin, QString cinema)
{
	QSqlQuery query;									//	新建数据库指令类
	QString or1 = "INSERT INTO user VALUES (NULL,";		//	建立并维护数据库指令字符串
														//	向数据库表中插入新项指令：INSERT INTO tablename VALUES（value1, value2, value3, ...）
	userId = formal(userId) + ",";
	password = formal(password) + ",";
	name = formal(name) + ",";
	sex = formal(sex) + ",";
	phonenumber = formal(phonenumber) + ",";
	email = formal(email) + ",";
	cinema = formal(cinema) + ")";

	//	判断是否为管理员
	//	如果是管理员，则账户余额balance置为NULL
	//	如果不是管理员，则分辖影院置为NULL
	QString isAd;
	isAd.sprintf("%d,", isAdmin);
	if (isAdmin)
		or1 = or1 + userId + password + name + sex + phonenumber + \
		email + "NULL," + isAd + cinema;
	else
		or1 = or1 + userId + password + name + sex + phonenumber + \
		email + "0," + isAd + "NULL)";
	query.exec(or1);									//	执行数据库指令
}





//  添加一个新电影场次
//	传入字符串：电影唯一ID movieId，电影名称name，本场次所属影院cinema，本场次所属影厅hall，
//	本场次电影开始时间（hh:mm:ss）startTime，本场次电影结束时间（hh:mm:ss）endTime
//	传入Int型电影长度length，单位为秒
//	传入float型电影价格price
//	传入Int型本场次电影剩余票数ticketRemain
//	传入字符串本场次电影类型type
//	传入Int型是否推荐的标志isRecommened
//	传入字符串本场次电影日期date
//	传入字符串本场次电影的座椅分布和作为分布情况seatMaps
//	传入字符串本场次电影的语言language
//	传入Int型是否打折的标志isDiscount
//	将以上信息添加到movie表中

void SqlFuns::addNewFilm(QString movieId, QString name, QString cinema, \
	QString hall, QString startTime, QString endTime, int length, \
	float price, int ticketRemain, QString type, int isRecommened, \
	QString date, QString seatMaps, QString language, int isDiscount)
{
	QSqlTableModel model;											//	新建QTSQL数据库表model
	model.setTable("movie");										//	指向movie表					
	model.select();
	int row = model.rowCount();										//	查询movie表中已有记录数量											
	model.insertRows(row, 1);										//	在最后一行记录下新建一行记录
	model.setData(model.index(row, 1), movieId);
	model.setData(model.index(row, 2), name);
	model.setData(model.index(row, 3), cinema);
	model.setData(model.index(row, 4), hall);
	model.setData(model.index(row, 5), startTime);
	model.setData(model.index(row, 6), endTime);
	model.setData(model.index(row, 7), length);
	model.setData(model.index(row, 8), 0);							//	默认新建的电影没有播放
	model.setData(model.index(row, 9), price);
	model.setData(model.index(row, 10), ticketRemain);
	model.setData(model.index(row, 11), type);
	model.setData(model.index(row, 12), isRecommened);
	model.setData(model.index(row, 13), ticketRemain);
	model.setData(model.index(row, 14), "0%");						//	没有播放的电影，上座率为0
	model.setData(model.index(row, 15), 0);							//	尚未有购票记录，总收入为0			
	model.setData(model.index(row, 16), date);
	model.setData(model.index(row, 17), queryRow(hall, cinema));	//	数据库调用本影院本影厅的行数	
	model.setData(model.index(row, 18), queryColumn(hall, cinema));	//	数据库调用本影院本影厅的列数
	model.setData(model.index(row, 19), seatMaps);
	model.setData(model.index(row, 20), language);
	model.setData(model.index(row, 21), isDiscount);				//	是否打折	
	model.submitAll();												//	提交更新
}



//	管理员调用函数
//	添加一个新的影院
//	传入字符串影厅名hallId，影院名cinema
//	传入Int型总座椅数totalseats，行数row，列数column
//	传入字符串总座椅分布图seatMap，影厅类型type

void SqlFuns::addNewHall(QString hallId, QString cinema, int totalseats, \
	int row, int column, QString seatMap, QString type)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	model.setTable("hall");														//	指向hall表	
	model.select();
	int rows = model.rowCount();												//	查询hall表中已有记录数量											
	model.insertRows(rows, 1);													//	在最后一行记录下新建一行记录
	model.setData(model.index(rows, 1), hallId + " " + type);
	model.setData(model.index(rows, 2), cinema);
	model.setData(model.index(rows, 3), totalseats);
	model.setData(model.index(rows, 4), seatMap);
	model.setData(model.index(rows, 5), row);
	model.setData(model.index(rows, 6), column);
	model.setData(model.index(rows, 7), type);
	model.submitAll();
}

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//          查询函数区：以query为开头的函数，根据提供的信息或全局变量用户名在数据库中查询需要的数据并返回         // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

// 查询用户名对应密码是否正确 若用户不存在返回空字符串

QString SqlFuns::queryPassword(QString userName)
{
	QSqlQuery query;												//	新建数据库指令类
	QString ord = "SELECT password FROM user WHERE userId = ";		//	建立并维护数据库指令字符串
																	//	数据库检索指令：SELECT columnname FROM tablename WHRER columnvalue = ...
	userName = formal(userName);
	ord = ord + userName;
	query.exec(ord);												//	执行数据库指令
	if (query.next())
	{
		QString psd = query.value(0).toString();
		return psd;
	}
	else
		return "";
}

// 登陆时查询用户是否拥有管理员权限，进入不同界面

int SqlFuns::queryIsadmin(QString userName)
{
	QSqlQuery query;												//	新建数据库指令类
	QString ord = "SELECT isAdmin FROM user WHERE userId = ";		//	数据库中按用户名检索isAdmin值，判断是否是管理员
	userName = formal(userName);
	ord = ord + userName;
	query.exec(ord);												//	执行数据库指令
	query.next();
	int flag = query.value(0).toInt();
	return flag;
}

//	管理员调用函数 
//	根据全局变量管理员ID和影厅ID 查询某个影厅拥有的座位数量
//	传入两个字符串hallId，cinema代表影厅编号，输出一个Int型代表座椅数量

int SqlFuns::queryHallSeates(QString hallId)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	model.setTable("hall");														//	指向hall表		
	hallId = formal(hallId);
	QString cinema = queryCinema(global_userName);								//	调用queryCinema函数，返回管理员所在的影院名
	model.setFilter("hallId = " + hallId + " and cinema = " + formal(cinema));	//	根据影院和影厅名成检索数据库
	model.select();
	QSqlRecord record = model.record(0);										//	选择第一条记录（程序未出错情况下只会查询到一条记录）				
	return record.value("totalSeats").toInt();
}

//	查询管理员对应的影院
//	传入值为字符串，为用户名userId
//	输出值为字符串，为影院名
QString SqlFuns::queryCinema(QString userId)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	model.setTable("user");														//	指向user表		
	userId = formal(userId);
	model.setFilter("userId = " + userId);										//	按照userId检索数据库user表
	model.select();
	QSqlRecord record = model.record(0);										//	选择第一条记录
	return record.value("cinema").toString();
}

//	查询电影院中所有的影厅ID 返回一个字符串列表
//	传入值为字符串，为影院名cinema
//	输出值为字符串列表，为影院中所用的影厅的ID
QStringList SqlFuns::queryHallId(QString cinema)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	QStringList qsl;															//	新建字符串列表qsl表示影厅名列表
	model.setTable("hall");														//	指向hall表
	cinema = formal(cinema);
	model.setFilter("cinema = " + cinema);										//	按照cinema值检索数据库
	model.select();

	for (int i = 0; i < model.rowCount(); i++)									//	所有查找到的结果
		qsl.append(model.record(i).value("hallId").toString());					//	将结果记录中的hallId值转化为字符串格式加在qsl列表末尾最后
	return qsl;
}


//	查询某个hall中的座位图 返回一个字符串儿
//	缺少movieId 待修改

QString SqlFuns::queryHallSeatMap(QString hallId)
{
	QSqlTableModel model;
	model.setTable("hall");
	hallId = formal(hallId);
	QString cinema = queryCinema(global_userName);
	model.setFilter("hallId = " + hallId + " and cinema = " + formal(cinema));
	model.select();
	QSqlRecord record = model.record(0);
	return record.value("seatMap").toString();
}


//	查询某个影厅的座位行数
//	输入两个字符串值hallId和cinema，分别表示影厅ID和影院名称
//	输出为一个Int值，代表查询到影院的座位行数

int SqlFuns::queryRow(QString hallId, QString cinema)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model	
	model.setTable("hall");														//	指向hall表							
	hallId = formal(hallId);
	cinema = formal(cinema);
	model.setFilter("hallId = " + hallId + " and cinema = " + cinema);			//	按照cinema值和hallId值检索数据库
	model.select();
	QSqlRecord record = model.record(0);										//	选择第一条记录（程序未出错情况下只会查询到一条记录）	
	return record.value("row").toInt();											//	将该条记录中row值转换为Int型输出	
}

//	查询某个影厅的座位行数
//	输入两个字符串值hallId和cinema，分别表示影厅ID和影院名称
//	输出为一个Int值，代表查询到影院的座位行数

int SqlFuns::queryColumn(QString hallId, QString cinema)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	model.setTable("hall");														//	指向hall表		
	hallId = formal(hallId);
	cinema = formal(cinema);
	model.setFilter("hallId = " + hallId + " and cinema = " + cinema);			//	按照cinema值和hallId值检索数据库
	model.select();
	QSqlRecord record = model.record(0);										//	选择第一条记录（程序未出错情况下只会查询到一条记录）	
	return record.value("column").toInt();										//	将该条记录中row值转换为Int型输出	
}

//	查询某个影厅可放映的电影类型
//	输入两个字符串值hallId和cinema，分别表示影厅ID和影院名称
//	输出为一个Int值，代表查询到影院的座位行数

QString SqlFuns::queryType(QString hallId, QString cinema)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	model.setTable("hall");														//	指向hall表
	hallId = formal(hallId);
	cinema = formal(cinema);
	model.setFilter("hallId = " + hallId + " and cinema = " + cinema);			//	按照cinema值和hallId值检索数据库
	model.select();
	QSqlRecord record = model.record(0);										//	选择第一条记录（程序未出错情况下只会查询到一条记录）
	return record.value("type").toString();										//	将该条记录中row值转换为Int型输出		
}

//  查询user对应的个人信息，按照电子邮箱，电话，密码的顺序返回一个字符串列表
//	输入一个字符串值userId，表示用户Id
//	输出一个字符串列表，按照电子邮箱，电话，密码的顺序返回

QStringList SqlFuns::queryEmailPhonePsd(QString userId)
{
	QSqlTableModel model;														//	新建QTSQL数据库表mode	l		
	QStringList qsl;															//	新建字符串列表qsl表示用户信息表
	model.setTable("user");														//	指向user表
	userId = formal(userId);
	model.setFilter("userId = " + userId);
	model.select();
	QSqlRecord record = model.record(0);										//	选择第一条记录（程序未出错情况下只会查询到一条记录）	
	qsl.append(record.value("email").toString());								//	将该条记录中email值转换为字符串加入到qsl列表中
	qsl.append(record.value("phoneNumber").toString());							//	将该条记录中phnoeNumber值转换为字符串加入到qsl列表中
	qsl.append(record.value("password").toString());							//	将该条记录中password值转换为字符串加入到qsl列表中
	return qsl;
}

//	管理员操作
//	返回一个表模型指针，代表该影院该影厅本片名电影的所有场次
//	输入为两个字符串movieName和hallId，代表影院名和影厅名
//	输出为表模型指针，代表按条件筛选得到的所有电影场次
//	若输入空字符串 返回所有电影院对应电影
//	可按条件查找

QSqlTableModel* SqlFuns::queryAdminMovie(QString movieName, QString hallId)
{
	QSqlTableModel* model = new QSqlTableModel;									//	新建QTSQL数据库表指针model			
	model->setTable("movie");													//	指向movie表			
	model->setSort(8, Qt::DescendingOrder);										//	按照是否播放降序排列	
	QString ord;																//	新建数据库指令字符串			
	QString cinema = queryCinema(global_userName);								//	调用queryCinema函数，返回管理员所在的影院名
	cinema = formal(cinema);
	ord = "cinema = " + cinema;													//	按照cinema值检索数据库movie表
	if (movieName != "")														//	如果	movieName不为空字符串，增加筛选条件电影名
	{
		movieName = formal(movieName);
		ord = ord + "and movieName = " + movieName;
	}
	if (hallId != "")															//	如果	hallId不为空字符串，增加筛选条件影厅名
	{
		hallId = formal(hallId);
		ord = ord + "and hall = " + hallId;
	}
	model->setFilter(ord);
	model->select();															//	按筛选条件检索数据库movie表
	return model;
}

//	非管理员用户操作
//	返回一个表模型指针，代表该影院、该影厅、本类型、本语言、本片名电影的所有场次
//	输入为四个字符串movieName, hallId, type, language代表影院名、影厅名、类型和语言，若任意一项为空字符串则表示不以此条件筛选
//	输出为表模型指针，代表按条件筛选得到的所有电影场次
//	若输入空字符串 返回所有电影院对应电影
//	可按条件查找

QSqlTableModel* SqlFuns::queryUserMovie(QString movieName, QString cinema, \
	QString type, QString language)
{
	QSqlTableModel* model = new QSqlTableModel;									//	新建QTSQL数据库表指针model	
	model->setTable("movie");													//	指向movie表	
	model->setSort(12, Qt::DescendingOrder);									//	按照推荐与否进行排序（降序排列）
	QString ord = "isPlayed = 0";												//	新建数据库指令字符，仅筛选尚未播放的电影				

	if (cinema != "")															//	如果cinema不为空字符串，增加筛选条件影厅名	
	{
		cinema = formal(cinema);
		ord = ord + " and cinema = " + cinema;
	}

	if (type != "")																//	如果type不为空字符串，增加筛选条件电影类型	
	{
		type = formal(type);
		ord = ord + " and type = " + type;
	}

	if (language != "")															//	如果language不为空字符串，增加筛选条件语言
	{
		language = formal(language);
		ord = ord + " and language = " + language;
	}

	if (movieName != "")														//	如果movieName不为空字符串，增加筛选条件电影名
	{
		movieName = formal(movieName);
		ord = ord + " and movieName = " + movieName;
	}
	model->setFilter(ord);														//	按筛选条件检索数据库movie表
	model->select();
	return model;																//	返回model指针
}

//	管理员操作
//	返回一个表模型指针，代表管理员分辖的影院下按条件筛选得到的影厅列表
//	输入为一个字符串hallId，代表要查找的影厅Id
//	输出为QT Sql model指针，代表查找得到的所有影厅列表
//	若输入空字符串 返回当前影院全部影厅列表
//	可按条件查找

QSqlTableModel* SqlFuns::queryAdminHall(QString hallId)
{
	QSqlTableModel* model = new QSqlTableModel;									//	新建QTSQL数据库表指针model	
	model->setTable("hall");													//	指向hall表
	QString ord;																//	新建数据库指令字符串	
	QString cinema = queryCinema(global_userName);								//	调用queryCinema函数，返回管理员所在的影院名			
	cinema = formal(cinema);
	ord = "cinema = " + cinema;													//	按照cinema值检索数据库movie表
	if (hallId != "")															//	如果hallId不为空字符串，增加筛选条件影厅名
	{
		hallId = formal(hallId);
		ord = ord + "and hallId = " + hallId;
	}
	model->setFilter(ord);														//	按筛选条件检索数据库movie表
	model->select();
	return model;																//	返回model指针
}

//	非管理员用户操作
//	查询当前用户余额并返回

float SqlFuns::queryBalance()
{
	QSqlTableModel model;														//	新建QTSQL数据库表指针model	
	model.setTable("user");
	QString userId = formal(global_userName);									//	按照全局变量用户名global_userName检索user表
	model.setFilter("userId = " + userId);
	model.select();
	return model.record(0).value("balance").toFloat();							//	选择第一条记录（程序未出错情况下只会查询到一条记录），将第一条记录中的balance值转换为float型并回传	
}

//	初始化操作
//	查询电影类型 并返回于comboBox中显示
//	返回值为字符串列表QStringList，代表全部的电影类型

QStringList SqlFuns::queryType()
{
	QSqlTableModel model;														//	新建QTSQL数据库表model	
	QStringList qsl;															//	新建字符串列表qsl
	qsl.append("全部");															//	在字符串列表首项添加“全部”，用于用户的筛选操作
	model.setTable("hall");														//	指向数据库hall表	
	model.select();
	for (int i = 0; i < model.rowCount(); i++)									//	先将所有影厅的类型信息转换为字符串后加入字符串列表qsl		
		qsl.append(model.record(i).value("type").toString());
	qsl.removeDuplicates();														//	删除字符串列表qsl中的重复项
	return qsl;
}

// 初始化操作
// 查询电影院 并返回于comboBox中显示
//	返回值为字符串列表QStringList，代表全部的电影院

QStringList SqlFuns::queryCinema()
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	QStringList qsl;															//	新建字符串列表qsl
	qsl.append("全部");															//	在字符串列表首项添加“全部”，用于用户的筛选操作
	model.setTable("hall");														//	指向数据库hall表	
	model.select();
	for (int i = 0; i < model.rowCount(); i++)									//	先将所有影厅的所属影院名转换为字符串后加入字符串列表qsl		
		qsl.append(model.record(i).value("cinema").toString());
	qsl.removeDuplicates();														//	删除字符串列表qsl中的重复项
	return qsl;
}

//	用户操作
//	查询订单所购买的电影信息 用于订单购买
//	输入值为一个字符串movieId，代表电影唯一ID
//	返回值为字符串列表QStringList，代表订单所需的本场次电影信息

QStringList SqlFuns::queryOrderInfo(QString movieId)
{

	QSqlTableModel model;														//	新建QTSQL数据库表model
	model.setTable("movie");													//	指向数据库movie表	
	movieId = formal(movieId);
	model.setFilter("movieId = " + movieId);									//	按照movieId检索数据库model表
	model.select();
	QStringList qsl;															//	新建字符串列表qsl，选择第一条记录（程序未出错情况下，有且只有一条记录）
	qsl.append(model.record(0).value("cinema").toString());						//	将影院名转换为字符串后加入字符串列表qsl		
	qsl.append(model.record(0).value("startTime").toString());					//	将本场次电影的开始时间名转换为字符串后加入字符串列表qsl		
	qsl.append(model.record(0).value("endTime").toString());					//	将本场次电影的结束时间名转换为字符串后加入字符串列表qsl	
	qsl.append(model.record(0).value("date").toString());						//	将本场次电影的日期转换为字符串后加入字符串列表qsl
	qsl.append(model.record(0).value("hall").toString());						//	将本场次电影的影厅ID转换为字符串后加入字符串列表qsl
	return qsl;																	//	返回字符串列表qsl
}

//	后台操作
//	用于查询电影名
//	输入为字符串类型movieId，代表电影的唯一ID
//	返回值为字符串型，代表订单所需的本场次电影的信息

QString SqlFuns::queryMovieName(QString movieId)
{
	QSqlTableModel model;														//	新建QTSQL数据库表model
	movieId = formal(movieId);
	model.setTable("movie");													//	指向数据库movie表	
	model.setFilter("movieId = " + movieId);
	model.select();
	return model.record(0).value("movieName").toString();						//	将本场次电影名转换为字符串返回
}

//	用户操作
//	返回一个表模型指针，代表该用户购买的同一电影名和同一影院下的所有电影订单
//	输入为两个字符串movieName和cinema，分别代表选定的电影名称和影院名
//	若输入空字符串 返回当前用户所有订单
//	可按条件查找

QSqlTableModel* SqlFuns::queryUserOrder(QString movieName, QString cinema)
{
	QSqlTableModel* model = new QSqlTableModel;									//	新建QTSQL数据库表指针model	
	model->setTable("orders");													//	指向数据库orders表
	model->setSort(14, Qt::DescendingOrder);									//	按照是否付款排序
	QString ord = "userId = " + formal(global_userName);						//	新建数据库指令字符串，并调用全局变量用户名作为筛选条件	
	if (cinema != "")															//	如果代表影院名的字符串cinema非空，则增加筛选条件cinema
	{
		cinema = formal(cinema);
		ord = ord + " and cinema = " + cinema;
	}
	if (movieName != "")														//	如果代表电影名的字符串movieName非空，则增加筛选条件movieName
	{
		movieName = formal(movieName);
		ord = ord + " and movieName = " + movieName;
	}
	model->setFilter(ord);														//	按筛选条件检索数据库movie表
	model->select();
	return model;																//	将结果模型指针返回	
}

//	根据电影ID查询价格
//	输入值为一个字符串代表电影的唯一编号
//	输出值为float型代表电影的票价

float SqlFuns::queryPrice(QString movieId)
{
	QSqlTableModel model;														//	新建QTSQL数据库表指针model
	model.setTable("movie");													//	指向数据库movie表	
	model.setFilter("movieId = " + formal(movieId));							//	按照movieId检索数据库movie表
	model.select();
	float cur = model.record(0).value("price").toFloat();;						//	选择第一条记录（程序未出错情况下只会查询到一条记录），将其转化为float型后输出
	return cur;
}

//	管理员操作
//	返回一个表模型指针，代表在管理员分辖的影院中，该筛选条件下的全部订单
//	输入为筛选条件，包括字符串类型 movieName，userId，startDate，endDate，分别代表
//  电影名称，用户名，时间区段的开始日期，时间区段的结束日期；
//	Int型变量isPlayed，代表是否播放
//	若输入空字符串,则不按照该筛选项筛选； 
//	若输入全部为空字符串，返回当前影院对应全部订单
//	可按条件查找

QSqlTableModel* SqlFuns::queryAdminOrder(QString movieName, QString userId, \
	QString startDate, QString endDate, int isPlayed)
{
	QSqlTableModel* model = new QSqlTableModel;									//	新建QTSQL数据库表指针model
	model->setTable("orders");													//	指向数据库orders表
	model->setSort(15, Qt::DescendingOrder);									//	按照订单总价降序排列 
	QString cinema = queryCinema(global_userName);								//	调用queryCinema函数，按照全局变量管理员用户名获得当前影院名
	QString ord = "cinema = " + formal(cinema);
	QTime curTime = QTime::currentTime();										//	获得当前时间
	QDate curDate = QDate::currentDate();										//	获得当前日期

	if (isPlayed == 1)															//	若查询当前尚未播放的电影
		ord = ord + " and date >= " + formal(curDate.toString("yyyy-MM-dd")) \	//	将当前日期转为“yyyy-mm-dd”格式，将时间转为“hh-mm-ss”格式
		+ " and startTime > " + formal(curTime.toString("hh:mm:ss"));			//	筛选得到的电影订单对应的电影播放时间应不早于当前日期，若日期与当前相同，应晚于当前时间
	if (isPlayed == 2)															//	若查询当前已经播放过的，或正在播放的电影	
		ord = ord + " and date <= " + formal(curDate.toString("yyyy-MM-dd")) \	//	将当前日期转为“yyyy-mm-dd”格式，将时间转为“hh-mm-ss”格式
		+ " and startTime < " + formal(curTime.toString("hh:mm:ss"));			//	筛选得到的电影订单对应的电影播放时间应不晚于当前日期，若日期与当前相同，应早于当前时间

	if (userId != "")															//	如果userId字符串非空，则增添userId筛选项
	{
		userId = formal(userId);
		ord = ord + " and userId = " + userId;
	}

	if (movieName != "")														//	如果movieName字符串非空，则增添movieName筛选项
	{
		movieName = formal(movieName);
		ord = ord + " and movieName = " + movieName;
	}

	if (startDate != "")														//	如果startDate字符串非空，则增添startDate筛选项
	{
		startDate = formal(startDate);
		endDate = formal(endDate);
		ord = ord + " and date > " + startDate + " and date < " + endDate;
	}
	model->setFilter(ord);														//	按照筛选条件检索数据库orders表
	model->select();
	return model;																//	将结果模型指针返回	
}

//	返回所有影厅模板的影厅类型
//	返回值为字符串列表QStringList，代表所有模板的影厅类型

QStringList SqlFuns::queryHallTemplateInfo()
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	QStringList qsl;															//	新建字符串列表qsl
	model.setTable("hallTemplate");												//	指向数据库hallTemplate表
	model.select();
	for (int i = 0; i < model.rowCount(); i++)
		qsl.append(model.record(i).value("type").toString());					//	将每一条记录里的type值转换为字符串后加入到qsl字符串列表里
	return qsl;																	//	返回qsl字符串列表
}

//	返回某一影厅类型的的影厅模板信息
//	返回值为字符串列表QStringList，代表该类型影厅模板的所需信息

QStringList SqlFuns::queryHallTemplateInfo(QString type)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	QStringList qsl;															//	新建字符串列表qsl
	QString tmp;																//	临时字符串变量
	model.setTable("hallTemplate");												//	指向数据库hallTemplate表
	model.setFilter("type = " + formal(type));									//	按照影厅类型检索hallRemplate表
	model.select();
	qsl.append(model.record(0).value("type").toString());						//	选择筛选结果中第一条记录（若程序未发生错误则选择第一条记录），将记录中type数据转换为字符串类型加入qsl列表中
	qsl.append(tmp.sprintf("%d", model.record(0).value("row").toInt()));		//	将记录中row数据转化为Int型，再将该数值转换为字符串加入qsl列表中
	tmp = "";																	//	初始化临时字符串变量
	qsl.append(tmp.sprintf("%d", model.record(0).value("column").toInt()));		//	将记录中column数据转化为Int型，再将该数值转换为字符串加入qsl列表中
	qsl.append(model.record(0).value("seatMap").toString());					//	将记录中seatMap数据转化为字符串类型，加入qsl列表中	
	qsl.append(tmp.sprintf("%d", model.record(0).value("totalSeats").toInt()));	//	将记录中totalSeats数据转化为Int型，再将该数值转换为字符串加入qsl列表中
	return qsl;																	//	返回qsl字符串列表
}

//	新建影厅时调用，查找当前影院现有影厅数量，并加#号返回新建的影厅的编号
//	输出值为字符串类型，表示新建影厅的Id编号

QString SqlFuns::getHallId()
{
	QString cinema = queryCinema(global_userName);								//	调用queryCinema函数，根据全局变量用户名得到管理员分辖的影院名cinema
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("hall");														//	指向数据库hall表
	model.setFilter("cinema = " + formal(cinema));								//	按照影院名检索数据库hall表
	model.select();
	int row = model.rowCount();													//	数据库全部记录值
	QString id;
	id.sprintf("#%d", row + 1);													//	生成当前新建的影厅的编号，在数值前加#号生成字符串
	return id;																	//	返回新建影厅的Id编号
}

//	返回本场次电影的座位分布图与座位占用情况
//	传入值为一个字符串QString，代表本场次电影唯一ID 
//	输出值为一个字符串，代表本场次电影的座位分布图和占用情况

QString SqlFuns::querySeatMap(QString movieId)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("movie");													//	指向数据库movie表
	model.setFilter("movieId = " + formal(movieId));							//	按照movieId检索数据库movie表	
	model.select();
	return model.record(0).value("seatMaps").toString();						//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），将该记录seatMaps值转换为字符串并返回
}

//	返回本场次电影的所需信息
//	传入值为一个字符串QString，代表本场次电影唯一ID 
//	输出值为一个字符串列表，分别为影厅，开始时间，开始日期，上座率，总收入

QStringList SqlFuns::queryMovieInfo(QString movieId)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	QStringList qsl;															//	新建字符串列表qsl
	QString tmp;																//	新建临时字符串变量tmp
	model.setTable("movie");													//	指向数据库movie表
	model.setFilter("movieId = " + formal(movieId));							//	按照movieId检索数据库movie表
	model.select();
	qsl.append(model.record(0).value("hall").toString());						//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），将该记录hall值转换为字符串并加入qsl列表
	qsl.append(model.record(0).value("startTime").toString());					//	将该记录startTime值转换为字符串并加入qsl列表
	qsl.append(model.record(0).value("date").toString());						//	将该记录date值转换为字符串并加入qsl列表
	tmp = "";																	//	初始化临时字符串变量
	qsl.append(model.record(0).value("percent").toString());					//	将该记录中percent值转换为字符串并加入qsl列表
	tmp = "";																	//	初始化临时字符串变量
	qsl.append(tmp.sprintf("%.2f", \											//	将该记录中totalIncome值转换为float型，再按两位小数形式转换为字符串，并加入qsl列表中	
		model.record(0).value("totalIncome").toFloat()));
	return qsl;
}


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//          修改函数区：根据提供的信息或全局变量用户名在数据库中查询需要的数据，如果需要则返回					  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


//	更新电影座位图
//	传入数据为字符串形式，分别为本场次电影的唯一ID，以及修改好的座位分布图和占用情况

void SqlFuns::updateSeatMap(QString movieId, QString seatMap)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("movie");													//	指向数据库movie表
	model.setFilter("movieId = " + formal(movieId));							//	按照movieId检索数据库movie表
	model.select();
	model.setData(model.index(0, 19), seatMap);									//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），更新本场次的电影的座位分布图和座区分布情况
	model.submitAll();															//	提交更改
}

//	更改个人信息
//	传入三个字符串分别代表用户电子邮箱地址，用户密码，用户电话号码

void SqlFuns::changeUserInfo(QString email, QString passwd, QString phoneNum)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("user");														//	指向数据库user表
	QString userId = formal(global_userName);									//	调用全局变量用户名，并规范化用于检索
	model.setFilter("userId = " + userId);										//	按照userId检索数据库user表
	model.select();
	model.setData(model.index(0, 2), passwd);									//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），更新用户密码
	model.setData(model.index(0, 6), email);									//	更新用户电子邮箱地址
	model.setData(model.index(0, 5), phoneNum);									//	更新用户电话号码
	model.submitAll();															//	提交更改
}

//	非管理员用户操作
//	更改当前用户余额 可增加 可支出
//	传入一float值，表示用户增加或支出的数额
//	返回一个float值，代表用户当前余额

float SqlFuns::changeUserBalance(float amount)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("user");														//	指向数据库user表
	QString userId = formal(global_userName);									//	调用全局变量用户名，并规范化用于检索
	model.setFilter("userId = " + userId);
	model.select();
	float cur = model.record(0).value("balance").toFloat();						//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），并将balance值转换为float型
	cur += amount;																//	更改余额
	model.setData(model.index(0, 7), cur);										//	更新数据库中用户余额
	model.submitAll();															//	提交更新
	return cur;																	//	返回用户当前余额
}

//	用户操作
//	添加一新订单
//	传入数据为字符串movieId代表购买场次的电影
//	传入seat1pos，seat2pos，seat3pos为购买的三个座位的坐标，若第二、三个座位未购买，则置为0
//	坐标编号的规则为四位整数，前两位代表列，后两位代表行，均从1开始编号
//	传入字符串为当前的时间和日期
//	传入float型数据，为该场次电影的票价
//	回传一个字符串，代表本订单的唯一编号

QString SqlFuns::addNewOrder(QString movieId, int seat1pos, int seat2pos, \
	int seat3pos, QString curTimeDate, float price)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("orders");													//	指向orders表
	model.select();
	//  查询row 和 col
	int rows = model.rowCount();												//	返回当前已有的订单数
	model.insertRows(rows, 1);													//	新建一行记录
	QString movieName = queryMovieName(movieId);								//	调用queryMovieName函数，添加订单的movieName数据
	//QString seatsInfo;
	QStringList info = queryOrderInfo(movieId);									//	调用queryOrderInfo函数，得到订单所需的其他信息

	QString orderId, seatsInfo;
	orderId = info[0] + info[4] + curTimeDate;									//	生成订单唯一编号：影院名+影厅名+当前时间
	seatsInfo.sprintf("%d排%d列", seat1pos % 100, seat1pos / 100);				//	生成交互用的座位信息
	if (seat2pos != 0)															//	至少有两个座位时	
		seatsInfo.sprintf("%d排%d列   %d排%d列", seat1pos % 100, \
			seat1pos / 100, seat2pos % 100, seat2pos / 100);
	if (seat3pos != 0)															//	有三个座位时
		seatsInfo.sprintf("%d排%d列   %d排%d列   %d排%d列", \
			seat1pos % 100, seat1pos / 100, seat2pos % 100, \
			seat2pos / 100, seat3pos % 100, seat3pos / 100);
	model.setData(model.index(rows, 1), orderId);								//	本订单的唯一编号
	model.setData(model.index(rows, 2), global_userName);						//	创建订单的用户ID		
	model.setData(model.index(rows, 3), movieId);								//	本订单所属的电影场次
	model.setData(model.index(rows, 4), movieName);								//	本订单所属的电影名	
	model.setData(model.index(rows, 5), info[0]);								//	本订单所属的影院名
	model.setData(model.index(rows, 6), info[1]);								//	本订单所属的电影场次的开始时间，采用"HH:MM:SS"格式存储，精确到秒
	model.setData(model.index(rows, 7), info[2]);								//	本订单所属的电影场次的结束时间，采用"HH:MM:SS"格式存储，精确到秒	
	model.setData(model.index(rows, 8), info[3]);								//	本订单创建日期，采用"YYYY-MM-DD"的格式存储
	model.setData(model.index(rows, 9), info[4]);								//	本订单的所属的影厅ID
	model.setData(model.index(rows, 10), seatsInfo);
	model.setData(model.index(rows, 11), seat1pos);								//	本订单购买的第一个座位在所属影厅的座椅分布图中唯一位置编号，必须存在
	model.setData(model.index(rows, 12), seat2pos);								//	本订单购买的第二个座位在所属影厅的座椅分布图中唯一位置编号，可选，若不存在置为-1
	model.setData(model.index(rows, 13), seat3pos);								//	本订单购买的第三个座位在所属影厅的座椅分布图中唯一位置编号，可选，若不存在置为-1
	model.setData(model.index(rows, 14), 0);									//	本订单是否付款的标志，此处为未付款
	model.setData(model.index(rows, 15), price);								//	本订单的总价
	model.submitAll();
	return orderId;																//	回传本订单的唯一编号
}

// 用户操作 付款
// 更新多项

void SqlFuns::changePaymentStage(QString orderId, int num, float price)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("orders");													//	指向orders表
	model.setFilter("orderId = " + formal(orderId));							//	按照orderId筛选orders表
	model.select();
	QString movieId = model.record(0).value("movieId").toString();				//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），并将movieId值转换为字符串
	QString percentage;
	model.setData(model.index(0, 14), 1);										//	更新支付情况
	model.submitAll();
	model.setTable("movie");													//	指向movie表
	model.setFilter("movieId = " + formal(movieId));							//	按照movieId筛选movie表
	model.select();
	int ticket = model.record(0).value("ticketRemain").toInt();					//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录），并将ticketRemain值转换为Int
	int totalSeat = model.record(0).value("totalSeats").toInt();				//	将记录中totalSeats值转换为Int
	float totalIncome = model.record(0).value("totalIncome").toFloat();			//	将记录中totalIncome值转换为float
	ticket -= num;																//	剩余票数减去购买票数
	totalIncome += price;														//	总收入加上订单总价
	float percent = (float)(totalSeat - ticket) / totalSeat;					//	更新上座率	
	percentage.sprintf("%.2f%", percent * 100);									//	将上座率按两位小数的形式转换为字符串
	model.setData(model.index(0, 10), ticket);									//	更新该场次电影的剩余票数	
	model.setData(model.index(0, 15), totalIncome);								//	更新该场次电影的总收入
	model.setData(model.index(0, 14), percentage);								//	更新该场次电影的上座率
	model.submitAll();															//	提交更新
}

//	取消订单 在数据库中删除订单
//	传入值为一个字符串，为订单的唯一编号
//	传出int值：若订单已付款，则回传-1表示订单已不能取消；
//	若订单未付款，回传1，表示订单取消成功

int SqlFuns::cancelOrders(QString orderId)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("orders");													//	指向orders表
	model.setFilter("orderId = " + formal(orderId));							//	按照orderId检索数据库orders表
	model.select();
	QSqlRecord record = model.record(0);										//	选择筛选结果中第一条记录（程序未出错情况下有且仅有一条记录）
	int isOrderPaid = record.value("isPaid").toInt();							//	将记录中isPaid值转换为INT
	if (isOrderPaid != 0)														//	订单已支付
		return -1;
	delete_occupied_seats(orderId);												//	订单未支付：删除已占用的座位
	model.removeRow(0);															//	删除订单记录
	return 1;																	//	回传成功取消的标志
}

//	将未支付订单中预占取的座位释放
//	未支付的订单，超过三十分钟未支付，订单将删除，座位将被释放；
//	未支付的订单，用户自行取消，座位将被释放
//	传入值为一个字符串，代表订单唯一ID

void SqlFuns::delete_occupied_seats(QString orderId)
{
	QSqlTableModel model;														//	新建QTSQL数据库model
	model.setTable("orders");													//	指向orders表
	orderId = formal(orderId);
	model.setFilter("orderId = " + orderId);									//	按照orderId检索数据库orders表
	model.select();
	QSqlRecord record = model.record(0);										//	选择检索结果中第一条记录（程序未出错情况下有且仅有一条记录）
	QString orderMovie = record.value("movieId").toString();					//	将记录中movieId值转换为字符串
	int seat1Pos = record.value("seat1pos").toInt();							//	将记录中第一个座位的位置转换为INT
	int seat2Pos = record.value("seat2pos").toInt();							//	将记录中第二个座位的位置转换为INT
	int seat3Pos = record.value("seat3pos").toInt();							//	将记录中第三个座位的位置转换为INT
	model.clear();
	model.setTable("movie");													//	指向movie表
	orderMovie = formal(orderMovie);
	model.setFilter("movieId = " + orderMovie);									//	按照movieId检索数据库movie表
	model.select();
	record = model.record(0);													//	选择检索结果中第一条记录（程序未出错情况下有且仅有一条记录）
	QString seats_map = record.value("seatMaps").toString();
	int column = record.value("coloumNum").toInt();
	int row = record.value("rowNum").toInt();
	int xBias = (21 - column) / 2;												//	为居中显示，x轴偏移量
	int yBias = (12 - row) / 2;													//	为居中显示，y轴偏移量
	int yPos = (seat1Pos % 100) - 1, xPos = (seat1Pos / 100) - 1;				//	四位数字转换为唯一编号
	seat1Pos = ((yPos + yBias) * 21) + (xPos + xBias);
	seats_map[seat1Pos] = '0';
	if (seat2Pos != 0)															//	如果第二个座位存在
	{
		yPos = seat2Pos % 100 - 1, xPos = seat2Pos / 100 - 1;					//	四位数字转换为唯一编号
		seat2Pos = (yPos + yBias) * 21 + xPos + xBias;
		seats_map[seat2Pos] = '0';
	}
	if (seat3Pos != 0)															//	如果第三个座位存在
	{
		yPos = seat3Pos % 100 - 1, xPos = seat3Pos / 100 - 1;					//	四位数字转换为唯一编号
		seat3Pos = (yPos + yBias) * 21 + xPos + xBias;
		seats_map[seat3Pos] = '0';
	}
	model.clear();
	model.setTable("movie");
	model.setFilter("movieId = " + orderMovie);
	model.select();
	model.setData(model.index(0, 19), seats_map);								//	更新本场次电影座位分布情况	
	model.submitAll();
}

//	删除逾期未支付的订单
//	未支付的订单，超过三十分钟未支付，订单将删除，座位将被释放；
//	未支付的订单，用户自行取消，座位将被释放
//	传入值为一个字符串，代表订单唯一ID

void SqlFuns::delete_outdated_orders(QString now_time, QString date)
{
	int earlist_time = returnMinute(now_time, date) - 30;
	QSqlTableModel model;
	model.setTable("orders");
	model.setFilter("isPaid = 0");
	model.select();
	for (int i = 0; i < model.rowCount(); i++)
	{
		QSqlRecord record = model.record(i);
		QString temp_time = record.value("orderId").toString();
		int string_length = temp_time.length();
		QString created_time = temp_time.mid(string_length - 6, 2) + ":" + temp_time.mid(string_length - 4, 2) + ":" + temp_time.mid(string_length - 2, 2);
		QString created_date = temp_time.mid(string_length - 14, 4) + "-" + temp_time.mid(string_length - 10, 2) + "-" + temp_time.mid(string_length - 8, 2);
		int order_created_time = returnMinute(created_time, created_date);
		if (order_created_time < earlist_time)
		{
			QString orderId = record.value("orderId").toString();
			cancelOrders(orderId);
		}
	}
}


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//												其他函数					                                  // 
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


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
	for (int i = 1970; i < year_to_int; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			day_interval = day_interval + 366;
		else day_interval = day_interval + 365;
	}
	for (int i = 1; i < month_to_int; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10) // i < 12
			day_interval = day_interval + 31;
		else
			if (i == 4 || i == 6 || i == 9 || i == 11) // i < 12
				day_interval = day_interval + 30;
			else
			{
				if ((year_to_int % 4 == 0 && year_to_int % 100 != 0) || (year_to_int % 400 == 0))
					day_interval = day_interval + 29;
				else day_interval = day_interval + 28;
			}
	}
	day_interval = day_interval + (convert_day.toInt() - 1);
	return_time_interval_by_min = return_time_interval_by_min + (day_interval * 60 * 24);
	return_time_interval_by_min = return_time_interval_by_min + (convert_hour.toInt() * 60) + convert_minute.toInt();
	return return_time_interval_by_min;
}





int SqlFuns::judgeUserOrderNumber(QString movieId)
{
	QSqlTableModel model;
	model.setTable("orders");
	model.setFilter("userId = " + formal(global_userName) + "and date = " + formal(queryMovieInfo(movieId)[2]));
	model.select();
	if (model.rowCount() > 4)
		return -1;
	return 0;
}

//判断选取的座位是否合法
//输入:电影序列号movieId，以QString字符串的形式存储；第一个座位在该场电影的位置编号，以INT形式储存；第二个座位（可选）在该场的位置编号，以INT值形式储存，如果没有则置为-1；第三个座位（可选）在该场的位置编号，以INT值形式储存，如果没有则置为-1；
int SqlFuns::judgeSeatOrder(QString movieId, int seat1pos, int seat2pos, int seat3pos)
{
	//先获取该场电影的当前可用座位分布
	//预占取座位，如果该坐标所在的座位不合法返回-1
	//占去座位后判断影院座位分布的合法性，如果不合法，撤销更改并返回-1
	//若合法则返回0
	QStringList info = queryOrderInfo(movieId);

	int now_seat_row = queryRow(info[4], info[0]);
	int now_seat_column = queryColumn(info[4], info[0]);
	int row_bias = (12 - now_seat_row) / 2;
	int column_bias = (21 - now_seat_column) / 2;
	QString now_seat_map = querySeatMap(movieId);
	int y_pos = seat1pos % 100 - 1;
	int xPos = seat1pos / 100 - 1;
	seat1pos = (y_pos + row_bias) * 21 + column_bias + xPos;
	if (now_seat_map[seat1pos] == '0')
		now_seat_map[seat1pos] = '3';
	else return -1;
	if (seat2pos != 0)
	{
		yPos = seat2pos % 100 - 1;
		xPos = seat2pos / 100 - 1;
		seat2pos = (yPos + row_bias) * 21 + column_bias + xPos;
		if (now_seat_map[seat2pos] == '0')
			now_seat_map[seat2pos] = '3';
		else return -1;

	}
	if (seat3pos != 0)
	{
		yPos = seat3pos % 100 - 1;
		xPos = seat3pos / 100 - 1;
		seat3pos = (yPos + row_bias) * 21 + column_bias + xPos;
		if (now_seat_map[seat3pos] == '0')
			now_seat_map[seat3pos] = '3';
		else return -1;
	}
	int index;
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 21; j++)
		{
			index = i * 21 + j;
			if (now_seat_map[index] == '3')
			{
				if (j == 0 && (now_seat_map[index + 1] == '1' || now_seat_map[index + 2] == '1'))
					return -1;
				else if (j == 1 && (now_seat_map[index + 1] == '1' || now_seat_map[index + 2] == '1' || now_seat_map[index - 1] == '1'))
					return -1;
				else if (j == 20 && (now_seat_map[index - 1] == '1' || now_seat_map[index - 2] == '1'))
					return -1;
				else if (j == 19 && (now_seat_map[index + 1] == '1' || now_seat_map[index - 1] == '1' || now_seat_map[index - 2] == '1'))
					return -1;
				else if (now_seat_map[index + 1] == '1' || now_seat_map[index + 2] == '1' || now_seat_map[index - 1] == '1' || now_seat_map[index - 2] == '1')
					return -1;
			}
		}
	return 0;
}

int SqlFuns::intelligentSeatsRecommend(QString movieId, int num)
{
	QStringList info = queryOrderInfo(movieId);
	QString seatMap = querySeatMap(movieId);
	QStringList seatMapTrans;
	int row = queryRow(info[4], info[0]);
	int column = queryColumn(info[4], info[0]);
	int edge = row > column ? row : column;
	for (int i = 0; i < 12; i++)
	{
		QString line;
		for (int j = 0; j < 21; j++)
			line = line + seatMap[i * 21 + j];
		seatMapTrans.append(line);
	}
	int curRow = 5, curColumn = 10;
	int length = 1, flg = 0, pos;
	for (int i = 0; i < edge * edge - 1 && i < 144;)
	{
		for (int j = 0; j < 9; j++)
			for (int k = 0; k < length; k++)
			{
				pos = seatTrans(row, column, curRow, curColumn);
				if (num == 1)
					flg = judgeSeatOrder(movieId, pos, 0, 0);
				else if (num == 2)
					flg = judgeSeatOrder(movieId, pos, pos + 100, 0);
				else
					flg = judgeSeatOrder(movieId, pos, pos + 100, pos - 100);

				if (flg == 0)
					return pos;

				switch (j % 9)
				{
				case 0:
					curRow = 5 + length;
					break;
				case 1:
					curColumn++;
					break;
				case 2:
				case 3:
					curRow--;
					break;
				case 4:
				case 5:
					curColumn--;
					break;
				case 6:
				case 7:
					curRow++;
					break;
				case 8:
					curColumn++;
					break;
				}
			}
		i += 8 * length;
		length++;
	}
	return -1;
}

int SqlFuns::seatTrans(int row, int column, int curRow, int curColumn)
{
	int pos;
	int columnBias = (21 - column) / 2;
	int rowBias = (12 - row) / 2;
	pos = (curRow - rowBias + 1) + (curColumn - columnBias + 1) * 100;
	return pos;
}

int SqlFuns::warning_confilcted_orders(QString movieId)
{
	QSqlTableModel model;
	model.setTable("movie");
	movieId = formal(movieId);
	model.setFilter("movieId = " + movieId);
	model.select();
	QSqlRecord record = model.record(0);
	QString this_film_start_time = record.value("startTime").toString();
	QString this_film_end_time = record.value("endTime").toString();
	QString this_film_date = record.value("date").toString();
	model.clear();
	QString userId = formal(global_userName);
	model.setTable("orders");
	model.setFilter("userId = " + userId);
	model.select();
	int item_num = model.rowCount();
	for (int i = 0; i < item_num; i++)
	{
		QSqlRecord record = model.record(i);
		QString iter_order_date = record.value("date").toString();
		QString iter_order_start_time = record.value("startTime").toString();
		QString iter_order_end_time = record.value("endTime").toString();
		QString iter_movieId = record.value("movieId").toString();
		if (iter_movieId == movieId)
			return 1;
		if (iter_order_date == this_film_date)
		{
			if (iter_order_start_time >= this_film_start_time && iter_order_start_time <= this_film_end_time)
				return 1;
			if (iter_order_start_time <= this_film_start_time && iter_order_end_time >= this_film_start_time)
				return 1;
		}
	}
	return 0;
}

int SqlFuns::queryIsDiscount(QString movieId)
{
	// 用户操作
	// 查询订单是否优惠 用于订单购买
	QSqlTableModel model;
	model.setTable("movie");
	movieId = formal(movieId);
	model.setFilter("movieId = " + movieId);
	model.select();
	return model.record(0).value("isDiscount").toInt();
}

void SqlFuns::checkIsPlayed()
{
	QSqlTableModel model;
	QDate curDate = QDate::currentDate();
	QTime curTime = QTime::currentTime();

	model.setTable("movie");
	model.select();
	for (int i = 0; i < model.rowCount(); i++)
	{
		if (model.record(i).value("date").toString() <= curDate.toString("yyyy-MM-dd") && model.record(i).value("startTime").toString() <= curDate.toString("hh:mm:ss"))
			model.setData(model.index(i, 8), 1);
	}
}

int SqlFuns::addNewFilmJudge(QString hallId, QString start_time, \
	QString end_time, QString film_date)
{
	// 0 合法 1 冲突 2 不建议
	QSqlTableModel* model = new QSqlTableModel;
	model->setTable("movie");
	int start_time_to_int = returnMinute(start_time, film_date);
	int end_time_to_int = returnMinute(end_time, film_date);
	int entry_begin_time = start_time_to_int - 10;
	int exit_end_time = end_time_to_int + 10;
	QString cinema = queryCinema(global_userName);
	cinema = formal(cinema);
	QString ord;
	ord = "cinema = " + cinema;
	if (hallId != "")
	{
		hallId = formal(hallId);
		ord = ord + "and hall = " + hallId;
	}
	model->setFilter(ord);
	model->select();
	int item_num = model->rowCount();
	for (int i = 0; i < item_num; i++)
	{
		// 同一个影厅开始结束相差10分钟
		QSqlRecord record = model->record(i);
		int exist_film_entry_begin = returnMinute(record.value("startTime").toString(), record.value("date").toString()) - 10;
		int exist_film_exit_end = returnMinute(record.value("endtime").toString(), record.value("date").toString()) + 10;
		if (entry_begin_time >= exist_film_entry_begin && entry_begin_time <= exist_film_exit_end)
			return 1;
		if (entry_begin_time <= exist_film_entry_begin && exit_end_time >= exist_film_entry_begin)
			return 1;
	}
	ord = "cinema = " + cinema;
	model->clear();
	model->setTable("movie");
	model->setFilter(ord);
	model->select();
	item_num = model->rowCount();
	for (int i = 0; i < item_num; i++)
	{
		QSqlRecord record = model->record(i);
		int exist_film_start_time = returnMinute(record.value("startTime").toString(), record.value("date").toString());
		int exist_film_end_time = returnMinute(record.value("endTime").toString(), record.value("date").toString());
		if (abs(exist_film_start_time - start_time_to_int) <= 10)
			return 2;
		if (abs(exist_film_end_time - end_time_to_int) <= 10)
			return 2;
		if (abs(exist_film_end_time - start_time_to_int) <= 20)
			return 2;
		if (abs(end_time_to_int - exist_film_start_time) <= 20)
			return 2;
	}
	return 0;
}