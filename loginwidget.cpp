#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QDebug>
#include "menuwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    ui->UserName->setPlaceholderText("Enter user name");
    ui->UserName->setMaxLength(20);
    ui->Password->setPlaceholderText("Enter password");
    ui->Password->setEchoMode(QLineEdit::Password);
    ui->Password->setMaxLength(32);

    this->setAttribute(Qt::WA_DeleteOnClose);

    s_caller = new ServerCaller;

    QObject::connect(s_caller, &ServerCaller::AuthorizationCompleted, this, &LoginWidget::onAuthorizationResult);

    s_caller->doAuthorize("","");
}

LoginWidget::~LoginWidget()
{
    qDebug() << "Teraz jest ten destruktor...";
    delete ui;
    if (s_caller)
        s_caller->deleteLater();
}

void LoginWidget::onAuthorizationResult(int result)
{
    if (result == 1)
    {
        MenuWidget *menu = new MenuWidget;
        menu->show();
        this->close();
    }
    else if (result == -1)
    {
        //wyświetl komunikat o błędzie
        if (!(ui->UserName->text().isEmpty() && ui->Password->text().isEmpty()))
        {
            ui->Error_label->setText("Nieprawidłowe dane!!!");
        }
        qDebug() << result;
    }

    QObject::disconnect(s_caller, &ServerCaller::AuthorizationCompleted, this, &LoginWidget::onAuthorizationResult);
    delete s_caller;
    s_caller = nullptr;
}


void LoginWidget::on_LogIn_clicked()
{
    if (!s_caller)
    {
        s_caller = new ServerCaller;

        QObject::connect(s_caller, &ServerCaller::AuthorizationCompleted, this, &LoginWidget::onAuthorizationResult);

        QString username = ui->UserName->text();
        QString password = ui->Password->text();

        s_caller->doAuthorize(username, password);
    }
    else
    {
        qDebug() << "Autoryzacja w toku, czekaj";
    }
}

