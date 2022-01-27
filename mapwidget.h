#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include "navigationwidget.h"
#include <QMouseEvent>
#include <QEvent>
#include <QGraphicsView>
#include <map.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MapWidget; }
QT_END_NAMESPACE

class NavigationWidget;

class MapWidget : public NavigationWidget
{
    Q_OBJECT
public:
    explicit MapWidget(NavigationWidget *parent = nullptr);
    explicit MapWidget(QPoint cords);
    virtual ~MapWidget();

    void setHeader();

signals:


private slots:
    void on_pushButtonBack_clicked();

    void on_pushButtonMenu_clicked();

private:
    Ui::MapWidget *ui;

    void wheelEvent(QWheelEvent* pWheelEvent);

    Map *map;
};

#endif // MAPWIDGET_H
