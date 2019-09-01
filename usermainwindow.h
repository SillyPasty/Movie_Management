#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QMainWindow>
#include "sqlfuns.h"

namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = nullptr);
    ~UserMainWindow();

private:
    Ui::UserMainWindow *ui;

private slots:
    void on_pushButton_changeUser_clicked();
    void receiveLogin();
    void timerUpdate();
    void infoChangeDone();

    void on_pushButton_editPersonalInfo_clicked();

signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
};

#endif // USERMAINWINDOW_H
