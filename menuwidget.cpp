#include "menuwidget.h"
#include "ui_menu.h"
#include <QDebug>

MenuWidget::MenuWidget(QWidget *parent) : QWidget(parent),
  ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

MenuWidget::~MenuWidget()
{
    qDebug() << "Robie ten destruktor";
    delete ui;
}
