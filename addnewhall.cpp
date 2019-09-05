#include "addnewhall.h"
#include "ui_addnewhall.h"

AddNewHall::AddNewHall(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewHall)
{
    ui->setupUi(this);
    this->setWindowTitle("新增影厅");
    this->setMaximumSize(557, 542);
    this->setMinimumSize(557, 542);
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

AddNewHall::~AddNewHall()
{
    delete ui;
}

void AddNewHall::receiveAddNewHall()
{
    this->show();
    SqlFuns sf;
    ui->label_cinema->setText(sf.queryCinema(global_userName));
    QStringList typeList = sf.queryHallTemplateInfo();
    ui->comboBox_type->addItems(typeList);
}

void AddNewHall::showSeat(QString seatMap)
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
            item->setFlags(item->flags()& ~Qt::ItemIsSelectable);
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

void AddNewHall::on_comboBox_type_currentTextChanged(const QString &arg1)
{
    SqlFuns sf;
    QStringList info = sf.queryHallTemplateInfo(arg1);

    ui->label_row->setText(info[1]);
    ui->label_column->setText(info[2]);
    ui->label_totalSeats->setText(info[4]);
    showSeat(info[3]);
}

void AddNewHall::on_pushButton_confirm_clicked()
{
    SqlFuns sf;

    QStringList info;
    QString type = ui->comboBox_type->currentText();
    info = sf.queryHallTemplateInfo(type);
    sf.addNewHall(sf.getHallId(), sf.queryCinema(global_userName), info[4].toInt(), info[1].toInt(), info[2].toInt(), info[3], info[0]);
    emit hallAdded();
    this->close();
}
