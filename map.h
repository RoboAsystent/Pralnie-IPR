#ifndef MAP_H
#define MAP_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPoint>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Map
{
public:
    Map();
    ~Map();
    void setMap(QGraphicsView *view);
    void addPoint();
    void setCords(QPoint point);

private:
    QGraphicsScene *scene;
    QPoint cords;
};

#endif // MAP_H
