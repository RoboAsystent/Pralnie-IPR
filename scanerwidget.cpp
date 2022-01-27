#include "scanerwidget.h"
#include "ui_scanerwidget.h"

ScanerWidget::ScanerWidget() :
    ui(new Ui::ScannerWidget)
{
    ui->setupUi(this);
    ui->QRCode->setEnabled(false);
    ui->QRCode->setVisible(false);

    scaner.startScan(ui->QRCode);
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

