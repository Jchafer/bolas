#ifndef _MAINWINDOW_H
#define _MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include "bola.h"
#include <QVector>
#include "dInformacion.h"
#include "dInfoBolas.h"
#include "dInfoTabla.h"
#include "dControlBolas.h"
#include "dArbolBolas.h"
#include <QAction>
#include <QDrag>
#include <QSystemTrayIcon>
#include <QChartView>
#include "dChart.h"
#include "dTablaInfo.h"
#include "dTabHijas.h"
#include "dTabDatosBolas.h"
#include "dguardarconf.h"

QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = NULL);

        void paintEvent(QPaintEvent *event);
        void inicializarBolas(int);
        void inicializarMenus();
        void keyPressEvent(QKeyEvent *event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void closeEvent(QCloseEvent *event);


        int cantidadBolas;
    
        int altoInicio;
        int anchoInicio;

        QDrag * drag;

        QSystemTrayIcon * trayIcon;
        //float posX, posY;
        //float velX, velY;

        //Bola bola;
        //Bola otraBola;
        QVector<Bola*> bolas;
        Bola *bolaJugador;

        QTimer * temporizador;

        DInformacion * dInformacion;       
        QAction *accionDInformacion;

        DInfoBolas * dInfoBolas;
        QAction *accionDInfoBolas;

        DInfoTabla * dInfoTabla;         
        QAction *accionDInfoTabla;

        DControlBolas * dControlBolas;         
        QAction *accionDControlBolas;

        DArbolBolas * dArbolBolas;         
        QAction *accionDArbolBolas;

        QMenu *menuContextual;

        QAction *accionGuardarPartida;
        QAction *accionCargarPartida;

        int initialMouseClickX;
        int initialMouseClickY;

        DChart * dChart;         
        QAction *accionDChart;

        DTablaInfo * dTablaInfo;         
        QAction *accionDTablaInfo;

        DTabHijas * dTabHijas;         
        QAction *accionDTabHijas;

        DTabDatosBolas * dTabDatosBolas;         
        QAction *acciondTabDatosBolas;

        DGuardarConf * dGuardarConf;
        QAction *accionCargarConf;

    public slots:
        void slotRepintar();    
        void slotDInformacion();
        void slotDInfoBolas();
        void slotDInfoTabla();
        void slotDControlBolas();
        void slotDArbolBolas();
        void slotChocar();
        void slotDChart();
        void slotDTabHijas();
        void slotDTabDatosBolas();

        void slotDTablaInfo();

        void slotGuardarPartida();
        void slotCargarPartida();
        void slotGuardarDatos(int, int);
        void slotCargarDatos();
    
    signals:
        void signalNuevaBola(Bola *bola);
        void jugadorChoqued();

    private:
        void performDrag();
        QPoint startPos;
};

#endif
