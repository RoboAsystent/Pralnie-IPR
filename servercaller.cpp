#include "servercaller.h"

ServerCaller::ServerCaller(QObject *parent) : QObject(parent)
{

}

ServerCaller::~ServerCaller()
{
    if (auth)
        auth->deleteLater();
}

void ServerCaller::doAuthorize(QString username, QString password)
{
    if (!auth)
    {
        auth = new Authorization;
        QObject::connect(this, &ServerCaller::checkIfValidUser, auth, &Authorization::pretendAuthorization);
        emit checkIfValidUser(username, password);
    }
    else
    {

    }
}

void ServerCaller::userIsValid(bool state, int key)
{

}
