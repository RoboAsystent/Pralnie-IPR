#ifndef ORDERLIST_H
#define ORDERLIST_H

#include <QObject>
#include "servercaller.h"

class OrderList : public QObject
{
    Q_OBJECT
public:
    explicit OrderList();
    virtual ~OrderList();

public slots:
    void getData();

private:
    ServerCaller *caller = nullptr;
};

#endif // ORDERLIST_H
