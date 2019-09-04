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

    void updateMovieTable(QSqlTableModel *model);
    void updateOrdersTable(QSqlTableModel *model);

    ~UserMainWindow();

private:
    Ui::UserMainWindow *ui;

private slots:
    void on_pushButton_changeUser_clicked();
    void receiveLogin();
    void receiveBalanceChange();
    void timerUpdate();
    void infoChangeDone();

    void on_pushButton_editPersonalInfo_clicked();

    void on_pushButton_confirmTopUp_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_buy_clicked();

    void on_pushButton_search_2_clicked();

    void on_pushButton_pay_clicked();

    void on_pushButton_cancelOrder_clicked();

    void orderCheck();


signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
    void showPaymentWindow(QString movieId);
};

#endif // USERMAINWINDOW_H
