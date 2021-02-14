#ifndef _DCONTROLBOLAS
#define _DCONTROLBOLAS

#include "ui_DControlBolas.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QAbstractTableModel>
#include <QTimer>
#include <QVector>


class DControlBolas : public QDialog, public Ui::DControlBolas{
    Q_OBJECT
public:
    DControlBolas(QVector<Bola*> * bolas, QWidget *parent = 0);
   
    QVector<Bola*> *bolasRecibidas;
public slots:
    void slotBotonParar();
    void slotBolaNueva(Bola *bola);
    void slotBotonAumentarVel();
    void slotBotonReducirVel();
};



#endif