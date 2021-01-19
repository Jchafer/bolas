#include "dInfoTabla.h"
#include <QDebug>
#include <QColor>

DInfoTabla::DInfoTabla(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent){

    setupUi(this);

    ModeloBolas *m = new ModeloBolas(bolas);

    vistaTabla->setModel(m);

    connect(botonActualizar, SIGNAL(clicked()), 
            m, SLOT(slotActualizarDatos()));

}

ModeloBolas::ModeloBolas (QVector<Bola*> * bolas, QObject *parent) : QAbstractTableModel(parent){

    listaBolas = bolas;

    temporizador = new QTimer();
    temporizador->setInterval(2000);
    temporizador->setSingleShot(false);
    temporizador->start();

    connect(temporizador, SIGNAL(timeout()),
            this, SLOT(slotActualizarDatos()));
}

int ModeloBolas::rowCount(const QModelIndex &parent) const{
    return listaBolas->size();

}

int ModeloBolas::columnCount(const QModelIndex &parent) const{
    return 4;
}

QVariant ModeloBolas::data(const QModelIndex & ind, int role) const{
    if ((role != Qt::DisplayRole) && (role != Qt::DecorationRole)) return QVariant();

    int column = ind.column();
    int row = ind.row();

    if (role == Qt::DecorationRole){  
        switch (column) {
            case 0: return QVariant(listaBolas->at(row)->color);
            case 1: return QVariant(listaBolas->at(row)->color);
            case 2:
                if (listaBolas->at(row)->velX < 0)
                    return QVariant(QColor("red"));
                else
                    return QVariant(QColor("green"));
            case 3:  
                if (listaBolas->at(row)->velY < 0)
                    return QVariant(QColor("red"));
                else
                    return QVariant(QColor("green"));                    
        }
    }
    
    QString texto;

    switch (column) {
   	 case 0:
   		  texto = QString::number(listaBolas->at(row)->posX);
   		  break;
   	 case 1:
   		  texto = QString::number(listaBolas->at(row)->posY);
   		  break;
   	 case 2:
   		  texto = QString::number(listaBolas->at(row)->velX);
   		  break;
   	 case 3:
   		  texto = QString::number(listaBolas->at(row)->velY);
   		  break;
    };
    return texto;

}

QVariant ModeloBolas::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) return QVariant();

    if (orientation == Qt::Vertical) return section;

    switch (section) {
   	 case 0: return QString("PosX"); break;
   	 case 1: return QString("PosY"); break;
   	 case 2: return QString("VelX"); break;
   	 case 3: return QString("VelY"); break;
    };

    return QVariant();    
    
}

void ModeloBolas::slotActualizarDatos(){

    QModelIndex topLeft = index(0,0);
    QModelIndex bottomRight = index(listaBolas->size(), 3);

    emit dataChanged(topLeft, bottomRight);

    emit layoutChanged();

}
