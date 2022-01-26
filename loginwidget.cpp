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

    QObject::connect(&ServerCaller::getServerCaller(), &ServerCaller::AuthorizationCompleted, this, &LoginWidget::onAuthorizationResult);

    ServerCaller::getServerCaller().doAuthorize("","");
}

LoginWidget::~LoginWidget()
{
    qDebug() << "Teraz jest ten destruktor...";
    delete ui;
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

    QObject::disconnect(&ServerCaller::getServerCaller(), &ServerCaller::AuthorizationCompleted, this, &LoginWidget::onAuthorizationResult);
}


void LoginWidget::on_LogIn_clicked()
{
    QObject::connect(&ServerCaller::getServerCaller(), &ServerCaller::AuthorizationCompleted, this, &LoginWidget::onAuthorizationResult);

    QString username = ui->UserName->text();
    QString password = ui->Password->text();

    ServerCaller::getServerCaller().doAuthorize(username, password);
}

