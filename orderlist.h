#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <QObject>
#include <QJsonDocument>
#include <QTableWidget>
#include "servercaller.h"
#include "order.h"

class Order;

class OrderList : public QObject
{
    Q_OBJECT
public:
    explicit OrderList();
    OrderList(QTableWidget *table);
    virtual ~OrderList();

    Order *getOrder(int id);

signals:
    void getOrders();

public slots:
    void getData(const QJsonDocument &doc);

private:
    QHash<int, Order*> orders;
    QTableWidget *table;
};

#endif // ORDERLIST_H
