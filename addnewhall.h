#ifndef ADDNEWHALL_H
#define ADDNEWHALL_H

#include <QWidget>
#include "sqlfuns.h"

namespace Ui {
class AddNewHall;
}

class AddNewHall : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewHall(QWidget *parent = nullptr);
    void showSeat(QString seatMap);
    ~AddNewHall();
private slots:
    void on_comboBox_type_currentTextChanged(const QString &arg1);

    void on_pushButton_confirm_clicked();

private:
    Ui::AddNewHall *ui;

private slots:
    void receiveAddNewHall();

signals:
    void hallAdded();
};

#endif // ADDNEWHALL_H
