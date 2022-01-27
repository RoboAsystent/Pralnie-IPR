#include "order.h"
#include <QDebug>

Order::Order()
{

}

Order::Order(int _id, QString _street, QString _target, int _cor_x, int _cor_y) :
    id(_id),
    street(_street),
    target(_target),
    cords(_cor_x, _cor_y)
{
}

Order::~Order()
{
    qDebug() << "Destruktor order";
}

int Order::getId()
{
    return id;
}

QString Order::getStreet()
{
    return street;
}

QString Order::getTarget()
{
    return target;
}

QPoint Order::getCords()
{
    return cords;
}
