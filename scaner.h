#ifndef SCANER_H
#define SCANER_H

#include <QObject>
#include <QAbstractButton>
#include <QTimer>

class Scaner : public QObject
{
    Q_OBJECT
public:
    explicit Scaner();
    virtual ~Scaner();

    void startScan(QAbstractButton *button);

public slots:
    void scanFinished();

private:
    QAbstractButton *button;
    QTimer timer;
};

#endif // SCANER_H
