#ifndef SCANER_H
#define SCANER_H

#include <QObject>

class Scaner : public QObject
{
    Q_OBJECT
public:
    Scaner();

    void Scan();
private:

};

#endif // SCANER_H
