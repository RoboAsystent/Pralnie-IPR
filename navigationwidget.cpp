#include "navigationwidget.h"
#include <QDebug>

NavigationWidget::NavigationWidget(QWidget *parent) : QWidget(parent)
{
}

NavigationWidget::~NavigationWidget()
{
    qDebug() << "Destruktor z gory";
}

void NavigationWidget::setPrev(QWidget *widget)
{
    prev = widget;
}

QWidget *NavigationWidget::getPrev()
{
    return prev;
}

void NavigationWidget::setRoot(QWidget *widget)
{
    root = widget;
}

QWidget *NavigationWidget::getRoot()
{
    return root;
}

void NavigationWidget::goBack()
{
    if (prev)
    {
        prev->show();
        this->hide();
    }
}

void NavigationWidget::goToRoot()
{
    if (root)
    {
        root->show();
        this->hide();
    }
}

void NavigationWidget::setCredentials(const QString _cred)
{
    cred = _cred;
}

QString NavigationWidget::getCredentials()
{
    return cred;
}
