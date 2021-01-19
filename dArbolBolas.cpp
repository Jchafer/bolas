#include "dArbolBolas.h"
#include <QDebug>

DArbolBolas::DArbolBolas(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    ModeloArbol *modeloArbol = new ModeloArbol(bolas);

    // vistaArbol->setModel(modeloArbol);

}

ModeloArbol::ModeloArbol (QVector<Bola*> * bolasRecibidas, QObject *parent) : QAbstractItemModel(parent){

    bolas = bolasRecibidas;

}

// Cantidad columnas
int ModeloArbol::columnCount(const QModelIndex &parent) const{
    return 1;
}

// Cantidad filas hay colgando de una bola(hijas)
int ModeloArbol::rowCount(const QModelIndex &parent) const{
    if (!parent.isValid()) { // Nos preguntan por las bolas raiz
        int bolasSinPadre=0;
        for (int i = 0; i < bolas->size(); i++)
            if (bolas->at(i)->padre == NULL) bolasSinPadre++;
        return bolasSinPadre;
    }
    else { // Nos preguntan cuántas hijas tiene una bola dada
        void * pPadre = parent.internalPointer();
        Bola * bolaPadre = static_cast<Bola *> (pPadre);

        return bolaPadre->hijas.size();
    }
}

// Que muestra en la celda
QVariant ModeloArbol::data(const QModelIndex &index, int role) const{
    void * pBola = index.internalPointer();
    Bola * bolaPreguntada = static_cast<Bola *> (pBola);

    return QVariant( QString::number(bolaPreguntada->posX) );
}

// Pregunta por cada hija que tenga la bola
QModelIndex ModeloArbol::index(int row, int column, const QModelIndex &parent) const{

    if (parent.isValid()){
        void * pPadre = parent.internalPointer();
        Bola * bolaPadre = static_cast<Bola *> (pPadre);

        Bola * hija = bolaPadre->hijas.at(row);

        QModelIndex indiceDevuelto = createIndex(row, column, hija);
        return indiceDevuelto;
    } else {
        int count = 0;
        for (int i = 0; i < bolas->size(); i++){
            if (bolas->at(i)->padre == NULL);
            count ++;
            if (count == row){
                QModelIndex indiceDevuelto = createIndex(row, column, bolas->at(i));
                return indiceDevuelto;
            }
        }
            
    }
    
}

QModelIndex ModeloArbol::parent(const QModelIndex &index) const{
    //void * pBola = index.internalPointer();
    //Bola * bolaPreguntada = static_cast<Bola *> (pBola);
    Bola * bolaPreguntada = static_cast<Bola *> (index.internalPointer());

    if (bolaPreguntada->padre == NULL) return QModelIndex();

    QModelIndex indiceDevuelto = createIndex(0, 0, bolaPreguntada->padre);
    return indiceDevuelto;
}

