#include "widgetBol.h"
#include <QDebug>
#include <QMessageBox>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QImage>
#include <QColorDialog>

WidgetBol::WidgetBol(Bola *bolaRecibida, QWidget *parent) : QWidget(parent), miBola(bolaRecibida){

    setupUi(this);

    //miBola = bolaRecibida;

}

void WidgetBol::slotBotonAumentarVelocidad(){
    // Acelerar la bola
    miBola->acelerar();
}

void WidgetBol::slotBotonReducirVelocidad(){
    // Frenar la bola
    miBola->frenar();
}