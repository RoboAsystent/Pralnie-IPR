#include "scaner.h"
#include <QIcon>
#include <QDebug>

Scaner::Scaner()
{
    qDebug() << "Stworzyłem skaner...";
}

Scaner::~Scaner()
{
    timer.stop();
}

void Scaner::scanFinished()
{
    qDebug() << "Po czasie";
    if (button)
    {
        QIcon icon(":/map/QRCode_wiki.png");
        button->setIcon(icon);
        button->setIconSize(QSize(335,335));
        button->setEnabled(true);
        button->setVisible(true);
    }
}

void Scaner::startScan(QAbstractButton *_button)
{
    button = _button;

    QObject::connect(&timer, &QTimer::timeout, this, &Scaner::scanFinished);

    timer.setSingleShot(true);
    timer.start(2500);
    qDebug() << "Timer wystartował";
}
