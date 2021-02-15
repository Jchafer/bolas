#ifndef _DTABHIJAS
#define _DTABHIJAS

#include "ui_DTabHijas.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QAbstractTableModel>
#include <QTimer>


class DTabHijas : public QDialog, public Ui::DTabHijas{
    Q_OBJECT
public:
    DTabHijas(QVector<Bola*> * bolas, QWidget *parent = 0);
   
    QVector<Bola*> *bolasRecibidas;
public slots:
    /*void slotBotonParar();
    void slotBolaNueva(Bola *bola);
    void slotBotonAumentarVel();
    void slotBotonReducirVel();*/
    void slotBolaNueva(Bola *);
};



#endif