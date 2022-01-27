#ifndef ORDER_H
#define ORDER_H

#include <QObject>
#include <QPoint>

class Order
{
public:
    explicit Order();
    explicit Order(int id, QString street, QString target, int cor_x, int cor_y);
    virtual ~Order();

    int getId();
    QString getStreet();
    QString getTarget();
    QPoint getCords();

private:
    int id;
    QString target;
    QString street;
    QPoint cords;

};

#endif // ORDER_H
