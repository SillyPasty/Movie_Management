#ifndef SEATSSELECT_H
#define SEATSSELECT_H

#include <QWidget>
#include "sqlfuns.h"

namespace Ui {
class SeatsSelect;
}

class SeatsSelect : public QWidget
{
    Q_OBJECT

public:
    explicit SeatsSelect(QWidget *parent = nullptr);
    QString movieIdStore;
    int xAxis, yAxis;
    ~SeatsSelect();
    void showSeat(QString seatMap);
    void calAxis();

private:
    Ui::SeatsSelect *ui;

private slots:
    void receivePayment(QString movieId);
    void on_tableWidget_clicked(const QModelIndex &index);
    void on_pushButton_puchase_clicked();

    void on_radioButton_one_clicked();

    void on_radioButton_two_clicked();

    void on_radioButton_three_clicked();

signals:
    void balanceChange();
};

#endif // SEATSSELECT_H
