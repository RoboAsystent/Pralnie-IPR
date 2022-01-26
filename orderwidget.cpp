#include "orderwidget.h"
#include "ui_orderwidget.h"
#include "orderdetailswidget.h"
#include <QDebug>

OrderWidget::OrderWidget(NavigationWidget *parent) : NavigationWidget(parent)
  , ui(new Ui::OrderWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    list = new OrderList(ui->tableOrders);

    ui->tableOrders->setColumnCount(3);
    QStringList headers = {"id", "Cel", "Adres"};
    ui->tableOrders->setHorizontalHeaderLabels(headers);
    ui->tableOrders->verticalHeader()->setVisible(false);
    ui->tableOrders->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //wysyłanie zapytania przez listę na temat zleceń
    QObject::connect(list, &OrderList::getOrders, &ServerCaller::getServerCaller(), &ServerCaller::readOrders);
    QObject::connect(&ServerCaller::getServerCaller(), &ServerCaller::readOrdersFinished, list, &OrderList::getData);

    emit list->getOrders();
}

OrderWidget::~OrderWidget()
{
    QObject::disconnect(list, &OrderList::getOrders, &ServerCaller::getServerCaller(), &ServerCaller::readOrders);
    QObject::disconnect(&ServerCaller::getServerCaller(), &ServerCaller::readOrdersFinished, list, &OrderList::getData);

    delete ui;
    delete list;

    qDebug() << "Destruktor orderwidget";
}

void OrderWidget::setHeader()
{
    ui->label->setText(getCredentials());
}

void OrderWidget::on_Prev_clicked()
{
    goBack();
}


void OrderWidget::on_Menu_clicked()
{
    goToRoot();
}


void OrderWidget::on_tableOrders_cellClicked(int row, int column)
{
    int id = (ui->tableOrders->item(row,0))->text().toInt();
    qDebug() << id;

    auto details = new OrderDetailsWidget(0, list->getOrder(id));
//    auto details = new OrderDetailsWidget();
    details->setCredentials(this->getCredentials());
    details->setHeader();
    details->setParent(this);
    details->setRoot(this->getRoot());
    appendChild(details);
    details->show();
    this->hide();
    //tworzenie widgetu szczegolow i jego wyswietlanie

}

