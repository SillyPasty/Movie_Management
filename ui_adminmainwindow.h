/********************************************************************************
** Form generated from reading UI file 'adminmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINWINDOW_H
#define UI_ADMINMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_exit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QLabel *label_userInfo;
    QLabel *label_currentTime;
    QTabWidget *tabWidget;
    QWidget *tab_search;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_movieName;
    QLabel *label_4;
    QLineEdit *lineEdit_cinemaName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QDateEdit *dateEdit_inquire01;
    QDateEdit *dateEdit_inquire02;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_isPlayed;
    QCheckBox *checkBox;
    QPushButton *pushButton_search;
    QFrame *line_2;
    QTableWidget *tableWidget_aviMovies;
    QLabel *label_totalIncome;
    QWidget *tab_towUp;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_hall;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_addNewHall;
    QFrame *line_3;
    QTableView *tableView_currentHall;
    QWidget *tab_order;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QLineEdit *lineEdit_movieName_2;
    QLabel *label_9;
    QComboBox *comboBox_hall_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_search_2;
    QPushButton *pushButton_addNewMovie;
    QTableView *tableView_movie;
    QFrame *line_4;
    QWidget *tab_personalInfo;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_phone;
    QLabel *label_8;
    QLabel *label_email;
    QLabel *label_10;
    QLabel *label_password;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_editPersonalInfo;
    QPushButton *pushButton_changeUser;
    QLabel *label_test;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMainWindow)
    {
        if (AdminMainWindow->objectName().isEmpty())
            AdminMainWindow->setObjectName(QStringLiteral("AdminMainWindow"));
        AdminMainWindow->resize(1141, 784);
        centralwidget = new QWidget(AdminMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(960, 660, 80, 20));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 1031, 621));
        gridLayout = new QGridLayout(gridLayoutWidget);
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
        layoutWidget = new QWidget(tab_search);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1001, 531));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
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

        lineEdit_cinemaName = new QLineEdit(layoutWidget);
        lineEdit_cinemaName->setObjectName(QStringLiteral("lineEdit_cinemaName"));

        horizontalLayout->addWidget(lineEdit_cinemaName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_5->addWidget(label_12);

        dateEdit_inquire01 = new QDateEdit(layoutWidget);
        dateEdit_inquire01->setObjectName(QStringLiteral("dateEdit_inquire01"));

        horizontalLayout_5->addWidget(dateEdit_inquire01);

        dateEdit_inquire02 = new QDateEdit(layoutWidget);
        dateEdit_inquire02->setObjectName(QStringLiteral("dateEdit_inquire02"));

        horizontalLayout_5->addWidget(dateEdit_inquire02);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBox_isPlayed = new QCheckBox(layoutWidget);
        checkBox_isPlayed->setObjectName(QStringLiteral("checkBox_isPlayed"));

        verticalLayout_2->addWidget(checkBox_isPlayed);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        pushButton_search = new QPushButton(layoutWidget);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        verticalLayout_2->addWidget(pushButton_search);


        horizontalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        tableWidget_aviMovies = new QTableWidget(layoutWidget);
        tableWidget_aviMovies->setObjectName(QStringLiteral("tableWidget_aviMovies"));

        verticalLayout_5->addWidget(tableWidget_aviMovies);

        label_totalIncome = new QLabel(tab_search);
        label_totalIncome->setObjectName(QStringLiteral("label_totalIncome"));
        label_totalIncome->setGeometry(QRect(960, 550, 54, 12));
        tabWidget->addTab(tab_search, QString());
        tab_towUp = new QWidget();
        tab_towUp->setObjectName(QStringLiteral("tab_towUp"));
        layoutWidget1 = new QWidget(tab_towUp);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 1001, 541));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboBox_hall = new QComboBox(layoutWidget1);
        comboBox_hall->setObjectName(QStringLiteral("comboBox_hall"));

        horizontalLayout_2->addWidget(comboBox_hall);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_addNewHall = new QPushButton(layoutWidget1);
        pushButton_addNewHall->setObjectName(QStringLiteral("pushButton_addNewHall"));

        horizontalLayout_2->addWidget(pushButton_addNewHall);


        verticalLayout_3->addLayout(horizontalLayout_2);

        line_3 = new QFrame(layoutWidget1);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        tableView_currentHall = new QTableView(layoutWidget1);
        tableView_currentHall->setObjectName(QStringLiteral("tableView_currentHall"));

        verticalLayout_3->addWidget(tableView_currentHall);

        tabWidget->addTab(tab_towUp, QString());
        tab_order = new QWidget();
        tab_order->setObjectName(QStringLiteral("tab_order"));
        layoutWidget2 = new QWidget(tab_order);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 1001, 541));
        verticalLayout_6 = new QVBoxLayout(layoutWidget2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
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

        comboBox_hall_2 = new QComboBox(layoutWidget2);
        comboBox_hall_2->setObjectName(QStringLiteral("comboBox_hall_2"));

        horizontalLayout_4->addWidget(comboBox_hall_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_search_2 = new QPushButton(layoutWidget2);
        pushButton_search_2->setObjectName(QStringLiteral("pushButton_search_2"));

        horizontalLayout_4->addWidget(pushButton_search_2);

        pushButton_addNewMovie = new QPushButton(layoutWidget2);
        pushButton_addNewMovie->setObjectName(QStringLiteral("pushButton_addNewMovie"));

        horizontalLayout_4->addWidget(pushButton_addNewMovie);


        verticalLayout_6->addLayout(horizontalLayout_4);

        tableView_movie = new QTableView(layoutWidget2);
        tableView_movie->setObjectName(QStringLiteral("tableView_movie"));

        verticalLayout_6->addWidget(tableView_movie);

        line_4 = new QFrame(layoutWidget2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_4);

        tabWidget->addTab(tab_order, QString());
        tab_personalInfo = new QWidget();
        tab_personalInfo->setObjectName(QStringLiteral("tab_personalInfo"));
        layoutWidget_3 = new QWidget(tab_personalInfo);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(51, 51, 211, 141));
        gridLayout_3 = new QGridLayout(layoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_phone = new QLabel(layoutWidget_3);
        label_phone->setObjectName(QStringLiteral("label_phone"));

        gridLayout_3->addWidget(label_phone, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        label_email = new QLabel(layoutWidget_3);
        label_email->setObjectName(QStringLiteral("label_email"));

        gridLayout_3->addWidget(label_email, 1, 1, 1, 1);

        label_10 = new QLabel(layoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        label_password = new QLabel(layoutWidget_3);
        label_password->setObjectName(QStringLiteral("label_password"));

        gridLayout_3->addWidget(label_password, 2, 1, 1, 1);

        layoutWidget_4 = new QWidget(tab_personalInfo);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(260, 100, 124, 91));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_editPersonalInfo = new QPushButton(layoutWidget_4);
        pushButton_editPersonalInfo->setObjectName(QStringLiteral("pushButton_editPersonalInfo"));

        verticalLayout_4->addWidget(pushButton_editPersonalInfo);

        pushButton_changeUser = new QPushButton(layoutWidget_4);
        pushButton_changeUser->setObjectName(QStringLiteral("pushButton_changeUser"));

        verticalLayout_4->addWidget(pushButton_changeUser);

        tabWidget->addTab(tab_personalInfo, QString());

        gridLayout->addWidget(tabWidget, 3, 0, 1, 2);

        label_test = new QLabel(centralwidget);
        label_test->setObjectName(QStringLiteral("label_test"));
        label_test->setGeometry(QRect(290, 670, 54, 12));
        AdminMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1141, 21));
        AdminMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdminMainWindow->setStatusBar(statusbar);

        retranslateUi(AdminMainWindow);
        QObject::connect(pushButton_exit, SIGNAL(clicked()), AdminMainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainWindow)
    {
        AdminMainWindow->setWindowTitle(QApplication::translate("AdminMainWindow", "MainWindow", Q_NULLPTR));
        pushButton_exit->setText(QApplication::translate("AdminMainWindow", "\351\200\200\345\207\272", Q_NULLPTR));
        label_userInfo->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
        label_currentTime->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("AdminMainWindow", "\347\224\265\345\275\261\345\220\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("AdminMainWindow", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_12->setText(QApplication::translate("AdminMainWindow", "\346\237\245\350\257\242\346\227\245\346\234\237\345\214\272\346\256\265", Q_NULLPTR));
        checkBox_isPlayed->setText(QApplication::translate("AdminMainWindow", "\345\267\262\346\224\276\346\230\240", Q_NULLPTR));
        checkBox->setText(QApplication::translate("AdminMainWindow", "\346\234\252\346\224\276\346\230\240", Q_NULLPTR));
        pushButton_search->setText(QApplication::translate("AdminMainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        label_totalIncome->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_search), QApplication::translate("AdminMainWindow", "\350\256\242\345\215\225\347\256\241\347\220\206", Q_NULLPTR));
        label->setText(QApplication::translate("AdminMainWindow", "\351\200\211\346\213\251\345\275\261\345\216\205", Q_NULLPTR));
        pushButton_addNewHall->setText(QApplication::translate("AdminMainWindow", "+", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_towUp), QApplication::translate("AdminMainWindow", "\345\275\261\345\216\205\347\256\241\347\220\206", Q_NULLPTR));
        label_11->setText(QApplication::translate("AdminMainWindow", "\347\224\265\345\275\261\345\220\215", Q_NULLPTR));
        label_9->setText(QApplication::translate("AdminMainWindow", "\345\275\261\345\216\205", Q_NULLPTR));
        pushButton_search_2->setText(QApplication::translate("AdminMainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_addNewMovie->setText(QApplication::translate("AdminMainWindow", "\346\267\273\345\212\240\345\234\272\346\254\241", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_order), QApplication::translate("AdminMainWindow", "\345\234\272\346\254\241\347\256\241\347\220\206", Q_NULLPTR));
        label_2->setText(QApplication::translate("AdminMainWindow", "\347\224\265\350\257\235", Q_NULLPTR));
        label_phone->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("AdminMainWindow", "\351\202\256\347\256\261", Q_NULLPTR));
        label_email->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("AdminMainWindow", "\345\257\206\347\240\201", Q_NULLPTR));
        label_password->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
        pushButton_editPersonalInfo->setText(QApplication::translate("AdminMainWindow", "\344\277\256\346\224\271", Q_NULLPTR));
        pushButton_changeUser->setText(QApplication::translate("AdminMainWindow", "\345\210\207\346\215\242\347\224\250\346\210\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_personalInfo), QApplication::translate("AdminMainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        label_test->setText(QApplication::translate("AdminMainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdminMainWindow: public Ui_AdminMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINWINDOW_H
