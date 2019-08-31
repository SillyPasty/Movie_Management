#ifndef ADDNEWFILM_H
#define ADDNEWFILM_H

#include <QDialog>
#include <sqlfuns.h>

namespace Ui {
class AddNewFilm;
}

class AddNewFilm : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewFilm(QWidget *parent = nullptr);
    ~AddNewFilm();

private slots:
    void on_pushButton_confirm_clicked();
    void receiveAddNewFilm();
private:
    Ui::AddNewFilm *ui;
};

#endif // ADDNEWFILM_H
