#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>

class Authorization : public QObject
{
    Q_OBJECT
public:
    explicit Authorization(QObject *parent = nullptr);

signals:
    void userIsValid(bool state,int key);
    void userIsInvalid(bool state = false, int key = 0);

public slots:
    void pretendAuthorization(QString username, QString password);

private:
    void checkCredentials(QString username, QString password);
};

#endif // AUTHORIZATION_H
