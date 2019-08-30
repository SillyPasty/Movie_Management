/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEdit_userName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_psd;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_male;
    QRadioButton *radioButton_female;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_number;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *lineEdit_email;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_adminKey;
    QLineEdit *lineEdit_adminKey;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEdit_cinemaId;
    QCheckBox *checkBox_isAdmin;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_exit;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QStringLiteral("RegisterWindow"));
        RegisterWindow->resize(329, 313);
        widget = new QWidget(RegisterWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 40, 201, 230));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_userName = new QLineEdit(widget);
        lineEdit_userName->setObjectName(QStringLiteral("lineEdit_userName"));

        horizontalLayout_2->addWidget(lineEdit_userName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_psd = new QLineEdit(widget);
        lineEdit_psd->setObjectName(QStringLiteral("lineEdit_psd"));

        horizontalLayout_3->addWidget(lineEdit_psd);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radioButton_male = new QRadioButton(widget);
        radioButton_male->setObjectName(QStringLiteral("radioButton_male"));

        horizontalLayout->addWidget(radioButton_male);

        radioButton_female = new QRadioButton(widget);
        radioButton_female->setObjectName(QStringLiteral("radioButton_female"));

        horizontalLayout->addWidget(radioButton_female);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit_number = new QLineEdit(widget);
        lineEdit_number->setObjectName(QStringLiteral("lineEdit_number"));

        horizontalLayout_4->addWidget(lineEdit_number);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_email = new QLineEdit(widget);
        lineEdit_email->setObjectName(QStringLiteral("lineEdit_email"));

        horizontalLayout_5->addWidget(lineEdit_email);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_adminKey = new QLabel(widget);
        label_adminKey->setObjectName(QStringLiteral("label_adminKey"));

        horizontalLayout_6->addWidget(label_adminKey);

        lineEdit_adminKey = new QLineEdit(widget);
        lineEdit_adminKey->setObjectName(QStringLiteral("lineEdit_adminKey"));

        horizontalLayout_6->addWidget(lineEdit_adminKey);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEdit_cinemaId = new QLineEdit(widget);
        lineEdit_cinemaId->setObjectName(QStringLiteral("lineEdit_cinemaId"));

        horizontalLayout_7->addWidget(lineEdit_cinemaId);

        checkBox_isAdmin = new QCheckBox(widget);
        checkBox_isAdmin->setObjectName(QStringLiteral("checkBox_isAdmin"));

        horizontalLayout_7->addWidget(checkBox_isAdmin);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_confirm = new QPushButton(widget);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout_8->addWidget(pushButton_confirm);

        pushButton_exit = new QPushButton(widget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        horizontalLayout_8->addWidget(pushButton_exit);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(RegisterWindow);
        QObject::connect(pushButton_exit, SIGNAL(clicked()), RegisterWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Dialog", Q_NULLPTR));
        label_5->setText(QApplication::translate("RegisterWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterWindow", "\345\257\206  \347\240\201", Q_NULLPTR));
        radioButton_male->setText(QApplication::translate("RegisterWindow", "\347\224\267", Q_NULLPTR));
        radioButton_female->setText(QApplication::translate("RegisterWindow", "\345\245\263", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterWindow", "\347\224\265  \350\257\235", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegisterWindow", "\351\202\256  \347\256\261", Q_NULLPTR));
        label_adminKey->setText(QApplication::translate("RegisterWindow", "\345\257\206  \351\222\245", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegisterWindow", "\345\275\261\351\231\242\347\274\226\345\217\267", Q_NULLPTR));
        checkBox_isAdmin->setText(QApplication::translate("RegisterWindow", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        pushButton_confirm->setText(QApplication::translate("RegisterWindow", "\346\263\250\345\206\214", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("RegisterWindow", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
