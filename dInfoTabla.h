#ifndef _DINFOTABLA
#define _DINFOTABLA

#include "ui_DInfoTabla.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QAbstractTableModel>
#include <QTimer>


class DInfoTabla : public QDialog, public Ui::DInfoTabla{
    Q_OBJECT
public:
    DInfoTabla(QVector<Bola*> * bolas, QWidget *parent = 0);
   
     
};

class ModeloBolas : public QAbstractTableModel {
    Q_OBJECT
public:
    ModeloBolas(QVector<Bola*> * bolas, QObject *parent = 0);

    QVector<Bola*> *listaBolas;

    QTimer * temporizador; 

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

public slots:
    void slotActualizarDatos();
};

#endif