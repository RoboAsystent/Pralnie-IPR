#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QWidget>

class NavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationWidget(QWidget *parent = nullptr);
    virtual ~NavigationWidget();

    void setParent(NavigationWidget *widget);
    NavigationWidget *getParent();

    void setRoot(QWidget *widget);
    QWidget *getRoot();

    void goBack();
    void goToRoot();

    void setCredentials(const QString _cred);
    QString getCredentials();

    bool HasChildren();

    void deleteChildren();
    void deleteParent();

    void appendChild(NavigationWidget *widget);
    void removeChild(NavigationWidget *widget);

private:
    NavigationWidget *parent = nullptr;
    QWidget *root = nullptr;
    QVector <NavigationWidget*> children;

    QString cred;

signals:

};

#endif // NAVIGATIONWIDGET_H
