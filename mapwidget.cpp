#include "mapwidget.h"
#include "ui_mapwidget.h"
#include <QPixmap>
#include <QGraphicsView>
#include <QDebug>
#include <qmath.h>


MapWidget::MapWidget(NavigationWidget *parent) : NavigationWidget(parent)
  , ui(new Ui::MapWidget)


{
    ui->setupUi(this);
    QPixmap pix(":/map/image1.PNG");

    scene = new QGraphicsScene(this);
    scene->addPixmap(pix);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);


}

MapWidget::~MapWidget()
{
    delete ui;
    delete scene;

}


void MapWidget::setHeader()
{
    ui->labelUserInfo->setText(getCredentials());
}


void MapWidget::on_pushButtonBack_clicked()
{
    if (getPrev())
    {
        this->hide();
        getPrev()->show();
    }
}

void MapWidget::on_pushButtonMenu_clicked()
{
    if (getRoot())
    {
        this->hide();
        getRoot()->show();
    }
}

void MapWidget::wheelEvent(QWheelEvent *pWheelEvent)
{
   if (pWheelEvent->modifiers() & Qt::ControlModifier)
       {
            double angle = pWheelEvent->angleDelta().y();
            double factor = qPow(1.0015, angle);

            auto targetViewportPos = pWheelEvent->pos();
            auto targetScenePos = ui->graphicsView->mapToScene(pWheelEvent->pos());

            ui->graphicsView->scale(factor, factor);
            ui->graphicsView->centerOn(targetScenePos);
            QPointF deltaViewportPos = targetViewportPos - QPointF(ui->graphicsView->viewport()->width() / 2.0, ui->graphicsView->viewport()->height() / 2.0);
            QPointF viewportCenter = ui->graphicsView->mapFromScene(targetScenePos) - deltaViewportPos;
            ui->graphicsView->centerOn(ui->graphicsView->mapToScene(viewportCenter.toPoint()));

            return;
   }
}


