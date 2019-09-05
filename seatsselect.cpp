#include "seatsselect.h"
#include "ui_seatsselect.h"

SeatsSelect::SeatsSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeatsSelect)
{
    ui->setupUi(this);
    this->setWindowTitle("购票界面");
    this->setMaximumSize(479, 538);
    this->setMinimumSize(479, 538);
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
    ui->label_disInfo->show();
    if(!sf.queryIsDiscount(movieId))
        ui->label_disInfo->hide();
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
            item->setData(Qt::UserRole, 3);
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
        selected->setIcon(QPixmap(":/new/prefix1/chosen1.png"));
        selected->setData(Qt::UserRole, 2);
    }
    else if(flg == 2)
    {
        selected->setIcon(QPixmap(":/new/prefix1/avi1.png"));
        selected->setData(Qt::UserRole, 1);
    }
}

void SeatsSelect::on_pushButton_puchase_clicked()
{
    QMessageBox::StandardButton result1 = QMessageBox::No; // 返回选择的按钮
    QMessageBox::StandardButton result2 = QMessageBox::No; // 返回选择的按钮
    int seatsInfo[3] = {0}, tickets = 0;
    SqlFuns sf;
    QString seatMap;
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 21; j++)
        {
            //  更新座位图
            switch (ui->tableWidget->item(i, j)->data(Qt::UserRole).toInt())
            {
            case 0:
                seatMap = seatMap + "1";
                break;
            case 1:
                seatMap = seatMap + "0";
                break;
            case 2:
                seatMap = seatMap + "1";
                break;
            case 3:
                seatMap = seatMap + "2";
                break;
            }
            if(ui->tableWidget->item(i, j)->data(Qt::UserRole) == 2)
            {
                if(tickets < 3)
                    //  将座位坐标减去偏移量后 存为四位数字
                    seatsInfo[tickets] = (j - xAxis + 1) * 100 + (i - yAxis + 1);
                tickets++;
            }
        }
        if(tickets > 3)
            QMessageBox::critical(this, "选择座位过多", "最多选择三个座位");
        else if(sf.judgeUserOrderNumber(movieIdStore) == -1)
            QMessageBox::critical(this, "今日订单已达上限", "每天最多五个订单");            
        else if(sf.judgeSeatOrder(movieIdStore, seatsInfo[0], seatsInfo[1], seatsInfo[2]) == -1)
            QMessageBox::critical(this, "座位不合法", "不能与其他座位仅相隔一个座位");
        else
        {
            QString info;
            float total;
            float price = sf.queryPrice(movieIdStore);
            if(sf.queryIsDiscount(movieIdStore))
                total = calTotal(price, tickets);
            else
                total = price * tickets;

            info.sprintf("%.2f", total);
            //  获得现在时间
            QDateTime curDateTime = QDateTime::currentDateTime();
            QString cur = curDateTime.toString("yyyyMMddhhmmss"), orderId;

            if(sf.warning_confilcted_orders(movieIdStore) == 1)
                if (QMessageBox::question(this, "与现有订单冲突", "是否继续购买?", QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton) == QMessageBox::No)
                {
                    this->close();
                    return;
                }
            result1 = QMessageBox::question(this, "支付", "一共要付款" + info + "元\n是否要支付？", QMessageBox::Yes | QMessageBox::No, QMessageBox::NoButton);
            orderId = sf.addNewOrder(movieIdStore, seatsInfo[0], seatsInfo[1], seatsInfo[2], cur, price * tickets);
            sf.updateSeatMap(movieIdStore, seatMap);
            if(result1 == QMessageBox::Yes)
            {
                float bal = sf.queryBalance();
                if(bal < total)
                    QMessageBox::critical(nullptr, "余额不足", "无法购买");
                else
                {
                    sf.changePaymentStage(orderId, tickets, total);
                    sf.changeUserBalance(-1 * total);
                }
            }
            emit balanceChange();
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

void SeatsSelect::on_radioButton_one_clicked()
{
    SqlFuns sf;
    int pos = sf.intelligentSeatsRecommend(movieIdStore, 1);
    if(pos == -1)
    {
        QMessageBox::critical(this, "无推荐座位", "请自行选择");
        return;
    }
    QStringList info = sf.queryOrderInfo(movieIdStore);
    int now_seat_row = sf.queryRow(info[4], info[0]);
    int now_seat_column = sf.queryColumn(info[4], info[0]);
    int row_bias = (12 - now_seat_row) / 2;
    int column_bias = (21 - now_seat_column) / 2;
    int y_pos = pos % 100 - 1;
    int x_pos = pos / 100 - 1;
    pos = (y_pos + row_bias) * 21 + column_bias + x_pos;

    QString seatMap = sf.querySeatMap(movieIdStore);
    QChar choice;
    QList<QTableWidgetItem *> ql;
    for(int i = 0; i < 252; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        choice = seatMap[i];
        if(i == pos)
        {
            item->setIcon(QPixmap(":/new/prefix1/chosen1.png"));
            item->setData(Qt::UserRole, 2);
        }
        else if(choice == "0")
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

void SeatsSelect::on_radioButton_two_clicked()
{
    SqlFuns sf;
    int pos = sf.intelligentSeatsRecommend(movieIdStore, 2);
    if(pos == -1)
    {
        QMessageBox::critical(this, "无推荐座位", "请自行选择");
        return;
    }
    QStringList info = sf.queryOrderInfo(movieIdStore);
    int now_seat_row = sf.queryRow(info[4], info[0]);
    int now_seat_column = sf.queryColumn(info[4], info[0]);
    int row_bias = (12 - now_seat_row) / 2;
    int column_bias = (21 - now_seat_column) / 2;
    int y_pos = pos % 100 - 1;
    int x_pos = pos / 100 - 1;
    pos = (y_pos + row_bias) * 21 + column_bias + x_pos;

    QString seatMap = sf.querySeatMap(movieIdStore);
    QChar choice;
    QList<QTableWidgetItem *> ql;
    for(int i = 0; i < 252; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        choice = seatMap[i];
        if(i == pos || i == (pos + 1))
        {
            item->setIcon(QPixmap(":/new/prefix1/chosen1.png"));
            item->setData(Qt::UserRole, 2);
        }
        else if(choice == "0")
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

void SeatsSelect::on_radioButton_three_clicked()
{
    SqlFuns sf;
    int pos = sf.intelligentSeatsRecommend(movieIdStore, 3);
    if(pos == -1)
    {
        QMessageBox::critical(this, "无推荐座位", "请自行选择");
        return;
    }
    QStringList info = sf.queryOrderInfo(movieIdStore);
    int now_seat_row = sf.queryRow(info[4], info[0]);
    int now_seat_column = sf.queryColumn(info[4], info[0]);
    int row_bias = (12 - now_seat_row) / 2;
    int column_bias = (21 - now_seat_column) / 2;
    int y_pos = pos % 100 - 1;
    int x_pos = pos / 100 - 1;
    pos = (y_pos + row_bias) * 21 + column_bias + x_pos;

    QString seatMap = sf.querySeatMap(movieIdStore);
    QChar choice;
    QList<QTableWidgetItem *> ql;
    for(int i = 0; i < 252; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem();
        choice = seatMap[i];
        if(i == pos || i == (pos + 1) || i == (pos - 1))
        {
            item->setIcon(QPixmap(":/new/prefix1/chosen1.png"));
            item->setData(Qt::UserRole, 2);
        }
        else if(choice == "0")
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

float SeatsSelect::calTotal(float price, int tickets)
{
    if(tickets == 1)
        return price;
    else if(tickets == 2)
        return price * 1.9;
    else
        return price * 2.7;
}
