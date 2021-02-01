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

        int cantidadBolas;

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

    public slots:
        void slotRepintar();    
        void slotDInformacion();
        void slotDInfoBolas();
        void slotDInfoTabla();
        void slotDControlBolas();
        void slotDArbolBolas();
        void slotChocar();

        void slotGuardarPartida();
        void slotCargarPartida();
    
    signals:
        void signalNuevaBola(Bola *bola);
        void jugadorChoqued();

    private:
        void performDrag();
        QPoint startPos;
};

#endif
