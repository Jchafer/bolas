#include "widgetBola.h"
#include <QDebug>
#include <QMessageBox>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QImage>
#include <QColorDialog>

WidgetBola::WidgetBola(Bola *bolaRecibida, QWidget *parent) : QWidget(parent), miBola(bolaRecibida){

    setupUi(this);

    //miBola = bolaRecibida;

    connect(pushButtonPararLaBola, SIGNAL(clicked()),
        this, SLOT(slotBotonParar()));

    connect(pushButtonElegirColor, SIGNAL(clicked()),
        this, SLOT(slotBotonColor()));

    connect(pushButtonAumVel, SIGNAL(clicked()),
        this, SLOT(slotBotonAumentarVelocidad()));

    connect(pushButtonRedVel, SIGNAL(clicked()),
        this, SLOT(slotBotonReducirVelocidad()));

    setAcceptDrops(true);
}

void WidgetBola::dragEnterEvent ( QDragEnterEvent * event ) {
    event->acceptProposedAction();
}

void WidgetBola::dropEvent ( QDropEvent * event ){

    //averiguar qué tipo mime tiene event ó verificar que si es de texto
    //if ( ! event->mimeData()->hasUrls() ) return;
    if ( ! event->mimeData()->hasText() ) return;

    // sacar el texto y mostrarlo en el cumessachbocs siguienteí
    QString text = (event->mimeData()->urls()).first().path();

    /*QMessageBox::warning(this, tr("DropEvent triggered"),
                                tr("El archivo arrastrado es") + text,
                                QMessageBox::Save | QMessageBox::Discard,
                                QMessageBox::Cancel,
                                QMessageBox::Save);*/

    miBola->imagen = QImage(text);
    miBola->imagen = miBola->imagen.scaled(Bola::diametro, Bola::diametro);

}

void WidgetBola::slotBotonParar(){
    // Parar la bola
    miBola->parar();
}

void WidgetBola::slotBotonColor(){
    // Cambiar el color de la bola
    QColorDialog colorDialog;

    color = colorDialog.getColor();
    qDebug() <<color;
    miBola->cambiarColor(color);
}

void WidgetBola::slotBotonAumentarVelocidad(){
    // Acelerar la bola
    miBola->acelerar();
}

void WidgetBola::slotBotonReducirVelocidad(){
    // Frenar la bola
    miBola->frenar();
}