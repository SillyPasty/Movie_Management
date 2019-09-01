#ifndef INFOCHANGE_H
#define INFOCHANGE_H

#include <QDialog>
#include "sqlfuns.h"

namespace Ui {
class InfoChange;
}

class InfoChange : public QDialog
{
    Q_OBJECT

public:
    explicit InfoChange(QWidget *parent = nullptr);
    ~InfoChange();

private:
    Ui::InfoChange *ui;

private slots:
    void receiveInfoChange();
    void on_pushButton_confirm_clicked();

signals:
    void infoChanged();
};

#endif // INFOCHANGE_H
