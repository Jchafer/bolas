#include "dInfoBolas.h"

DInfoBolas::DInfoBolas(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent){

    setupUi(this);

    temporizador = new QTimer();
    temporizador->setInterval(200);
    temporizador->setSingleShot(false);
    temporizador->start();

    listaBolas = bolas;

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotMostrarInfo()));

}

QString DInfoBolas::getInfoBola(Bola *bola){
    QString info = "Posición X -> " + QString::number(bola->posX) + ", " + 
                    "Posición Y -> " + QString::number(bola->posY) + ", " +
                    "Velocidad X -> " + QString::number(bola->velX) + ", " + 
                    "Velocidad Y -> " + QString::number(bola->velY);

    return info;
}

void DInfoBolas::slotMostrarInfo(){
    listWidgetBolas->clear();

    for (int i = 0; i < listaBolas->size(); i++)
    {
        listWidgetBolas->addItem(getInfoBola(listaBolas->at(i)));
    }
    
}
