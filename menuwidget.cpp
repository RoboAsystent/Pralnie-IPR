#include "menuwidget.h"
#include "orderwidget.h"
#include "ui_menu.h"
#include "scanerwidget.h"

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
    qDebug() << "Destruktor menu...";
    delete ui;
}

void MenuWidget::on_List_clicked()
{
    this->hide();
    auto orders = new OrderWidget;
    orders->setRoot(this);
    orders->setCredentials(ui->LogedAs->text());
    orders->setHeader();
    orders->show();
}


void MenuWidget::on_ScanSack_clicked()
{
    this->hide();
    auto scan_widget = new ScanerWidget();
    scan_widget->setCredentials(ui->LogedAs->text());
    scan_widget->setRoot(this);
    scan_widget->show();
}
