#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>
#include <sqlfuns.h>
#include <QTimer>
#include <QDateTime>
#include <QAbstractItemView>
#include <QTableWidgetItem>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    void updateMovieTable(QSqlTableModel *model);
    void updateHallTable(QSqlTableModel *model);
    void updateOrdersTable(QSqlTableModel *model);
    void showSeat(QString seatMap);
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
    void on_pushButton_search_2_clicked();
    void on_comboBox_hall_currentTextChanged(const QString &arg1);
    void on_pushButton_search_clicked();
    void receiveMovieInfoChange();
    void receiveHallAdded();
    void on_tableView_currentHall_clicked(const QModelIndex &index);
    void on_pushButton_viewDetail_clicked();

signals:
    void showLoginWindow();
    void timeout();
    void showInfoChangeWindow();
    void showAddNewFilmWindow();
    void showAddNewHallWindow();
    void showMovieDetail(QString movieId);
};

#endif // ADMINMAINWINDOW_H
