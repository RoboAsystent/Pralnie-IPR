#include "servercaller.h"
#include <QFile>

ServerCaller::ServerCaller(QObject *parent) : QObject(parent)
{

}

ServerCaller::~ServerCaller()
{
    qDebug() << "Destruktor callera...";
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
    //czytanie pliku
    QString val;
    QFile file;

    file.setFileName("D:/Studia/SEMVII/IPR/Pranie/Kurier-Pralnia/LocalData/Zlecenia.json"); //zmienić na prawidłową ścieżkę
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie można otworzyć jsona!!!";
        return;
    }

    val = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    //wysyłanie go dalej
    emit readOrdersFinished(doc);
}

void ServerCaller::userIsValid(bool state)
{
    if (state)
        emit AuthorizationCompleted(1);
    else
        emit AuthorizationCompleted(-1);
}
