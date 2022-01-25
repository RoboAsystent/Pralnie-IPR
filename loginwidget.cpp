#include "loginwidget.h"
#include "ui_loginwidget.h"

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
}

LoginWidget::~LoginWidget()
{
    delete ui;
    if (s_caller)
        s_caller->deleteLater();
}


void LoginWidget::on_LogIn_clicked()
{
    if (!s_caller)
    {
        s_caller = new ServerCaller;
    }
}

