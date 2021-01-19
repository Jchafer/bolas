#ifndef _DINFOBOLAS_H
#define _DINFOBOLAS_H

#include "ui_DInfoBolas.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QListWidget>
#include <QTimer>

class DInfoBolas : public QDialog, public Ui::DInfoBolas{
    Q_OBJECT
public:
    DInfoBolas(QVector<Bola*> * bolas, QWidget *parent = 0);

    QVector<Bola*> *listaBolas;

    QTimer * temporizador;

    QString getInfoBola(Bola *bola);

public slots:
    void slotMostrarInfo();
     
};

#endif