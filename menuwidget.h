#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include "orderwidget.h"

class OrderWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWidget; }
QT_END_NAMESPACE

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
    virtual ~MenuWidget();

signals:

private slots:
    void on_List_clicked();

private:
    Ui::MenuWidget *ui;
    OrderWidget *orders = nullptr;
};

#endif // MENUWIDGET_H
