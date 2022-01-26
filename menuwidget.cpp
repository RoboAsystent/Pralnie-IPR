#include "menuwidget.h"
#include "ui_menu.h"
#include <QDebug>
#include <QLabel>


MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent),
  ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    QString info = ui->LogedAs->text() + " Kamil Slimak";
    ui->LogedAs->setText(info);
}

MenuWidget::~MenuWidget()
{
    qDebug() << "Robie ten destruktor";
    delete ui;
}

void MenuWidget::on_List_clicked()
{
    if (orders)
    {
        this->hide();
        orders->show();
        return;
    }

    this->hide();
    orders = new OrderWidget;
    orders->setRoot(this);
    orders->setPrev(this);
    orders->setCredentials(ui->LogedAs->text());
    orders->setHeader();
    orders->show();
}


void MenuWidget::on_ScanSack_clicked()
{
    map = new MapWidget;                        // TO REMOVE
    map->setRoot(this);                         // TO REMOVE
    map->setPrev(this);                         // TO REMOVE
    map->setCredentials(ui->LogedAs->text());   // TO REMOVE
    map->setHeader();                           // TO REMOVE
    map->show();                                // TO REMOVE
}
