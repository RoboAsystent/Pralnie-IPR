#include "authorization.h"

Authorization::Authorization(QObject *parent) : QObject(parent)
{
}

void Authorization::pretendAuthorization(QString username, QString password)
{
    checkCredentials(username, password);
}

void Authorization::checkCredentials(QString username, QString password)
{
    //sprawdza czy jest token
}
