/********************************************************************************
** Form generated from reading UI file 'infochange.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOCHANGE_H
#define UI_INFOCHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoChange
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_newEmail;
    QLabel *label;
    QLineEdit *lineEdit_newPasd;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *InfoChange)
    {
        if (InfoChange->objectName().isEmpty())
            InfoChange->setObjectName(QStringLiteral("InfoChange"));
        InfoChange->resize(284, 252);
        widget = new QWidget(InfoChange);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 70, 188, 82));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_newEmail = new QLineEdit(widget);
        lineEdit_newEmail->setObjectName(QStringLiteral("lineEdit_newEmail"));

        gridLayout->addWidget(lineEdit_newEmail, 0, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_newPasd = new QLineEdit(widget);
        lineEdit_newPasd->setObjectName(QStringLiteral("lineEdit_newPasd"));

        gridLayout->addWidget(lineEdit_newPasd, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(widget);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_confirm = new QPushButton(widget);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));

        horizontalLayout->addWidget(pushButton_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(InfoChange);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), InfoChange, SLOT(close()));

        QMetaObject::connectSlotsByName(InfoChange);
    } // setupUi

    void retranslateUi(QDialog *InfoChange)
    {
        InfoChange->setWindowTitle(QApplication::translate("InfoChange", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("InfoChange", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("InfoChange", "\346\226\260\351\202\256\347\256\261", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("InfoChange", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_confirm->setText(QApplication::translate("InfoChange", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoChange: public Ui_InfoChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOCHANGE_H
