#include "orderdetailswidget.h"
#include "ui_orderdetailswidget.h"
#include "mapwidget.h"
#include "servercaller.h"
#include <QDebug>

OrderDetailsWidget::OrderDetailsWidget() :
    ui(new Ui::OrderDetailsWidget)
{
    ui->setupUi(this);
}

OrderDetailsWidget::OrderDetailsWidget(int type, Order *_order) :
    ui(new Ui::OrderDetailsWidget),
    my_order(_order)
{
    ui->setupUi(this);
    // jeśli to są szczegółu ze skanera
    if (type == 1)
    {
        ui->OpenBox->setVisible(false);
    }
    // jeśli to są szczegóły z listy szczegółów
    else if (type == 0)
    {
        ui->Submit->setVisible(false);

        if (my_order->getTarget() != "DoPralniomatu")
            ui->OpenBox->setVisible(false);
    }

    ui->IdLabel->setText("Zamówienie numer: " + QString::number(my_order->getId()));
    ui->TargetLabel->setText("Dostarczyć do: " + my_order->getTarget());
    ui->StreetLabel->setText("Adres: " + my_order->getStreet());
}

OrderDetailsWidget::~OrderDetailsWidget()
{
    qDebug() << "Destruktor szczegolow orderu";
    delete ui;
}

void OrderDetailsWidget::setHeader()
{
    ui->LogedAs->setText(this->getCredentials());
}


void OrderDetailsWidget::on_Back_clicked()
{
    goBack();
}


void OrderDetailsWidget::on_MenuButton_clicked()
{
    goToRoot();
}


void OrderDetailsWidget::on_OpenBox_clicked()
{
    int my_X = 10;
    int my_Y = 10;
    ServerCaller::getServerCaller().openBox(my_X, my_Y);
}


void OrderDetailsWidget::on_ShowMap_clicked()
{
    auto map = new MapWidget(my_order->getCords());
    map->setRoot(this->getRoot());
    map->setParent(this);
    map->setCredentials(this->getCredentials());
    map->setHeader();
    map->show();
    this->hide();
}

