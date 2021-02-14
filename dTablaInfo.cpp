#include "dTablaInfo.h"
#include <QDebug>
#include <QColor>

DTablaInfo::DTablaInfo(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent){

    setupUi(this);

    ModeloBolasInfo *m = new ModeloBolasInfo(bolas);

    tableInfo->setModel(m);

    /*connect(botonActualizar, SIGNAL(clicked()), 
            m, SLOT(slotActualizarDatos()));*/

}

ModeloBolasInfo::ModeloBolasInfo (QVector<Bola*> * bolas, QObject *parent) : QAbstractTableModel(parent){

    listaBolas = bolas;

    temporizador = new QTimer();
    temporizador->setInterval(2000);
    temporizador->setSingleShot(false);
    temporizador->start();

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotActualizarDatos()));
}

int ModeloBolasInfo::rowCount(const QModelIndex &parent) const{
    return listaBolas->size();

}

int ModeloBolasInfo::columnCount(const QModelIndex &parent) const{
    return 6;
}

QVariant ModeloBolasInfo::data(const QModelIndex & ind, int role) const{
    if ((role != Qt::DisplayRole) && (role != Qt::DecorationRole)) return QVariant();

    int column = ind.column();
    int row = ind.row();

    if (role == Qt::DecorationRole){  
        switch (column) {
            case 0: return QVariant(listaBolas->at(row)->color);
            case 3:  
                if (listaBolas->at(row)->vida <= 0)
                    return QVariant(QColor("red"));
                else
                    return QVariant(QColor("green"));              
        }
    }
    
    QString texto;

    switch (column) {
        case 0:
            texto = QString(listaBolas->at(row)->nombre);
            break;
        case 1:
            texto = QString::number(listaBolas->at(row)->colisiones);
            break;
        case 2:
            texto = QString::number(listaBolas->at(row)->coliPared);
            break;
        case 3:
            texto = QString::number(listaBolas->at(row)->vida);
            break;
        case 4:
            texto = QString::number(listaBolas->at(row)->hijas.count());
            break;
        case 5:
            if (listaBolas->at(row)->padre != NULL){
                texto = QString(listaBolas->at(row)->padre->nombre);
                break;
            }            
            texto = QString("Sin padre");
            break;
    };
    return texto;

}

QVariant ModeloBolasInfo::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) return QVariant();

    if (orientation == Qt::Vertical) return section;

    switch (section) {
        case 0: return QString("Nombre"); break;
        case 1: return QString("Colisiones"); break;
        case 2: return QString("Col. Pared"); break;
        case 3: return QString("Vida"); break;
        case 4: return QString("Cant. hijas"); break;
        case 5: return QString("Padre"); break;
    };

    return QVariant();    
    
}

void ModeloBolasInfo::slotActualizarDatos(){

    QModelIndex topLeft = index(0,0);
    QModelIndex bottomRight = index(listaBolas->size(), 3);

    emit dataChanged(topLeft, bottomRight);

    emit layoutChanged();

}
