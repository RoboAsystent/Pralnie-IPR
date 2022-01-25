#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWidget; }
QT_END_NAMESPACE

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
    virtual ~MenuWidget();

signals:

private:
    Ui::MenuWidget *ui;
};

#endif // MENUWIDGET_H
