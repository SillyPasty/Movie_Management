/*
 * 代码完成了对添加电影界面各项配置的实现，与管理员用户和数据库进行了交互
 * By Yubo Wang
 * Copyright 2019 Yubo Wang, Lingsong Feng, Yining Zhu.
 */


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
    void on_comboBox_hall_currentTextChanged(const QString &arg1);

private:
    Ui::AddNewFilm *ui;

signals:
    void movieInfoChange();
};

#endif // ADDNEWFILM_H
