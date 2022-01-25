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
        QObject::connect(auth, &Authorization::IsUserValid, this, &ServerCaller::userIsValid);
    }
    emit checkIfValidUser(username, password);
}

void ServerCaller::readOrders()
{

}

void ServerCaller::userIsValid(bool state)
{
    if (state)
        emit AuthorizationCompleted(1);
    else
        emit AuthorizationCompleted(-1);
}
