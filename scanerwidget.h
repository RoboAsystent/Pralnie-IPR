#ifndef SCANERWIDGET_H
#define SCANERWIDGET_H

#include "navigationwidget.h"

class NavigationWidget;

namespace Ui {
    class ScannerWidget;
}

class ScanerWidget : public NavigationWidget
{
    Q_OBJECT
public:
    explicit ScanerWidget();
    virtual ~ScanerWidget();

private slots:
    void on_MenuButton_clicked();

    void on_Back_clicked();

private:
   Ui::ScannerWidget *ui;
};

#endif // SCANERWIDGET_H
