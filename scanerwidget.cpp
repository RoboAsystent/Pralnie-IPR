#include "scanerwidget.h"
#include "ui_scanerwidget.h"
#include "scaner.h"

#include <QIcon>

ScanerWidget::ScanerWidget() :
    ui(new Ui::ScannerWidget)
{
    ui->setupUi(this);
    ui->QRCode->setEnabled(false);
    ui->QRCode->setVisible(false);
    QIcon icon(":/map/QRCode_wiki.png");
    ui->QRCode->setIcon(icon);
    ui->QRCode->setIconSize(QSize(335,335));
}

ScanerWidget::~ScanerWidget()
{
    delete ui;
}

void ScanerWidget::on_MenuButton_clicked()
{
    goToRoot();
}


void ScanerWidget::on_Back_clicked()
{
    goBack();
}

