#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QWidget>

class NavigationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NavigationWidget(QWidget *parent = nullptr);
    virtual ~NavigationWidget();

    void setPrev(QWidget *widget);
    QWidget *getPrev();

    void setRoot(QWidget *widget);
    QWidget *getRoot();

    void goBack();
    void goToRoot();

    void setCredentials(const QString _cred);
    QString getCredentials();

private:
    QWidget *prev = nullptr;
    QWidget *root = nullptr;

    QString cred;

signals:

};

#endif // NAVIGATIONWIDGET_H
