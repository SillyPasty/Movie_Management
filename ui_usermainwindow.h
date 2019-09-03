/********************************************************************************
** Form generated from reading UI file 'usermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMAINWINDOW_H
#define UI_USERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QLabel *label_userInfo;
    QLabel *label_currentTime;
    QTabWidget *tabWidget;
    QWidget *tab_search;
    QPushButton *pushButton_buy;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_movieName;
    QLabel *label_4;
    QComboBox *comboBox_cinema;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_13;
    QComboBox *comboBox_language;
    QLabel *label_12;
    QComboBox *comboBox_type;
    QPushButton *pushButton_search;
    QTableView *tableView_movie;
    QFrame *line_2;
    QWidget *tab_towUp;
    QPushButton *pushButton_confirmTopUp;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_currentBalance;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *lineEdit_topUp;
    QLabel *label_7;
    QWidget *tab_order;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLineEdit *lineEdit_movieName_2;
    QLabel *label_9;
    QLineEdit *lineEdit_cinemaName_2;
    QPushButton *pushButton_search_2;
    QTableView *tableView_orders;
    QFrame *line_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_pay;
    QPushButton *pushButton_cancelOrder;
    QWidget *tab_personalInfo;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_phone;
    QLabel *label_8;
    QLabel *label_email;
    QLabel *label_10;
    QLabel *label_password;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_editPersonalInfo;
    QPushButton *pushButton_changeUser;
    QPushButton *pushButton_exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserMainWindow)
    {
        if (UserMainWindow->objectName().isEmpty())
            UserMainWindow->setObjectName(QStringLiteral("UserMainWindow"));
        UserMainWindow->resize(885, 645);
        centralWidget = new QWidget(UserMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 591, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 2);

        label_userInfo = new QLabel(gridLayoutWidget);
        label_userInfo->setObjectName(QStringLiteral("label_userInfo"));

        gridLayout->addWidget(label_userInfo, 0, 0, 1, 1);

        label_currentTime = new QLabel(gridLayoutWidget);
        label_currentTime->setObjectName(QStringLiteral("label_currentTime"));

        gridLayout->addWidget(label_currentTime, 0, 1, 1, 1);

        tabWidget = new QTabWidget(gridLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_search = new QWidget();
        tab_search->setObjectName(QStringLiteral("tab_search"));
        pushButton_buy = new QPushButton(tab_search);
        pushButton_buy->setObjectName(QStringLiteral("pushButton_buy"));
        pushButton_buy->setGeometry(QRect(480, 370, 80, 20));
        layoutWidget = new QWidget(tab_search);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 551, 351));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_movieName = new QLineEdit(layoutWidget);
        lineEdit_movieName->setObjectName(QStringLiteral("lineEdit_movieName"));

        horizontalLayout->addWidget(lineEdit_movieName);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        comboBox_cinema = new QComboBox(layoutWidget);
        comboBox_cinema->setObjectName(QStringLiteral("comboBox_cinema"));

        horizontalLayout->addWidget(comboBox_cinema);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_6->addWidget(label_13);

        comboBox_language = new QComboBox(layoutWidget);
        comboBox_language->setObjectName(QStringLiteral("comboBox_language"));

        horizontalLayout_6->addWidget(comboBox_language);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_6->addWidget(label_12);

        comboBox_type = new QComboBox(layoutWidget);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout_6->addWidget(comboBox_type);


        verticalLayout_2->addLayout(horizontalLayout_6);


        horizontalLayout_7->addLayout(verticalLayout_2);

        pushButton_search = new QPushButton(layoutWidget);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        horizontalLayout_7->addWidget(pushButton_search);


        verticalLayout_5->addLayout(horizontalLayout_7);

        tableView_movie = new QTableView(layoutWidget);
        tableView_movie->setObjectName(QStringLiteral("tableView_movie"));

        verticalLayout_5->addWidget(tableView_movie);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        tabWidget->addTab(tab_search, QString());
        tab_towUp = new QWidget();
        tab_towUp->setObjectName(QStringLiteral("tab_towUp"));
        pushButton_confirmTopUp = new QPushButton(tab_towUp);
        pushButton_confirmTopUp->setObjectName(QStringLiteral("pushButton_confirmTopUp"));
        pushButton_confirmTopUp->setGeometry(QRect(330, 240, 80, 20));
        layoutWidget1 = new QWidget(tab_towUp);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 60, 191, 131));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_currentBalance = new QLineEdit(layoutWidget1);
        lineEdit_currentBalance->setObjectName(QStringLiteral("lineEdit_currentBalance"));

        horizontalLayout_2->addWidget(lineEdit_currentBalance);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);

        lineEdit_topUp = new QLineEdit(layoutWidget1);
        lineEdit_topUp->setObjectName(QStringLiteral("lineEdit_topUp"));

        horizontalLayout_3->addWidget(lineEdit_topUp);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab_towUp, QString());
        tab_order = new QWidget();
        tab_order->setObjectName(QStringLiteral("tab_order"));
        layoutWidget2 = new QWidget(tab_order);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 561, 351));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_4->addWidget(label_11);

        lineEdit_movieName_2 = new QLineEdit(layoutWidget2);
        lineEdit_movieName_2->setObjectName(QStringLiteral("lineEdit_movieName_2"));

        horizontalLayout_4->addWidget(lineEdit_movieName_2);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEdit_cinemaName_2 = new QLineEdit(layoutWidget2);
        lineEdit_cinemaName_2->setObjectName(QStringLiteral("lineEdit_cinemaName_2"));

        horizontalLayout_4->addWidget(lineEdit_cinemaName_2);

        pushButton_search_2 = new QPushButton(layoutWidget2);
        pushButton_search_2->setObjectName(QStringLiteral("pushButton_search_2"));

        horizontalLayout_4->addWidget(pushButton_search_2);


        verticalLayout->addLayout(horizontalLayout_4);

        tableView_orders = new QTableView(layoutWidget2);
        tableView_orders->setObjectName(QStringLiteral("tableView_orders"));

        verticalLayout->addWidget(tableView_orders);

        line_3 = new QFrame(layoutWidget2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        layoutWidget3 = new QWidget(tab_order);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(400, 380, 168, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_pay = new QPushButton(layoutWidget3);
        pushButton_pay->setObjectName(QStringLiteral("pushButton_pay"));

        horizontalLayout_5->addWidget(pushButton_pay);

        pushButton_cancelOrder = new QPushButton(layoutWidget3);
        pushButton_cancelOrder->setObjectName(QStringLiteral("pushButton_cancelOrder"));

        horizontalLayout_5->addWidget(pushButton_cancelOrder);

        tabWidget->addTab(tab_order, QString());
        tab_personalInfo = new QWidget();
        tab_personalInfo->setObjectName(QStringLiteral("tab_personalInfo"));
        layoutWidget4 = new QWidget(tab_personalInfo);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(51, 51, 211, 141));
        gridLayout_3 = new QGridLayout(layoutWidget4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_phone = new QLabel(layoutWidget4);
        label_phone->setObjectName(QStringLiteral("label_phone"));

        gridLayout_3->addWidget(label_phone, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        label_email = new QLabel(layoutWidget4);
        label_email->setObjectName(QStringLiteral("label_email"));

        gridLayout_3->addWidget(label_email, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget4);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_password = new QLabel(layoutWidget4);
        label_password->setObjectName(QStringLiteral("label_password"));

        gridLayout_3->addWidget(label_password, 2, 1, 1, 1);

        layoutWidget5 = new QWidget(tab_personalInfo);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(260, 100, 124, 91));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_editPersonalInfo = new QPushButton(layoutWidget5);
        pushButton_editPersonalInfo->setObjectName(QStringLiteral("pushButton_editPersonalInfo"));

        verticalLayout_4->addWidget(pushButton_editPersonalInfo);

        pushButton_changeUser = new QPushButton(layoutWidget5);
        pushButton_changeUser->setObjectName(QStringLiteral("pushButton_changeUser"));

        verticalLayout_4->addWidget(pushButton_changeUser);

        tabWidget->addTab(tab_personalInfo, QString());

        gridLayout->addWidget(tabWidget, 2, 0, 1, 2);

        pushButton_exit = new QPushButton(centralWidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(630, 520, 80, 20));
        UserMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 21));
        UserMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UserMainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        UserMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UserMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UserMainWindow->setStatusBar(statusBar);

        retranslateUi(UserMainWindow);
        QObject::connect(pushButton_exit, SIGNAL(clicked()), UserMainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(UserMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserMainWindow)
    {
        UserMainWindow->setWindowTitle(QApplication::translate("UserMainWindow", "UserMainWindow", Q_NULLPTR));
        label_userInfo->setText(QApplication::translate("UserMainWindow", "TextLabel", Q_NULLPTR));
        label_currentTime->setText(QApplication::translate("UserMainWindow", "TextLabel", Q_NULLPTR));
        pushButton_buy->setText(QApplication::translate("UserMainWindow", "\350\264\255\344\271\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("UserMainWindow", "\347\224\265\345\275\261\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("UserMainWindow", "\345\275\261\351\231\242\345\220\215", Q_NULLPTR));
        label_13->setText(QApplication::translate("UserMainWindow", "\350\257\255 \350\250\200", Q_NULLPTR));
        comboBox_language->clear();
        comboBox_language->insertItems(0, QStringList()
         << QApplication::translate("UserMainWindow", "\345\205\250\351\203\250", Q_NULLPTR)
         << QApplication::translate("UserMainWindow", "\345\233\275\350\257\255", Q_NULLPTR)
         << QApplication::translate("UserMainWindow", "\350\213\261\346\226\207", Q_NULLPTR)
         << QApplication::translate("UserMainWindow", "\345\205\266\344\273\226", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("UserMainWindow", "\347\261\273  \345\236\213", Q_NULLPTR));
        pushButton_search->setText(QApplication::translate("UserMainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_search), QApplication::translate("UserMainWindow", "\346\237\245\350\257\242\350\264\255\344\271\260", Q_NULLPTR));
        pushButton_confirmTopUp->setText(QApplication::translate("UserMainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        label->setText(QApplication::translate("UserMainWindow", "\345\275\223\345\211\215\344\275\231\351\242\235", Q_NULLPTR));
        label_5->setText(QApplication::translate("UserMainWindow", "\345\205\203", Q_NULLPTR));
        label_6->setText(QApplication::translate("UserMainWindow", "   \345\205\205\345\200\274 ", Q_NULLPTR));
        label_7->setText(QApplication::translate("UserMainWindow", "\345\205\203", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_towUp), QApplication::translate("UserMainWindow", "\350\264\246\346\210\267\345\205\205\345\200\274", Q_NULLPTR));
        label_11->setText(QApplication::translate("UserMainWindow", "\347\224\265\345\275\261\345\220\215", Q_NULLPTR));
        label_9->setText(QApplication::translate("UserMainWindow", "\345\275\261\351\231\242\345\220\215", Q_NULLPTR));
        pushButton_search_2->setText(QApplication::translate("UserMainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_pay->setText(QApplication::translate("UserMainWindow", "\344\273\230\346\254\276", Q_NULLPTR));
        pushButton_cancelOrder->setText(QApplication::translate("UserMainWindow", "\345\217\226\346\266\210\350\256\242\345\215\225", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_order), QApplication::translate("UserMainWindow", "\350\256\242\345\215\225\344\277\241\346\201\257", Q_NULLPTR));
        label_2->setText(QApplication::translate("UserMainWindow", "\347\224\265\350\257\235", Q_NULLPTR));
        label_phone->setText(QApplication::translate("UserMainWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("UserMainWindow", "\351\202\256\347\256\261", Q_NULLPTR));
        label_email->setText(QApplication::translate("UserMainWindow", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("UserMainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        label_password->setText(QApplication::translate("UserMainWindow", "TextLabel", Q_NULLPTR));
        pushButton_editPersonalInfo->setText(QApplication::translate("UserMainWindow", "\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_changeUser->setText(QApplication::translate("UserMainWindow", "\345\210\207\346\215\242\347\224\250\346\210\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_personalInfo), QApplication::translate("UserMainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("UserMainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserMainWindow: public Ui_UserMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMAINWINDOW_H
