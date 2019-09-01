#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <sqlfuns.h>
#include <QTimer>
#include <QDateTime>
#include <QAbstractItemView>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    void updateMovieTable();
    ~AdminMainWindow();

private:
    Ui::AdminMainWindow *ui;

private slots:
    void on_pushButton_changeUser_clicked();
    void receiveLogin();
    void timerUpdate();
    void infoChangeDone();

    void on_pushButton_editPersonalInfo_clicked();

    void on_pushButton_addNewMovie_clicked();

    void on_pushButton_addNewHall_clicked();

signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
    void showAddNewFilmWindow();
};

#endif // ADMINMAINWINDOW_H
