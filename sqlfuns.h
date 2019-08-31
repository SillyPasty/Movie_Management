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

    //
    void createTables();

    //  TEXT格式化
    QString formal(QString str);
    //  注册
    void registerUser(QString userId, QString password, QString name, QString sex, QString phonenumber, QString email, int isAdmin, QString cinema);

    //  查询函数
    QString queryPassword(QString userName);
    int queryIsadmin(QString userName);
    SqlFuns();
};

#endif // SQLFUNS_H
