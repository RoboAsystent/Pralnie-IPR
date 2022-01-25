#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "servercaller.h"

class ServerCaller;
class MenuWidget;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWidget; }
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

public slots:
    void onAuthorizationResult(int result);

private slots:
    void on_LogIn_clicked();

private:
    Ui::LoginWidget *ui;
    ServerCaller *s_caller = nullptr;
};
#endif // LOGINWIDGET_H
