#ifndef _DARBOLBOLAS
#define _DARBOLBOLAS

#include "ui_DArbolBolas.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QAbstractItemModel>
#include <QTimer>


class DArbolBolas : public QDialog, public Ui::DArbolBolas{
    Q_OBJECT
public:
    DArbolBolas(QVector<Bola*> * bolas, QWidget *parent = 0);
   
    QVector<Bola*> *bolasRecibidas;

};

class ModeloArbol : public QAbstractItemModel {
    Q_OBJECT
public:
    ModeloArbol(QVector<Bola*> * bolas, QObject *parent = 0);

    QVector<Bola*> *bolas;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

};

#endif