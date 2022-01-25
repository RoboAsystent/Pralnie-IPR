#ifndef SERVERCALLER_H
#define SERVERCALLER_H

#include <QObject>
#include "authorization.h"

class Authorization;

class ServerCaller : public QObject
{
    Q_OBJECT
public:
    explicit ServerCaller(QObject *parent = nullptr);
    virtual ~ServerCaller();
    void doAuthorize(QString username, QString password);

signals:
    void checkIfValidUser(QString username, QString password);
    void AuthorizationCompleted(int result);

public slots:
    void userIsValid(bool state);


private:
    Authorization *auth = nullptr;
};

#endif // SERVERCALLER_H
