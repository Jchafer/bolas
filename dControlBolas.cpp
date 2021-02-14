#include "dControlBolas.h"
#include <QDebug>
#include <QColor>
#include <QPushButton>
#include <widgetBola.h>

DControlBolas::DControlBolas(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    // bolasRecibidas = bolas;
    tabBolas->clear();

    for ( int i = 0; i < bolas->size(); i++){
        tabBolas->addTab(new WidgetBola(bolas->at(i)), QString("Bola ") + QString::number(i));
    }

    connect(pushButtonPararBola, SIGNAL(clicked()),
        this, SLOT(slotBotonParar()));

    connect(pushButtonAumVel, SIGNAL(clicked()),
        this, SLOT(slotBotonAumentarVel()));

    connect(pushButtonRedVel, SIGNAL(clicked()),
        this, SLOT(slotBotonReducirVel()));

}

void DControlBolas::slotBotonParar(){
    // Parar la bola
    if ( checkBoxPararTodas->isChecked() )
        for ( int i = 0; i < tabBolas->count(); i++){
            WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabBolas->widget(i));
            widgetBola->slotBotonParar();
    } else {
        //QWidget *widgetActual = tabBolas->currentWidget();

        WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabBolas->currentWidget());
        widgetBola->slotBotonParar();
    }

    
}

void DControlBolas::slotBolaNueva(Bola *bola){

    tabBolas->addTab(new WidgetBola(bola), QString("Bola ") + QString::number(bolasRecibidas->size()));

    /*tabBolas->clear();

    for ( int i = 0; i < bolasRecibidas->size(); i++){
        tabBolas->addTab(new WidgetBola(bolasRecibidas->at(i)), QString("Bola ") + QString::number(i));
    }*/
}

void DControlBolas::slotBotonAumentarVel(){
    WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabBolas->currentWidget());
    widgetBola->slotBotonAumentarVelocidad();
}

void DControlBolas::slotBotonReducirVel(){
    WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabBolas->currentWidget());
    widgetBola->slotBotonReducirVelocidad();
}