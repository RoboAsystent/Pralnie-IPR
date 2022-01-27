#include "mapwidget.h"
#include "ui_mapwidget.h"
#include <QPixmap>
#include <QGraphicsView>
#include <QDebug>
#include <qmath.h>


class Map;

MapWidget::MapWidget(NavigationWidget *parent) : NavigationWidget(parent)
  , ui(new Ui::MapWidget)


{
    ui->setupUi(this);
    map = new Map;
    map->setMap(ui->graphicsView);

}

MapWidget::MapWidget(QPoint cords) :
    ui(new Ui::MapWidget)
{
    ui->setupUi(this);
    map = new Map;
    map->setCords(cords);
    map->setMap(ui->graphicsView);


}

MapWidget::~MapWidget()
{
    delete ui;
    delete map;
}


void MapWidget::setHeader()
{
    ui->labelUserInfo->setText(getCredentials());
}


void MapWidget::on_pushButtonBack_clicked()
{
    goBack();
}

void MapWidget::on_pushButtonMenu_clicked()
{
    goToRoot();
}

void MapWidget::wheelEvent(QWheelEvent *pWheelEvent)
{
   if (pWheelEvent->modifiers() & Qt::ControlModifier)
       {
            double angle = pWheelEvent->angleDelta().y();
            double factor = qPow(1.0015, angle);

            auto targetViewportPos = pWheelEvent->position();
            auto targetScenePos = ui->graphicsView->mapToScene(pWheelEvent->pos());

            ui->graphicsView->scale(factor, factor);
            ui->graphicsView->centerOn(targetScenePos);
            QPointF deltaViewportPos = targetViewportPos - QPointF(ui->graphicsView->viewport()->width() / 2.0, ui->graphicsView->viewport()->height() / 2.0);
            QPointF viewportCenter = ui->graphicsView->mapFromScene(targetScenePos) - deltaViewportPos;
            ui->graphicsView->centerOn(ui->graphicsView->mapToScene(viewportCenter.toPoint()));

            return;
   }
}


