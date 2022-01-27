#include "map.h"

Map::Map()
{

}

Map::~Map()
{
    delete scene;
}

void Map::setMap(QGraphicsView *view)
{

    QPixmap pix(":/map/image1.PNG");

    scene = new QGraphicsScene(view);
    scene->addPixmap(pix);

    addPoint();
    view->setScene(scene);

    view->centerOn(cords);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

}

void Map::addPoint()
{
    QPixmap pixPoint(":/map/point.png");


    QGraphicsPixmapItem *pointImage = scene->addPixmap(pixPoint.scaled(50,50));

    pointImage->setPos(cords);

}

void Map::setCords(QPoint point)
{
    cords = point;
}
