/********************************************************************************
** Form generated from reading UI file 'movieseatmap.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIESEATMAP_H
#define UI_MOVIESEATMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieSeatMap
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_movieName;
    QLabel *label_hall;
    QLabel *label_startTime;
    QLabel *label_percent;
    QLabel *label_totalIncome;

    void setupUi(QWidget *MovieSeatMap)
    {
        if (MovieSeatMap->objectName().isEmpty())
            MovieSeatMap->setObjectName(QStringLiteral("MovieSeatMap"));
        MovieSeatMap->resize(484, 569);
        tableWidget = new QTableWidget(MovieSeatMap);
        if (tableWidget->columnCount() < 21)
            tableWidget->setColumnCount(21);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        if (tableWidget->rowCount() < 12)
            tableWidget->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem32);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(20, 160, 431, 251));
        pushButton = new QPushButton(MovieSeatMap);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(320, 480, 80, 20));
        widget = new QWidget(MovieSeatMap);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 20, 71, 131));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        widget1 = new QWidget(MovieSeatMap);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(160, 20, 201, 131));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_movieName = new QLabel(widget1);
        label_movieName->setObjectName(QStringLiteral("label_movieName"));

        verticalLayout_2->addWidget(label_movieName);

        label_hall = new QLabel(widget1);
        label_hall->setObjectName(QStringLiteral("label_hall"));

        verticalLayout_2->addWidget(label_hall);

        label_startTime = new QLabel(widget1);
        label_startTime->setObjectName(QStringLiteral("label_startTime"));

        verticalLayout_2->addWidget(label_startTime);

        label_percent = new QLabel(widget1);
        label_percent->setObjectName(QStringLiteral("label_percent"));

        verticalLayout_2->addWidget(label_percent);

        label_totalIncome = new QLabel(widget1);
        label_totalIncome->setObjectName(QStringLiteral("label_totalIncome"));

        verticalLayout_2->addWidget(label_totalIncome);


        retranslateUi(MovieSeatMap);
        QObject::connect(pushButton, SIGNAL(clicked()), MovieSeatMap, SLOT(close()));

        QMetaObject::connectSlotsByName(MovieSeatMap);
    } // setupUi

    void retranslateUi(QWidget *MovieSeatMap)
    {
        MovieSeatMap->setWindowTitle(QApplication::translate("MovieSeatMap", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem25->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem26->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem27->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem28->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem29->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem30->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem31->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem32->setText(QApplication::translate("MovieSeatMap", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MovieSeatMap", "\347\241\256\345\256\232", Q_NULLPTR));
        label->setText(QApplication::translate("MovieSeatMap", "\347\224\265 \345\275\261 \345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MovieSeatMap", "\345\275\261    \345\216\205\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MovieSeatMap", "\345\274\200\345\247\213\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MovieSeatMap", "\344\270\212 \345\272\247 \347\216\207\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MovieSeatMap", "\346\200\273 \346\224\266 \345\205\245\357\274\232", Q_NULLPTR));
        label_movieName->setText(QApplication::translate("MovieSeatMap", "TextLabel", Q_NULLPTR));
        label_hall->setText(QApplication::translate("MovieSeatMap", "\345\275\261\345\216\205", Q_NULLPTR));
        label_startTime->setText(QApplication::translate("MovieSeatMap", "TextLabel", Q_NULLPTR));
        label_percent->setText(QApplication::translate("MovieSeatMap", "TextLabel", Q_NULLPTR));
        label_totalIncome->setText(QApplication::translate("MovieSeatMap", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MovieSeatMap: public Ui_MovieSeatMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIESEATMAP_H
