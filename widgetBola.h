#ifndef _WIDGETBOLA
#define _WIDGETBOLA

#include "ui_widgetBola.h"
#include "bola.h"
#include <QColor>


class WidgetBola : public QWidget, public Ui::WidgetBola{
    Q_OBJECT
public:
    WidgetBola(Bola *bola, QWidget *parent = 0);

    Bola *miBola;
    QColor color;

    void dragEnterEvent(QDragEnterEvent*);
    void dropEvent(QDropEvent * event);

public slots:
    void slotBotonParar();
    void slotBotonColor();
    void slotBotonAumentarVelocidad();
    void slotBotonReducirVelocidad();
};



#endif