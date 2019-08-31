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

    //  添加电影
    void addNewFilm(QString movieId, QString name, QString cinema, QString hall, QString startTime, QString endTime, int length, float price, int ticketRemain, QString type, int isRecommened, QString date, QString seatMaps);
    //  查询函数
    QString queryPassword(QString userName); //
    int queryIsadmin(QString userName);      //  查询用户是否为管理院
    int queryHallSeates(QString hallId);
    QString queryCinema(QString userId);

    QStringList queryHallId(QString cinema);     //  返回列表

    QString queryHallSeatMap(QString hallId);
    SqlFuns();
};

#endif // SQLFUNS_H
