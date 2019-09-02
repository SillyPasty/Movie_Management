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
    QWidget *layoutWidget;
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
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QLineEdit *lineEdit_type;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QDateEdit *dateEdit_date;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QTimeEdit *timeEdit_startTime;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QTimeEdit *timeEdit_endTime;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QComboBox *comboBox_language;
    QCheckBox *checkBox_isRecommened;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *AddNewFilm)
    {
        if (AddNewFilm->objectName().isEmpty())
            AddNewFilm->setObjectName(QStringLiteral("AddNewFilm"));
        AddNewFilm->resize(313, 384);
        label_test = new QLabel(AddNewFilm);
        label_test->setObjectName(QStringLiteral("label_test"));
        label_test->setGeometry(QRect(0, 170, 54, 12));
        layoutWidget = new QWidget(AddNewFilm);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 20, 201, 293));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_8->addWidget(label);

        lineEdit_name = new QLineEdit(layoutWidget);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout_8->addWidget(lineEdit_name);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_7->addWidget(label_2);

        lineEdit_cinema = new QLineEdit(layoutWidget);
        lineEdit_cinema->setObjectName(QStringLiteral("lineEdit_cinema"));

        horizontalLayout_7->addWidget(lineEdit_cinema);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_2->addWidget(label_10);

        lineEdit_price = new QLineEdit(layoutWidget);
        lineEdit_price->setObjectName(QStringLiteral("lineEdit_price"));

        horizontalLayout_2->addWidget(lineEdit_price);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        comboBox_hall = new QComboBox(layoutWidget);
        comboBox_hall->setObjectName(QStringLiteral("comboBox_hall"));

        horizontalLayout_6->addWidget(comboBox_hall);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout->addWidget(label_7);

        lineEdit_type = new QLineEdit(layoutWidget);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));

        horizontalLayout->addWidget(lineEdit_type);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        dateEdit_date = new QDateEdit(layoutWidget);
        dateEdit_date->setObjectName(QStringLiteral("dateEdit_date"));

        horizontalLayout_5->addWidget(dateEdit_date);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        timeEdit_startTime = new QTimeEdit(layoutWidget);
        timeEdit_startTime->setObjectName(QStringLiteral("timeEdit_startTime"));

        horizontalLayout_4->addWidget(timeEdit_startTime);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        timeEdit_endTime = new QTimeEdit(layoutWidget);
        timeEdit_endTime->setObjectName(QStringLiteral("timeEdit_endTime"));

        horizontalLayout_3->addWidget(timeEdit_endTime);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_10->addWidget(label_8);

        comboBox_language = new QComboBox(layoutWidget);
        comboBox_language->setObjectName(QStringLiteral("comboBox_language"));

        horizontalLayout_10->addWidget(comboBox_language);


        verticalLayout->addLayout(horizontalLayout_10);

        checkBox_isRecommened = new QCheckBox(layoutWidget);
        checkBox_isRecommened->setObjectName(QStringLiteral("checkBox_isRecommened"));

        verticalLayout->addWidget(checkBox_isRecommened);

        layoutWidget1 = new QWidget(AddNewFilm);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(80, 320, 168, 22));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        pushButton_confirm = new QPushButton(layoutWidget1);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout_9->addWidget(pushButton_confirm);

        pushButton_cancel = new QPushButton(layoutWidget1);
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
        label_7->setText(QApplication::translate("AddNewFilm", "\347\247\215    \347\261\273", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddNewFilm", "\346\227\245    \346\234\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddNewFilm", "\345\274\200\345\247\213\346\227\266\351\227\264", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddNewFilm", "\347\273\223\346\235\237\346\227\266\351\227\264", Q_NULLPTR));
        label_8->setText(QApplication::translate("AddNewFilm", "\350\257\255    \350\250\200", Q_NULLPTR));
        comboBox_language->clear();
        comboBox_language->insertItems(0, QStringList()
         << QApplication::translate("AddNewFilm", "\345\233\275\350\257\255", Q_NULLPTR)
         << QApplication::translate("AddNewFilm", "\350\213\261\346\226\207", Q_NULLPTR)
         << QApplication::translate("AddNewFilm", "\345\205\266\344\273\226", Q_NULLPTR)
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
