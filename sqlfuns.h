/*
	By Silly Pasty 2019.
	本头文件包含所有涉及数据库操作的函数声明，将其置于自定义类SqlFuns中
	其中包括对四个数据库表user, movie, orders, hall，hallTemplate的新建、查询、修改、删除操作，以及其他需要调用数据库的函数，
	如判断用户选定的座位是否合法，判断管理员新增的影片是否合法等。
	其中，table为sqlite数据库中的表文件，在本程序中共使用四个表：
	user             用于存储用户和管理员的身份信息、密码等
	movie            用于存储某时段在某影院的某影厅播放的电影的信息，包括片名、上座率、选座情况、总收入等
	orders           用于存储用户建立的订单，其中包括订单指向的某一条电影记录，订单建立时间，订单购买的座位位置编号等
	hall             用于存储影院影厅的原始信息，包括所属的影院名，影厅名，影厅类型，座椅分布图等
	hallTemplate	 用于存储建立影厅时需要的影院座椅分布模板
	某些函数仅涉及单一数据库的操作，如查询等，但某些函数，如添加和删除订单，涉及多个数据库的交互
*/

#ifndef SQLFUNS_H
#define SQLFUNS_H
#include <QString>
#include <QtSql>
#include <QMessageBox>

extern QString global_userName;


class SqlFuns
{
public:
    //  连接并打开数据库
    bool connect(const QString &dbName);

    //  初始化
    void createTables();

    //  TEXT格式化
    QString formal(QString str);
    int returnMinute(QString time_to_convert, QString date_to_convert);
    //  注册
    void registerUser(QString userId, QString password, QString name, QString sex, QString phonenumber, QString email, int isAdmin, QString cinema);

    //  添加电影 影厅
    void addNewFilm(QString movieId, QString name, QString cinema, QString hall, QString startTime, QString endTime, int length, float price, int ticketRemain, QString type, int isRecommened, QString date, QString seatMaps, QString language);
    void addNewHall(QString hallId, QString cinema, int totalseats, int row, int column, QString seatMap, QString type);
    void addNewHallTemplate();
    QString addNewOrder(QString movieId, int seats1pos, int seats2pos, int seat3pos, QString curTimeDate);


    //  删除订单
    int cancelOrders(QString orderId);

    //  更改信息
    void changeUserInfo(QString email, QString passwd, QString phoneNum);
    float changeUserBalance(float amount);
    void changePaymentStage(QString orderId, int num, float price);

    QString getHallId();
    //  查询函数
    QString queryPassword(QString userName);     //	 查询用户的密码，传入参数为QString字符串格式，代表用户名，返回一个Qtring字符串，代表用户密码
    int queryIsadmin(QString userName);			 //  查询用户是否为管理员，传入参数为QString字符串格式，代表用户名，返回一个int值，0代表
    int queryHallSeates(QString hallId);		 //  管理员函数，仅在管理员界面下被调用；查询当前管理员所属的当前影院下某个影厅的座位数
												 //  传入参数为QString字符串格式，代表影厅ID，返回值为int型，代表座位数										
    
	QString queryCinema(QString userId);	     //  查询管理员对应的影院
												 //  传入参数为QString字符串格式，代表管理员名称，返回值为QString字符串，代表影院名称	
   
	QString queryMovieName(QString movieId);	 //	 	
												 //								
    QString querySeatMap(QString movieId);
    QSqlTableModel *queryAdminMovie(QString movieName, QString hallId);
    QSqlTableModel *queryAdminHall(QString hallId);
    QSqlTableModel *queryAdminOrder(QString movieName, QString userId, QString startDate, QString endDate, int isPlayed);
    QSqlTableModel *queryUserMovie(QString movieName, QString cinema, QString type, QString language);
    QSqlTableModel *queryUserOrder(QString movieName, QString cinema);
    //  查询行列
    int queryRow(QString hallId, QString cinema);
    int queryColumn(QString hallId, QString cinema);
    QStringList queryHallId(QString cinema);     //  返回列表
    QStringList queryEmailPhonePsd(QString userId);
    QStringList queryType();
    QStringList queryCinema();
    QStringList queryOrderInfo(QString movieId);
    QStringList queryHallTemplateInfo();              //  返回所有可用type列表
    QStringList queryHallTemplateInfo(QString type);  //  返回某个type的所有参数
    int *querySeates(QString orderId);
    QString queryType(QString hallId, QString cinema);
    QString queryHallSeatMap(QString hallId);
    float queryPrice(QString movieId);
    float queryBalance();
    int addNewFilmJudge(QString hallId, QString start_time, QString end_time, QString film_date);

    SqlFuns();
};

#endif // SQLFUNS_H
