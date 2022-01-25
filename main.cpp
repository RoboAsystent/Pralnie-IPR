#include "loginwidget.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget *w = new LoginWidget;
    w->show();
    return a.exec();
}
