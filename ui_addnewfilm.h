/********************************************************************************
** Form generated from reading UI file 'addnewfilm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWFILM_H
#define UI_ADDNEWFILM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewFilm
{
public:
    QLabel *label_test;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *lineEdit_cinema;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_10;
    QLineEdit *lineEdit_price;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *comboBox_hall;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDateEdit *dateEdit_date;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QTimeEdit *timeEdit_startTime;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QTimeEdit *timeEdit_endTime;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QComboBox *comboBox_type;
    QCheckBox *checkBox_isRecommened;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *AddNewFilm)
    {
        if (AddNewFilm->objectName().isEmpty())
            AddNewFilm->setObjectName(QStringLiteral("AddNewFilm"));
        AddNewFilm->resize(319, 346);
        label_test = new QLabel(AddNewFilm);
        label_test->setObjectName(QStringLiteral("label_test"));
        label_test->setGeometry(QRect(130, 330, 54, 12));
        widget = new QWidget(AddNewFilm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 20, 201, 263));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);

        lineEdit_name = new QLineEdit(widget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout_8->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        lineEdit_cinema = new QLineEdit(widget);
        lineEdit_cinema->setObjectName(QStringLiteral("lineEdit_cinema"));

        horizontalLayout_7->addWidget(lineEdit_cinema);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        lineEdit_price = new QLineEdit(widget);
        lineEdit_price->setObjectName(QStringLiteral("lineEdit_price"));

        horizontalLayout_2->addWidget(lineEdit_price);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        comboBox_hall = new QComboBox(widget);
        comboBox_hall->setObjectName(QStringLiteral("comboBox_hall"));

        horizontalLayout_6->addWidget(comboBox_hall);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        dateEdit_date = new QDateEdit(widget);
        dateEdit_date->setObjectName(QStringLiteral("dateEdit_date"));

        horizontalLayout_5->addWidget(dateEdit_date);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        timeEdit_startTime = new QTimeEdit(widget);
        timeEdit_startTime->setObjectName(QStringLiteral("timeEdit_startTime"));

        horizontalLayout_4->addWidget(timeEdit_startTime);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        timeEdit_endTime = new QTimeEdit(widget);
        timeEdit_endTime->setObjectName(QStringLiteral("timeEdit_endTime"));

        horizontalLayout_3->addWidget(timeEdit_endTime);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        comboBox_type = new QComboBox(widget);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout->addWidget(comboBox_type);


        verticalLayout->addLayout(horizontalLayout);

        checkBox_isRecommened = new QCheckBox(widget);
        checkBox_isRecommened->setObjectName(QStringLiteral("checkBox_isRecommened"));

        verticalLayout->addWidget(checkBox_isRecommened);

        widget1 = new QWidget(AddNewFilm);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(80, 290, 168, 22));
        horizontalLayout_9 = new QHBoxLayout(widget1);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton_confirm = new QPushButton(widget1);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout_9->addWidget(pushButton_confirm);

        pushButton_cancel = new QPushButton(widget1);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_9->addWidget(pushButton_cancel);


        retranslateUi(AddNewFilm);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), AddNewFilm, SLOT(close()));

        QMetaObject::connectSlotsByName(AddNewFilm);
    } // setupUi

    void retranslateUi(QDialog *AddNewFilm)
    {
        AddNewFilm->setWindowTitle(QApplication::translate("AddNewFilm", "Dialog", Q_NULLPTR));
        label_test->setText(QApplication::translate("AddNewFilm", "TextLabel", Q_NULLPTR));
        label->setText(QApplication::translate("AddNewFilm", "\347\224\265\345\275\261\345\220\215\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddNewFilm", "\345\275\261    \351\231\242", Q_NULLPTR));
        label_10->setText(QApplication::translate("AddNewFilm", "\344\273\267    \346\240\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddNewFilm", "\345\275\261    \345\216\205", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddNewFilm", "\346\227\245    \346\234\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddNewFilm", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddNewFilm", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddNewFilm", "\347\247\215\347\261\273", Q_NULLPTR));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("AddNewFilm", "2D", Q_NULLPTR)
         << QApplication::translate("AddNewFilm", "3D", Q_NULLPTR)
         << QApplication::translate("AddNewFilm", "4D", Q_NULLPTR)
         << QApplication::translate("AddNewFilm", "iMax", Q_NULLPTR)
        );
        checkBox_isRecommened->setText(QApplication::translate("AddNewFilm", "\346\230\257\345\220\246\346\216\250\350\215\220", Q_NULLPTR));
        pushButton_confirm->setText(QApplication::translate("AddNewFilm", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("AddNewFilm", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNewFilm: public Ui_AddNewFilm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWFILM_H
