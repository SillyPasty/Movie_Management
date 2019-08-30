#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    ~AdminMainWindow();

private:
    Ui::AdminMainWindow *ui;

private slots:
    void on_pushButton_changeUser_clicked();
    void receiveLogin();
    void timerUpdate();

    void on_pushButton_editPersonalInfo_clicked();

signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
};

#endif // ADMINMAINWINDOW_H
