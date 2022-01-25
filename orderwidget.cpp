#include "orderwidget.h"
#include "ui_orderwidget.h"
#include <QDebug>

OrderWidget::OrderWidget(NavigationWidget *parent) : NavigationWidget(parent)
  , ui(new Ui::OrderWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

OrderWidget::~OrderWidget()
{
    delete ui;
    qDebug() << "Destruktor list";
}

void OrderWidget::setHeader()
{
    ui->label->setText(getCredentials());
}

void OrderWidget::on_Prev_clicked()
{
    if (getPrev())
    {
        this->hide();
        getPrev()->show();
    }
}


void OrderWidget::on_Menu_clicked()
{
    if (getRoot())
    {
        this->hide();
        getRoot()->show();
    }
}
