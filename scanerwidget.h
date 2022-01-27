#ifndef SCANERWIDGET_H
#define SCANERWIDGET_H

#include "navigationwidget.h"
#include "scaner.h"

class NavigationWidget;
class Scaner;

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
   Scaner scaner;
};

#endif // SCANERWIDGET_H
