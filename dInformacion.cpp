#include "dInformacion.h"
#include <QGridLayout>

DInformacion::DInformacion(int cantidadBolas, QWidget *parent) : QDialog(parent){

    QGridLayout *layout = new QGridLayout();

    etTituloNumero = new QLabel("Número de bolas: ");
    etTituloTamanyo = new QLabel("Tamanyo de la ventana: ");
    etValorNumero = new QLabel(QString::number(cantidadBolas));
    etValorTamanyo = new QLabel("0");

    layout->addWidget(etTituloNumero, 0, 0);
    layout->addWidget(etTituloTamanyo, 1, 0);
    layout->addWidget(etValorNumero, 0, 1);
    layout->addWidget(etValorTamanyo, 1, 1);

    this->setLayout(layout);
}

void DInformacion::establecerTamanyo(int anchura, int altura){
    QString cadena = QString::number(anchura) + " x " + QString::number(altura);
    etValorTamanyo->setText(cadena);
}