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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_newEmail;
    QLabel *label;
    QLineEdit *lineEdit_newPasd;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3x;
    QLineEdit *lineEdit_phoneNum;
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
        layoutWidget = new QWidget(InfoChange);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 70, 188, 112));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_newEmail = new QLineEdit(layoutWidget);
        lineEdit_newEmail->setObjectName(QStringLiteral("lineEdit_newEmail"));

        gridLayout->addWidget(lineEdit_newEmail, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_newPasd = new QLineEdit(layoutWidget);
        lineEdit_newPasd->setObjectName(QStringLiteral("lineEdit_newPasd"));

        gridLayout->addWidget(lineEdit_newPasd, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3x = new QLabel(layoutWidget);
        label_3x->setObjectName(QStringLiteral("label_3x"));

        horizontalLayout_2->addWidget(label_3x);

        lineEdit_phoneNum = new QLineEdit(layoutWidget);
        lineEdit_phoneNum->setObjectName(QStringLiteral("lineEdit_phoneNum"));

        horizontalLayout_2->addWidget(lineEdit_phoneNum);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_confirm = new QPushButton(layoutWidget);
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
        label->setText(QApplication::translate("InfoChange", "\346\226\260\351\202\256\347\256\261", Q_NULLPTR));
        label_2->setText(QApplication::translate("InfoChange", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_3x->setText(QApplication::translate("InfoChange", "\346\226\260\347\224\265\350\257\235", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("InfoChange", "\345\217\226\346\266\210", Q_NULLPTR));
        pushButton_confirm->setText(QApplication::translate("InfoChange", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InfoChange: public Ui_InfoChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOCHANGE_H
