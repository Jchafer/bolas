#include "dTabDatosBolas.h"
#include <QDebug>
#include <QColor>
#include <QPushButton>
#include "widgetBol.h"

DTabDatosBolas::DTabDatosBolas(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    tabWidgetDatosBolas->clear();

    for ( int i = 0; i < bolas->size(); i++){
        tabWidgetDatosBolas->addTab(new WidgetBol(bolas->at(i)), bolas->at(i)->nombre);
    }

    connect(pushButtonAumVel, SIGNAL(clicked()),
        this, SLOT(slotBotonAumentarVel()));

    connect(pushButtonRedVel, SIGNAL(clicked()),
        this, SLOT(slotBotonReducirVel()));

}

void DTabDatosBolas::slotBotonAumentarVel(){
    if ( checkBoxTodas->isChecked() )
        for ( int i = 0; i < tabWidgetDatosBolas->count(); i++){
            WidgetBol *widgetBol = qobject_cast<WidgetBol*>(tabWidgetDatosBolas->widget(i));
            widgetBol->slotBotonAumentarVelocidad();
    } else {
        WidgetBol *widgetBol = qobject_cast<WidgetBol*>(tabWidgetDatosBolas->currentWidget());
        widgetBol->slotBotonAumentarVelocidad();
    }
}

void DTabDatosBolas::slotBotonReducirVel(){
    if ( checkBoxTodas->isChecked() )
        for ( int i = 0; i < tabWidgetDatosBolas->count(); i++){
            WidgetBol *widgetBol = qobject_cast<WidgetBol*>(tabWidgetDatosBolas->widget(i));
            widgetBol->slotBotonReducirVelocidad();
    } else {
        WidgetBol *widgetBol = qobject_cast<WidgetBol*>(tabWidgetDatosBolas->currentWidget());
        widgetBol->slotBotonReducirVelocidad();
    }
}