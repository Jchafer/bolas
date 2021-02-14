#ifndef _DCHART
#define _DCHART

#include "ui_DChart.h"
#include "bola.h"
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QTimer>

QT_CHARTS_USE_NAMESPACE

class DChart : public QDialog, public Ui::DChart{
    Q_OBJECT
public:
    DChart(QVector<Bola*> * bolas, QWidget *parent = 0);
   
    QVector<Bola*> *bolasRecibidas;
    QVector<QLineSeries*> series; 

    QChartView * vistaChart;
    QChart * datosChart;
    QLineSeries * serie;
    QValueAxis * axisXHorizontal;
    QValueAxis * axisYVertical;
    QTimer * temporizador;

public slots:
    void slotResaltar(const QPointF &, bool estado);
    void slotTemporizador();
};

#endif 