#include "order.h"
#include <QDebug>

Order::Order()
{

}

Order::Order(int _id, QString _street, QString _target) :
    id(_id),
    street(_street),
    target(_target)
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
