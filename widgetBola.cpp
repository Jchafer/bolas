#include "widgetBola.h"
#include <QDebug>

WidgetBola::WidgetBola(Bola *bolaRecibida, QWidget *parent) : QWidget(parent), miBola(bolaRecibida){

    setupUi(this);

    //miBola = bolaRecibida;

    connect(pushButtonPararLaBola, SIGNAL(clicked()),
        this, SLOT(slotBotonParar()));
}

void WidgetBola::slotBotonParar(){
    // Parar la bola
    miBola->parar();
}