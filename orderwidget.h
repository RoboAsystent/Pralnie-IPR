#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include "navigationwidget.h"
#include "orderlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OrderWidget; }
QT_END_NAMESPACE

class NavigationWidget;
class OrderList;

class OrderWidget : public NavigationWidget
{
    Q_OBJECT
public:
    explicit OrderWidget(NavigationWidget *parent = nullptr);
    virtual ~OrderWidget();

    void setHeader();

private slots:
    void on_Prev_clicked();

    void on_Menu_clicked();

    void on_tableOrders_cellClicked(int row, int column);

private:
    Ui::OrderWidget *ui;
    OrderList *list = nullptr;
};

#endif // ORDERWIDGET_H
