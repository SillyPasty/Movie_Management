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
    //  注册
    void registerUser(QString userId, QString password, QString name, QString sex, QString phonenumber, QString email, int isAdmin, QString cinema);

    //  添加电影 影厅
    void addNewFilm(QString movieId, QString name, QString cinema, QString hall, QString startTime, QString endTime, int length, float price, int ticketRemain, QString type, int isRecommened, QString date, QString seatMaps, QString language);
    void addNewHall(QString hallId, QString cinema, int totalseats, int row, int column, QString seatMap, QString type);
    void addNewOrder(QString movieId, int seats1pos, int seats2pos, int seat3pos, QString curTimeDate);

    //  更改信息
    void changeUserInfo(QString email, QString passwd, QString phoneNum);
    float changeUserBalance(float amount);
    void changePaymentStage(QString orderId);

    //  查询函数
    QString queryPassword(QString userName); //
    int queryIsadmin(QString userName);      //  查询用户是否为管理院
    int queryHallSeates(QString hallId);
    QString queryCinema(QString userId);
    QString queryMovieName(QString movieId);
    QSqlTableModel *queryAdminMovie(QString movieName, QString hallId);
    QSqlTableModel *queryAdminHall(QString hallId);
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
    int *querySeates(QString orderId);
    QString queryType(QString hallId, QString cinema);
    QString queryHallSeatMap(QString hallId);
    float queryPrice(QString movieId);
    float queryBalance();

    SqlFuns();
};

#endif // SQLFUNS_H
