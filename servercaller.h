#ifndef SERVERCALLER_H
#define SERVERCALLER_H

#include <QObject>
#include <QJsonDocument>
#include "authorization.h"

class Authorization;

class ServerCaller : public QObject
{
    Q_OBJECT
public:
    static ServerCaller &getServerCaller();
    void doAuthorize(QString username, QString password);
    void openBox(int X, int Y);

signals:
    void checkIfValidUser(QString username, QString password);
    void AuthorizationCompleted(int result);
    void readOrdersFinished(const QJsonDocument &doc);

public slots:
    void userIsValid(bool state);
    void readOrders();

private:
    Authorization *auth = nullptr;
    explicit ServerCaller(QObject *parent = nullptr);
    virtual ~ServerCaller();
};

inline ServerCaller &ServerCaller::getServerCaller()
{
    static ServerCaller caller;
    return caller;
}

#endif // SERVERCALLER_H
