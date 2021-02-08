#include "dChart.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>

DChart::DChart(QVector<Bola*> * bolas, QWidget *parent) : QDialog(parent), bolasRecibidas(bolas){

    setupUi(this);

    datosChart = new QChart();
    vistaChart = new QChartView(datosChart);
    
    QHBoxLayout * layout = new QHBoxLayout();

    frameChart->setLayout(layout);

    layout->addWidget(vistaChart);
    //layout->addWidget(new QPushButton("hola"));

    serie = new QLineSeries();

    serie->append(1,1);
    serie->append(2,0);
    serie->append(4,6);
    datosChart->addSeries(serie);

    axisYVertical = new QValueAxis;
    axisYVertical->setRange(0, 60);
    axisYVertical->setTitleText("Goles");

    axisXHorizontal = new QValueAxis;
    axisXHorizontal->setRange(0, 60);
    axisXHorizontal->setTitleText("Dias");

    datosChart->addAxis(axisYVertical, Qt::AlignLeft);
    datosChart->addAxis(axisXHorizontal, Qt::AlignBottom);
}