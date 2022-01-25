#include "authorization.h"

const int token = 0;

Authorization::Authorization(QObject *parent) : QObject(parent)
{
}

void Authorization::pretendAuthorization(QString username, QString password)
{
    checkCredentials(username, password);
}

void Authorization::checkCredentials(QString username, QString password)
{
    if (token == 0)
    {
        if (username == "Kamil" && password == "Slimak")
            emit IsUserValid(true);
        else
        {
            emit IsUserValid(false);
        }
    }
    else
    {
        emit IsUserValid(true);
    }
}
