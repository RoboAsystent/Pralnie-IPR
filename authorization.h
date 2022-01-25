#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>

class Authorization : public QObject
{
    Q_OBJECT
public:
    explicit Authorization(QObject *parent = nullptr);

signals:
    void IsUserValid(bool state);

public slots:
    void pretendAuthorization(QString username, QString password);

private:
    void checkCredentials(QString username, QString password);
};

#endif // AUTHORIZATION_H
