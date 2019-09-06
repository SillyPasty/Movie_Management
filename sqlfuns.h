#ifndef SQLFUNS_H
#define SQLFUNS_H
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <algorithm>

extern QString global_userName;


class SqlFuns
{
public:

// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//                          数据库初始化函数区：连接数据库并建立所需的五个数据表文件						   //
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

    bool connect(const QString& dbName);										//  连接数据库
    void createTables();														//  初始化Table


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//                               添加函数区：根据传入的数据向数据库中添加新的元素							  //
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

    void registerUser(QString userId, QString password, QString name, 			//	注册新用户（包括管理员）
        QString sex, QString phonenumber, QString email, int isAdmin,
        QString cinema);

    void addNewFilm(QString movieId, QString name, QString cinema,			//	添加新电影场次
        QString hall, QString startTime, QString endTime, int length,
        float price, int ticketRemain, QString type, int isRecommened,
        QString date, QString seatMaps, QString language, int isDiscount);
    void addNewHall(QString hallId, QString cinema, int totalseats,			//	添加新影厅
        int row, int column, QString seatMap, QString type);
    void addNewHallTemplate();													//	添加新影厅模板
    QString addNewOrder(QString movieId, int seats1pos, int seats2pos,		//	创建新订单
        int seat3pos, QString curTimeDate, float price);


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//          查询函数区：以query为开头的函数，根据提供的信息或全局变量用户名在数据库中查询需要的数据并返回         //
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

    QString getHallId();
    QString queryPassword(QString userName); 									//	查询密码
    int queryIsadmin(QString userName);     									//  查询是否为管理员
    int queryHallSeates(QString hallId);
    QString queryCinema(QString userId);
    QString queryMovieName(QString movieId);
    QString querySeatMap(QString movieId);
    QSqlTableModel* queryAdminMovie(QString movieName, QString hallId);
    QSqlTableModel* queryAdminHall(QString hallId);
    QSqlTableModel* queryAdminOrder(QString movieName, QString userId,
    QString startDate, QString endDate, int isPlayed);
    QSqlTableModel* queryUserMovie(QString movieName, QString cinema,
    QString type, QString language);
    QSqlTableModel* queryUserOrder(QString movieName, QString cinema);
    //  ????
    int queryRow(QString hallId, QString cinema);
    int queryColumn(QString hallId, QString cinema);
    //  ????
    QStringList queryHallId(QString cinema);
    QStringList queryEmailPhonePsd(QString userId);
    QStringList queryType();
    QStringList queryCinema();
    QStringList queryOrderInfo(QString movieId);
    QStringList queryHallTemplateInfo();              //  查询全部type的影厅模板
    QStringList queryHallTemplateInfo(QString type);  //  按照type查询影厅模板信息
    QStringList queryMovieInfo(QString movieId);
    int* querySeates(QString orderId);
    QString queryType(QString hallId, QString cinema);
    QString queryHallSeatMap(QString hallId);
    float queryPrice(QString movieId);
    float queryBalance();
    int addNewFilmJudge(QString hallId, QString start_time, QString end_time, QString film_date);
    int queryIsDiscount(QString movieId);
    void checkIsPlayed();


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//          修改函数区：根据提供的信息或全局变量用户名在数据库中查询需要的数据，如果需要则返回					  //
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//

    //  删除订单，释放被占用座位，删除逾期期未支付订单
    int cancelOrders(QString orderId);
    void delete_occupied_seats(QString orderId);
    void delete_outdated_orders(QString now_time, QString date);

    //  更改信息
    void changeUserInfo(QString email, QString passwd, QString phoneNum);
    float changeUserBalance(float amount);
    void changePaymentStage(QString orderId, int num, float price);
    void updateSeatMap(QString movieId, QString seatMap);


// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
//																										  //
//												其他函数					                               //
//																										  //
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//


    int seatTrans(int row, int column, int curRow, int curColumn);
    //  判断座位合法性、判断订单合法性
    int judgeSeatOrder(QString movieId, int seat1pos, int seat2pos, int seat3pos);
    int judgeUserOrderNumber(QString date);
    int warning_confilcted_orders(QString movieId);

    //	智能座位推荐
    int intelligentSeatsRecommend(QString movieId, int num);
    QString formal(QString str);												//  TEXT规范化
    int returnMinute(QString time_to_convert, QString date_to_convert);			//	计算从1970-01-01 00:00开始经过的分钟数
    SqlFuns();
};

#endif // SQLFUNS_H
