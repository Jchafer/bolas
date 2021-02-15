#include "dChart.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>

DChart::DChart(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    temporizador = new QTimer();

    temporizador->setInterval(1000);
    
    connect(temporizador,
            SIGNAL(timeout()),
            this,SLOT(slotTemporizador()));
    
    


    datosChart = new QChart();
    vistaChart = new QChartView(datosChart);
    
    QHBoxLayout * layout = new QHBoxLayout();

    frameChart->setLayout(layout);

    layout->addWidget(vistaChart);
    //layout->addWidget(new QPushButton("hola"));make

    

    /*serie = new QLineSeries();

    serie->append(0,0);
    //serie->append(2,20);
    //serie->append(3,15);
    datosChart->addSeries(serie);*/

    axisXHorizontal = new QValueAxis;
    axisXHorizontal->setRange(0, 1);
    axisXHorizontal->setTitleText("Tiempo");

    axisYVertical = new QValueAxis;
    axisYVertical->setRange(0, 1);
    axisYVertical->setTitleText("Colisiones");
    
    datosChart->addAxis(axisXHorizontal, Qt::AlignBottom);
    datosChart->addAxis(axisYVertical, Qt::AlignLeft);
    
    //serie->attachAxis(axisXHorizontal);
    //serie->attachAxis(axisYVertical);
    
    /*connect(serie, SIGNAL(hovered(const QPointF &, bool)),
            this, SLOT(slotResaltar(const QPointF &, bool)));*/

    vistaChart->setRenderHint(QPainter::Antialiasing);

    for (int i = 0; i < bolas->size(); i++)
    {
        serie = new QLineSeries();

        series.append(serie);
        datosChart->addSeries(serie);
        serie->append(0,0);
        serie->attachAxis(axisXHorizontal);
        serie->attachAxis(axisYVertical);
    }

    temporizador->start();

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

    int colisiones = 0;
    int totalColisiones = 0;
    static int count;
    count++;

    for (int i = 0; i < bolasRecibidas->size(); i++){
        totalColisiones += bolasRecibidas->at(i)->colisiones; 
    }
    
    //serie->append(count, totalColisiones);
    
    

    /*serie->replace(  serie->count() -1 ,
   				  serie->at( serie->count() -1 ).x() + totalColisiones,
   				  serie->at( serie->count() -1 ).y() + 1);*/
    
    
    QList<QAbstractAxis*> lista = datosChart->axes(Qt::Horizontal);   
    foreach (QAbstractAxis * axis, lista  ) {
        if (axis->orientation() == Qt::Horizontal) {           
            serie->detachAxis(axis);
            datosChart->removeAxis(axis);
            delete axis;
            break;
        }
    }

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, count + 1 );
    axisX->setTitleText("Tiempo");
    
    datosChart->addAxis(axisX,Qt::AlignBottom);
    //serie->attachAxis(axisX);


    lista = datosChart->axes(Qt::Vertical);   
    foreach (QAbstractAxis * axis, lista ) {
        if (axis->orientation() == Qt::Vertical) {
            serie->detachAxis(axis);
            datosChart->removeAxis(axis);            
            delete axis;
            break;
        }
    }
   
    for (int i = 0; i < bolasRecibidas->size(); i++){
        if (colisiones <= bolasRecibidas->at(i)->colisiones)
            colisiones = bolasRecibidas->at(i)->colisiones;
    }

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, colisiones + 1 );
    axisY->setTitleText("Colisiones");
    
    datosChart->addAxis(axisY,Qt::AlignLeft);
    //serie->attachAxis(axisY);

    for (int j = 0; j < series.size(); j++){
        series.at(j)->append(count, bolasRecibidas->at(j)->colisiones);
        series.at(j)->attachAxis(axisX);
        series.at(j)->attachAxis(axisY);
        connect(series.at(j), SIGNAL(hovered(const QPointF &, bool)),
            this, SLOT(slotResaltar(const QPointF &, bool)));
        
    }
}

