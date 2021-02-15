#ifndef _DTABDATOSBOLAS
#define _DTABDATOSBOLAS

#include "ui_DTabDatosBolas.h"
#include <QDialog>
#include <QLabel>
#include <QVector>
#include "bola.h"
#include <QAbstractTableModel>
#include <QTimer>


class DTabDatosBolas : public QDialog, public Ui::DTabDatosBolas{
    Q_OBJECT
public:
    DTabDatosBolas(QVector<Bola*> * bolas, QWidget *parent = 0);
   
    QVector<Bola*> *bolasRecibidas;
public slots:
    void slotBotonAumentarVel();
    void slotBotonReducirVel();
};



#endif