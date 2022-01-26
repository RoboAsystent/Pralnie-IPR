#ifndef ORDERDETAILSWIDGET_H
#define ORDERDETAILSWIDGET_H
#include "navigationwidget.h"
#include "order.h"

class NavigationWidget;
class Order;

namespace Ui {
    class OrderDetailsWidget;
}

class OrderDetailsWidget : public NavigationWidget
{
    Q_OBJECT
public:
    explicit OrderDetailsWidget();
    OrderDetailsWidget(int type, Order *_order);
    virtual ~OrderDetailsWidget();

    void setHeader();

private slots:
    void on_Back_clicked();

    void on_MenuButton_clicked();

private:
    Ui::OrderDetailsWidget *ui;
    Order *my_order;
};

#endif // ORDERDETAILSWIDGET_H
