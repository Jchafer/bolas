#include "dChart.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>

DChart::DChart(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    temporizador = new QTimer();

    temporizador->setSingleShot(false);
    temporizador->setInterval(1000);
    
    connect(temporizador,
            SIGNAL(timeout()),
            this,SLOT(slotTemporizador()));
            temporizador->start();


    datosChart = new QChart();
    vistaChart = new QChartView(datosChart);
    
    QHBoxLayout * layout = new QHBoxLayout();

    frameChart->setLayout(layout);

    layout->addWidget(vistaChart);
    //layout->addWidget(new QPushButton("hola"));

    serie = new QLineSeries();

    serie->append(1,1);
    serie->append(2,20);
    serie->append(3,15);
    datosChart->addSeries(serie);

    axisXHorizontal = new QValueAxis;
    axisXHorizontal->setRange(0, 3);
    axisXHorizontal->setTitleText("Dias");

    axisYVertical = new QValueAxis;
    axisYVertical->setRange(0, 20);
    axisYVertical->setTitleText("Goles");
    
    datosChart->addAxis(axisXHorizontal, Qt::AlignBottom);
    datosChart->addAxis(axisYVertical, Qt::AlignLeft);
    
    serie->attachAxis(axisXHorizontal);
    serie->attachAxis(axisYVertical);
    
    connect(serie, SIGNAL(hovered(const QPointF &, bool)),
            this, SLOT(slotResaltar(const QPointF &, bool)));

    vistaChart->setRenderHint(QPainter::Antialiasing);


}

void DChart::slotResaltar(const QPointF &punto, bool estado){
    QPen pen;

    if (estado ) {
   	 pen.setColor(Qt::red);
   	 pen.setWidth(3);
   	 }
    else {
   	 pen.setColor(Qt::blue);
   	 pen.setWidth(2);
    }
    serie->setPen(pen);
}

void DChart::slotTemporizador(){
    serie->replace(  serie->count() -1 ,
   				  serie->at( serie->count() -1 ).x() + 0.5,
   				  serie->at( serie->count() -1 ).y());
    
    
    QList<QAbstractAxis*> lista = datosChart->axes(Qt::Horizontal);   
    foreach (QAbstractAxis * axis, lista  ) {
        if (axis->orientation() == Qt::Horizontal) {
            datosChart->removeAxis(axis);
            serie->detachAxis(axis);
            delete axis;
            break; // no debería hacerlo
        }
    }
   
    
   QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,serie->at( serie->count() -1 ).x() + 1 );
    axisX->setTitleText("Prueba");
    
    datosChart->addAxis(axisX,Qt::AlignBottom);
    serie->attachAxis(axisX);
}

