#ifndef _DTABLAINFO
#define _DTABLAINFO

#include "ui_DTablaInfo.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QAbstractTableModel>
#include <QTimer>


class DTablaInfo : public QDialog, public Ui::DTablaInfo{
    Q_OBJECT
public:
    DTablaInfo(QVector<Bola*> * bolas, QWidget *parent = 0);
   
     
};

class ModeloBolasInfo : public QAbstractTableModel {
    Q_OBJECT
public:
    ModeloBolasInfo(QVector<Bola*> * bolas, QObject *parent = 0);

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