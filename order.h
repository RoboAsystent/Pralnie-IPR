#ifndef ORDER_H
#define ORDER_H

#include <QObject>

class Order
{
public:
    explicit Order();
    explicit Order(int id, QString street, QString target);
    virtual ~Order();

    int getId();
    QString getStreet();
    QString getTarget();

private:
    int id;
    QString target;
    QString street;
};

#endif // ORDER_H
