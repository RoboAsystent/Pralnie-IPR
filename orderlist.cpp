#include "orderlist.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

OrderList::OrderList()
{
}

OrderList::OrderList(QTableWidget *_table) :
    table(_table)
{
}

OrderList::~OrderList()
{
    qDebug() << "Destruktor order listy";
    for (auto order : orders)
    {
        delete order;
    }
    orders.clear();
}

Order *OrderList::getOrder(int id)
{
    return orders[id];
}

void OrderList::getData(const QJsonDocument &doc)
{
    //czytanie jsona i tworzenie orderów
    QJsonObject item = doc.object();
    QJsonArray orders_array = item["orders"].toArray();

    for (auto item : orders_array)
    {
        QJsonObject obj = item.toObject();

        QJsonValue street = obj["street"];
        QJsonValue id = obj["id"];
        QJsonValue target = obj["target"];

        auto order = new Order(id.toInt(), street.toString(), target.toString());
        this->orders[id.toInt()] = order;

        table->insertRow(table->rowCount());
        int row = table->rowCount()-1;

        table->setItem(row, 0, new QTableWidgetItem(QString::number(id.toInt())));
        table->setItem(row, 1, new QTableWidgetItem(target.toString()));
        table->setItem(row, 2, new QTableWidgetItem(street.toString()));

        table->resizeColumnsToContents();
    }
}
