#include "dguardarconf.h"
#include <QVector>
#include <QString>
#include <QColor>
#include <QPushButton>
#include <QDebug>


DGuardarConf::DGuardarConf(QWidget * parent) : QDialog(parent){
    setupUi(this);

    alto = 0;
    ancho = 0;

    connect(this, SIGNAL(accepted()),
        this, SLOT(slotEnviarGuardar()));


}

void DGuardarConf::slotEnviarGuardar(){
    if(checkAlto->isChecked()){
        alto = 1;
    }
    if(checkAncho->isChecked()){
        ancho = 1;
    }
    emit guardarEsto(alto, ancho);
}