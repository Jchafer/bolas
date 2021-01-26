#ifndef _WIDGETBOLA
#define _WIDGETBOLA

#include "ui_widgetBola.h"
#include "bola.h"


class WidgetBola : public QWidget, public Ui::WidgetBola{
    Q_OBJECT
public:
    WidgetBola(Bola *bola, QWidget *parent = 0);

    Bola *miBola;

    void dragEnterEvent(QDragEnterEvent*);
    void dropEvent(QDropEvent * event);

public slots:
    void slotBotonParar();
};



#endif