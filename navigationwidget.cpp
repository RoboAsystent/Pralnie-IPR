#include "navigationwidget.h"
#include <QDebug>

NavigationWidget::NavigationWidget(QWidget *parent) : QWidget(parent)
{
}

NavigationWidget::~NavigationWidget()
{
    qDebug() << "Destruktor navigation widget...";
}

void NavigationWidget::setParent(NavigationWidget *widget)
{
    parent = widget;
}

NavigationWidget *NavigationWidget::getParent()
{
    return parent;
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
    if (parent)
    {
        parent->show();
        parent->removeChild(this);
        deleteChildren();
        this->deleteLater();
    }
    else
    {
        root->show();
        deleteChildren();
        this->deleteLater();
    }
}

void NavigationWidget::goToRoot()
{
    if (root)
    {
        root->show();
        deleteChildren();
        deleteParent();
        this->deleteLater();
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

bool NavigationWidget::HasChildren()
{
    return children.size() ? true : false;
}

void NavigationWidget::deleteChildren()
{
    if (!HasChildren())
        return;

    for (auto child : children)
    {
        child->deleteChildren();
        child->deleteLater();
    }
}

void NavigationWidget::deleteParent()
{
    if (getParent())
    {
        getParent()->deleteLater();
    }
}

void NavigationWidget::appendChild(NavigationWidget*widget)
{
    children.push_back(widget);
}

void NavigationWidget::removeChild(NavigationWidget *widget)
{
    children.removeOne(widget);
}
