#include "widgetbolatabla.h"
#include <QVector>
#include <QString>
#include <QColor>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QImage>
#include <bola.h>
#include <QComboBox>
#include <QFrame>
#include <QCheckBox>

WidgetBolaTabla::WidgetBolaTabla(Bola * bola, QWidget * parent) : QWidget(parent), miBola(bola){
    setupUi(this);

    temporizador = new QTimer();
    temporizador->setInterval(500);
    temporizador->setSingleShot(false);
    temporizador->start();

    ModeloBolasHijas *m = new ModeloBolasHijas(&bola->hijas);

    foreach(Bola * b, bola->hijas){
        QPixmap pix(15,15);
        pix.fill(b->color);
        QVariant datos(b->color);
        //QVariant bolaIndex = bola->hijas.indexOf(b);
        listaHijas->addItem(pix, b->nombre, datos);
    }

    tablaHijas->setModel(m);

    connect(temporizador, SIGNAL(timeout()),
        m, SLOT(slotActualizarDatosTemp()));

}

ModeloBolasHijas::ModeloBolasHijas (QVector<Bola *> * bolas, QObject * parent): QAbstractTableModel(parent){
    vector = bolas;
}

int ModeloBolasHijas::rowCount(const QModelIndex &parent) const{
    return vector->size();
}

int ModeloBolasHijas::columnCount(const QModelIndex &parent) const{
    return 10;
}

QVariant ModeloBolasHijas::data(const QModelIndex &index, int role) const{
    int fila = index.row();
    int columna = index.column();   
    
    QString dato = QString::number(fila) + QString("-") + QString::number(columna);

    if (role != Qt::DisplayRole && role != Qt::DecorationRole){
        return QVariant();
    }

    if (role == Qt::DecorationRole){  
        switch (columna) {
            case 0: return QVariant(vector->at(fila)->color);
            case 3:  
                if (vector->at(fila)->vida <= 0)
                    return QVariant(QColor("red"));
                else
                    return QVariant(QColor("green"));
            case 8:  
                if (vector->at(fila)->vida <= 0)
                    return QVariant(QColor("red"));
                else
                    return QVariant(QColor("green"));  
            case 9:  
                if (vector->at(fila)->vida <= 0)
                    return QVariant(QColor("red"));
                else
                    return QVariant(QColor("green"));                           
        }
    }    

    switch (columna){
    case 0:
        return vector->at(fila)->nombre;
        break;
    case 1:
        return vector->at(fila)->colisiones;
        break;
    case 2:
        return vector->at(fila)->coliPared;
        break;
    case 3:
        return vector->at(fila)->vida;
        break;
    case 4:
        return vector->at(fila)->hijas.size();
        break;
    case 5:
        if(vector->at(fila)->padre != NULL)
            return vector->at(fila)->padre->nombre;
        return QString("Sin padre");
        break;
    case 6:
        return vector->at(fila)->posX;
        break;
    case 7:
        return vector->at(fila)->posY;
        break;
    case 8:
        return vector->at(fila)->velX;
        break;
    case 9:
        return vector->at(fila)->velY;
        break;    
    
    };
    return QVariant(); 

}

QVariant ModeloBolasHijas::headerData(int section, Qt::Orientation orientation, int role) const{

    if (role != Qt::DisplayRole){
        return QVariant();
    }

    if (orientation == Qt::Vertical){
        return section;
    }
    
    switch (section){
        case 0:
            return QString("nombre");
            break;
        case 1:
            return QString("Colisiones");
            break;
        case 2:
            return QString("Col. pared");
            break;
        case 3:
            return QString("Vida");
            break;
        case 4:
            return QString("Hijas");
            break;
        case 5:
            return QString("Padre");
            break;
        case 6:
            return QString("PosX");
            break;
        case 7:
            return QString("PosY");
            break;
        case 8:
            return QString("VelX");
            break;
        case 9:
            return QString("VelY");
            break;    
            
    };
    return QVariant();
}


void ModeloBolasHijas::slotActualizarDatos(){
    
    emit layoutChanged();
    
}

void ModeloBolasHijas::slotActualizarDatosTemp(){
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(vector->size(), 3);
    
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
    
}


