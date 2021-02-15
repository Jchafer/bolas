#ifndef _WIDGETBOL
#define _WIDGETBOL

#include "ui_widgetBol.h"
#include "bola.h"
#include <QColor>


class WidgetBol : public QWidget, public Ui::WidgetBol{
    Q_OBJECT
public:
    WidgetBol(Bola *bola, QWidget *parent = 0);

    Bola *miBola;
    QColor color;

public slots:
    void slotBotonAumentarVelocidad();
    void slotBotonReducirVelocidad();
};



#endif