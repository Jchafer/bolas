#ifndef _DINFORMACION_H
#define _DINFORMACION_H

#include <QDialog>
#include <QLabel>

class DInformacion : public QDialog{
public:
    DInformacion(int cantidadBolas, QWidget *parent = nullptr);

    QLabel *etTituloNumero;
    QLabel *etTituloTamanyo;
    QLabel *etValorNumero;
    QLabel *etValorTamanyo;

    void establecerTamanyo(int anchura, int altura);
};

#endif