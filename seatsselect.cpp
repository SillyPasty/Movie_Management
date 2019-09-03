#include "seatsselect.h"
#include "ui_seatsselect.h"

SeatsSelect::SeatsSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeatsSelect)
{
    ui->setupUi(this);
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

void SeatsSelect::receivePayment(QString movieId)
{
    movieIdStore = movieId;
    SqlFuns sf;
    QStringList qsl = sf.queryOrderInfo(movieIdStore);
    ui->label_movieName->setText(sf.queryMovieName(movieIdStore));
    QString seatMap = sf.querySeatMap(movieIdStore);
    ui->label_startTime->setText(qsl[3] + " " + qsl[1]);
    ui->label_cinema->setText(qsl[0]);
    calAxis();
    showSeat(seatMap);
    this->show();
}
void SeatsSelect::showSeat(QString seatMap)
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
            item->setData(Qt::UserRole, 0);
            item->setFlags(item->flags() & !Qt::ItemIsEnabled & !Qt::ItemIsSelectable);
        }
        ql.append(item);
    }
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 21; j++)
            ui->tableWidget->setItem(i, j, ql[i * 21 + j]);
}
SeatsSelect::~SeatsSelect()
{
    delete ui;
}

void SeatsSelect::on_tableWidget_clicked(const QModelIndex &index)
{
    QTableWidgetItem *selected = ui->tableWidget->item(index.row(), index.column());
    QVariant flg;
    flg = selected->data(Qt::UserRole);
    if(flg == 1)
    {
        selected->setIcon(QPixmap("D:/university/programming/QTcodes/testT/chosen1.png"));
        selected->setData(Qt::UserRole, 2);
    }
    else if(flg == 2)
    {
        selected->setIcon(QPixmap("D:/university/programming/QTcodes/testT/avi1.png"));
        selected->setData(Qt::UserRole, 1);
    }
}

void SeatsSelect::on_pushButton_puchase_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::No; // 返回选择的按钮
    int seatsInfo[3] = {0}, tickets = 0;
    SqlFuns sf;

    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 21; j++)
            if(ui->tableWidget->item(i, j)->data(Qt::UserRole) == 2)
            {
                if(tickets < 3)
                    //  将座位坐标减去偏移量后 存为四位数字
                    seatsInfo[tickets] = (j - xAxis + 1) * 100 + (i - yAxis + 1);

                tickets++;
            }
        if(tickets > 3)
            QMessageBox::critical(this, "选择座位过多", "最多选择三个座位");
        else
        {
            QString info;
            float price = sf.queryPrice(movieIdStore);
            info.sprintf("%.2f", price * tickets);
            //  获得现在时间
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString cur = curDateTime.toString("yyyyMMddhhmmss"), orderId;

            result = QMessageBox::question(this, "支付", "一共要付款" + info + "元\n是否要支付？", QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton);
            orderId = sf.addNewOrder(movieIdStore, seatsInfo[0], seatsInfo[1], seatsInfo[2], cur);
            if(result == QMessageBox::Yes)
            {
                float bal = sf.queryBalance();
                float total = sf.queryPrice(movieIdStore) * tickets;
                if(bal < total)
                    QMessageBox::critical(nullptr, "余额不足", "无法购买");
                else
                {
                    sf.changePaymentStage(orderId, tickets, total);
                    sf.changeUserBalance(-1 * total);
                }
            }
            this->close();
        }
}

void SeatsSelect::calAxis()
{
    SqlFuns sf;

    QStringList qsl = sf.queryOrderInfo(movieIdStore);
    int row = sf.queryRow(qsl[4], qsl[0]);
    int col = sf.queryColumn(qsl[4], qsl[0]);
    xAxis = (21 - col) / 2;
    yAxis = (12 - row) / 2;
}
