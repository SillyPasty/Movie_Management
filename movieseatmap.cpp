/*
 * 管理员查看订单信息
 */
#include "movieseatmap.h"
#include "ui_movieseatmap.h"

MovieSeatMap::MovieSeatMap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MovieSeatMap)
{
    ui->setupUi(this);
    this->setWindowTitle("信息查看");
    this->setMaximumSize(484, 569);
    this->setMinimumSize(484, 569);
    this->setWindowIcon(QIcon(QStringLiteral(":/new/prefix1/iconfinder_movie_118631.png")));
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(20);
    ui->tableWidget->setStyleSheet("selection-background-color:white;");
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

void MovieSeatMap::showSeat(QString seatMap)  // 对字符串逐位判断 在表格上显示图片
{
    QChar choice;
    QList<QTableWidgetItem *> ql;
    for(int i = 0; i < 252; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        choice = seatMap[i];
        if(choice == "0")
        {
            item->setIcon(QPixmap(":/new/prefix1/avi1.png"));
            item->setData(Qt::UserRole, 1);
        }
        else if(choice == "1")
        {
            item->setIcon(QPixmap(":/new/prefix1/unuse1.png"));
            item->setData(Qt::UserRole, 0);
            item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        }
        else
        {
            item->setIcon(QPixmap(":/new/prefix1/blank.png"));
            item->setData(Qt::UserRole, 3);
            item->setFlags(item->flags() & !Qt::ItemIsEnabled & !Qt::ItemIsSelectable);
        }
        ql.append(item);
    }
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 21; j++)
            ui->tableWidget->setItem(i, j, ql[i * 21 + j]);
}


void MovieSeatMap::receiveMovieDetail(QString movieId) // 查询电影信息并展示与label
{
    SqlFuns sf;
    QStringList info = sf.queryMovieInfo(movieId);
    ui->label_movieName->setText(sf.queryMovieName(movieId));
    ui->label_hall->setText(info[0]);
    ui->label_startTime->setText(info[2] + " " + info[1]);
    ui->label_percent->setText(info[3]);
    ui->label_totalIncome->setText(info[4] + "元");
    showSeat(sf.querySeatMap(movieId));
    this->show();
}

MovieSeatMap::~MovieSeatMap()
{
    delete ui;
}
