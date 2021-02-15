#include "dTabHijas.h"
#include <QDebug>
#include <QColor>
#include <QPushButton>
#include <widgetbolatabla.h>

DTabHijas::DTabHijas(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    // bolasRecibidas = bolas;
    tabWidgetHijas->clear();

    for ( int i = 0; i < bolas->size(); i++){
        tabWidgetHijas->addTab(new WidgetBolaTabla(bolas->at(i)), bolas->at(i)->nombre);
    }

    /*connect(pushButtonPararBola, SIGNAL(clicked()),
        this, SLOT(slotBotonParar()));

    connect(pushButtonAumVel, SIGNAL(clicked()),
        this, SLOT(slotBotonAumentarVel()));

    connect(pushButtonRedVel, SIGNAL(clicked()),
        this, SLOT(slotBotonReducirVel()));*/

}

void DTabHijas::slotBolaNueva(Bola *nueva){
    tabWidgetHijas->addTab(new WidgetBolaTabla(nueva), QString("Bola "));
} 

/*void DTabHijas::slotBotonParar(){
    // Parar la bola
    if ( checkBoxPararTodas->isChecked() )
        for ( int i = 0; i < tabWidgetHijas->count(); i++){
            WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabWidgetHijas->widget(i));
            widgetBola->slotBotonParar();
    } else {
        //QWidget *widgetActual = tabBolas->currentWidget();

        WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabWidgetHijas->currentWidget());
        widgetBola->slotBotonParar();
    }

    
}

void DTabHijas::slotBolaNueva(Bola *bola){

    tabWidgetHijas->addTab(new WidgetBola(bola), QString("Bola ") + QString::number(bolasRecibidas->size()));

    tabBolas->clear();

    for ( int i = 0; i < bolasRecibidas->size(); i++){
        tabBolas->addTab(new WidgetBola(bolasRecibidas->at(i)), QString("Bola ") + QString::number(i));
    }
}

void DTabHijas::slotBotonAumentarVel(){
    WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabWidgetHijas->currentWidget());
    widgetBola->slotBotonAumentarVelocidad();
}

void DTabHijas::slotBotonReducirVel(){
    WidgetBola *widgetBola = qobject_cast<WidgetBola*>(tabWidgetHijas->currentWidget());
    widgetBola->slotBotonReducirVelocidad();
}*/