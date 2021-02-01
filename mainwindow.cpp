#include "mainwindow.h"
#include <QPainter>
#include <QtMath>
#include <QBrush>
#include <QMenuBar>
#include <QMenu>
#include <QDebug>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDrag>
#include <QPoint>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    resize(800, 600);

    Bola::vidaInicial = 100;

    temporizador = new QTimer();
    temporizador->setInterval(10);
    temporizador->setSingleShot(false);
    temporizador->start();

    cantidadBolas = 10;
    inicializarBolas(cantidadBolas);
    inicializarMenus();

    connect(temporizador, SIGNAL(timeout()),
        this, SLOT(slotRepintar()));

    dInformacion = NULL;
    dInfoBolas = NULL;
    dInfoTabla = NULL;
    dControlBolas = NULL;
    dArbolBolas = NULL;

    drag = NULL;

    trayIcon = NULL;
    /*bola = Bola(100, 100, 0.2, 0.5);
    otraBola = Bola(200, 200, 0.5, 0.8);*/

    initialMouseClickY = 0;
    initialMouseClickY = 0;

    if ( QSystemTrayIcon::isSystemTrayAvailable()  == true ) {
   	 trayIcon = new QSystemTrayIcon(this);
   	 trayIcon->setContextMenu(menuContextual);
   	 trayIcon->setIcon(QIcon("./png/parpadeo.png"));
   	 trayIcon->show();
   	 connect(this,SIGNAL(jugadorChoqued()),this,SLOT(slotChocar()));    
    }

}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter pintor(this);    
    //pintor.fillRect(posX,posY,posicion,200,QColor("red"));
    
    foreach( Bola *bola, bolas){
        bola->pintar(pintor);
    }

    bolaJugador->pintar(pintor);

    /*for (int i = 0; i < bolas.length(); i++)
    {
       bolas.at(i)->pintar();

    }*/


    /*bola.pintar(pintor);    
    otraBola.pintar(pintor);*/
   
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Up)
        bolaJugador->velY = bolaJugador->velY - 0.05;
    if (event->key() == Qt::Key_Down)
        bolaJugador->velY = bolaJugador->velY + 0.05;
    if (event->key() == Qt::Key_Left)
        bolaJugador->velX = bolaJugador->velX - 0.05;
    if (event->key() == Qt::Key_Right)
        bolaJugador->velX = bolaJugador->velX + 0.05;
    
}

void MainWindow::mousePressEvent(QMouseEvent *event){    
    initialMouseClickX = event->x();
    initialMouseClickY = event->y();

    /*if (event->button() == Qt::LeftButton){
        startPos = event->pos();
    }
    QMainWindow::mousePressEvent(event);

    if (event->button() == Qt::RightButton){
        initialMouseClickX=event->x();
        initialMouseClickY=event->y();
    }*/

    drag = NULL;

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    // float finalMouseClickX = event->x();
    // float finalMouseClickY = event->y();

    bolas.append(new Bola(initialMouseClickX, initialMouseClickY, 
    (float) (event->x() - initialMouseClickX) / width() *10,
    (float) (event->y() - initialMouseClickY) / height() *10));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
        QPoint posInicial(initialMouseClickX, initialMouseClickY);
        QPoint posFinal = event->pos();
        int distance = (posFinal - posInicial).manhattanLength();

        if (distance > QApplication::startDragDistance()) return;
    
        if (drag == NULL){
            QMimeData * mimeData = new QMimeData;
            QPixmap pixmap(size());
            this->render(&pixmap);
            mimeData->setImageData(pixmap);

            drag = new QDrag(this);
            drag->setMimeData(mimeData);
            //drag->setPixmap(QPixmap("mai_ok.png"));
            drag->exec(Qt::MoveAction);
        }
        

        /*if (event->button() & Qt::LeftButton) {
            int distance = (event->pos() - startPos).manhattanLength();
            if (distance >= QApplication::startDragDistance())
            performDrag();
        }
        QMainWindow::mouseMoveEvent(event);*/
}

void MainWindow::performDrag(){

        QMimeData *mimeData = new QMimeData;
        mimeData->setText(QString("hola"));

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap("./png/abrupt-boy-face.png"));
        drag->exec(Qt::MoveAction) ;
}

void MainWindow::inicializarBolas(int cantidadBolas){
    for (int i = 0; i < cantidadBolas; i++)
    {
        bolas.append(new Bola(random()%width(),
                                random()%height(),
                                (0.1 + random()%50) / 50.1,
                                (0.1 + random()%50) / 50.1));
       /*Bola bola = new Bola(100, 100, 0.2, 0.5);
       bolas.push_back(*bola);*/

    }

    bolaJugador = new Bola(100, 100, 0, 0);
    bolaJugador->color = QColor("black");

    // bolas.append(bolaJugador);
}

void MainWindow::inicializarMenus(){
    QMenu *menuFichero = menuBar()->addMenu("Fichero");

    accionDInformacion = new QAction("Información Básica", this);
    //accionDInformacion->setIcon(QIcon("./icons/salir.png"));
    //accionDInformacion->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDInformacion->setToolTip("Información básica");              // Texto sobre el icono
    accionDInformacion->setStatusTip("Información del editor"); // Texto en la barra de estado.

    connect(accionDInformacion, SIGNAL(triggered()),
            this, SLOT(slotDInformacion()));

    accionDInfoBolas = new QAction("Información Detallada", this);
    //accionDInfoBolas->setIcon(QIcon("./icons/salir.png"));
    //accionDInfoBolas->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDInfoBolas->setToolTip("Información detallada");              // Texto sobre el icono
    accionDInfoBolas->setStatusTip("Información del editor"); // Texto en la barra de estado.

    connect(accionDInfoBolas, SIGNAL(triggered()),
            this, SLOT(slotDInfoBolas()));

    accionDInfoTabla = new QAction("Información Detallada Tabla", this);
    //accionDInfoTabla->setIcon(QIcon("./icons/salir.png"));
    //accionDInfoTabla->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDInfoTabla->setToolTip("Información detallada");              // Texto sobre el icono
    accionDInfoTabla->setStatusTip("Información del editor"); // Texto en la barra de estado.

    connect(accionDInfoTabla, SIGNAL(triggered()),
            this, SLOT(slotDInfoTabla()));

    accionDControlBolas = new QAction("Control bolas", this);
    //accionDControlBolas->setIcon(QIcon("./icons/salir.png"));
    //accionDControlBolas->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDControlBolas->setToolTip("Control bolas");              // Texto sobre el icono
    accionDControlBolas->setStatusTip("Control de todas las bolas"); // Texto en la barra de estado.

    connect(accionDControlBolas, SIGNAL(triggered()),
            this, SLOT(slotDControlBolas()));

    accionDArbolBolas = new QAction("Arbol bolas", this);
    //accionDArbolBolas->setIcon(QIcon("./icons/salir.png"));
    //accionDArbolBolas->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDArbolBolas->setToolTip("Arbol bolas");              // Texto sobre el icono
    accionDArbolBolas->setStatusTip("Arbol de todas las bolas"); // Texto en la barra de estado.

    connect(accionDArbolBolas, SIGNAL(triggered()),
            this, SLOT(slotDArbolBolas()));

    accionGuardarPartida = new QAction("Guardar partida", this);
    //accionDArbolBolas->setIcon(QIcon("./icons/salir.png"));
    //accionDArbolBolas->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionGuardarPartida->setToolTip("Guardar partida");              // Texto sobre el icono
    accionGuardarPartida->setStatusTip("GUardar partida de bolas"); // Texto en la barra de estado.

    connect(accionGuardarPartida, SIGNAL(triggered()),
            this, SLOT(slotGuardarPartida()));

    accionCargarPartida = new QAction("Cargar partida", this);
    //accionCargarPartida->setIcon(QIcon("./icons/salir.png"));
    //accionCargarPartida->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionCargarPartida->setToolTip("Cargar partida");              // Texto sobre el icono
    accionCargarPartida->setStatusTip("Cargar partida de bolas"); // Texto en la barra de estado.

    connect(accionCargarPartida, SIGNAL(triggered()),
            this, SLOT(slotCargarPartida()));


    menuContextual = new QMenu("Contextual");
    menuContextual->addAction(accionDInformacion);

    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->addAction(accionDInfoBolas);


    menuFichero->addAction(accionDInformacion);
    menuFichero->addAction(accionDInfoBolas);
    menuFichero->addAction(accionDInfoTabla);
    menuFichero->addAction(accionDControlBolas);
    menuFichero->addAction(accionDArbolBolas);
    menuFichero->addAction(accionGuardarPartida);
    menuFichero->addAction(accionCargarPartida);
}

void MainWindow::slotRepintar(){
    // Pedir al motor Qt que repinte la ventana de
    foreach( Bola *bola, bolas){
        bola->mover(width(),height());
        
    }

    for (int i = 0; i < bolas.size(); i++){
        for (int j = 0; j < bolas.size(); j++){
            if (bolas.at(i) != bolas.at(j)){
                if (bolas.at(i)->choca(bolas.at(j))){
                    bolas.at(i)->vida --;
                    bolas.at(j)->vida --;
                    if (bolas.size()<25){
                        int numero=random()%100;
                        if (numero<5){
                            Bola *nueva = new Bola(bolas.at(i)->posX+20, bolas.at(i)->posY-20, 
                            ((0.1+random()%50) / 50.1) -0.5, ((0.1+random()%50) / 50.1) -0.5);
                            nueva->padre = bolas.at(i);
                            bolas.at(i)->hijas.append(nueva);

                            bolas.append(nueva);
                            emit signalNuevaBola(nueva);
                            
                            // guarrada dControlBolas->tabBolas->addTab(new WidgetBola(...));
                        }
                    }
                }
            }            
        }
    }

    /*for (int i = 0; i < bolas.size(); i++){
        if (bolas.at(i) != bolas.at(j)){
            if (bolas.at(i)->choca(bolas.at(j))){
                bolas.at(i)->vidaInicial --;
                bolas.at(j)->vidaInicial --;
            }
        }
    }*/
    
    if (dInformacion != NULL)
        dInformacion->establecerTamanyo(width(), height());
    
    for (int i = 0; i < bolas.size(); i++){
       if (bolaJugador->choca(bolas.at(i))){
           bolaJugador->vida--;
           bolas.at(i)->vida--;
           emit jugadorChoqued();
       }

    }

    /*bola.mover(width(),height());
    otraBola.mover(width(),height());*/

    bolaJugador->mover(width(),height());

    update();
}

void MainWindow::slotDInformacion(){
    if (dInformacion == NULL)
        dInformacion = new DInformacion(bolas.size(), this);

    //dInformacion->establecerTamanyo(width(), height());

    dInformacion->show();
    
}

void MainWindow::slotDInfoBolas(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dInfoBolas == NULL)
        dInfoBolas = new DInfoBolas(punteroABolas);

    dInfoBolas->show();
    
}

void MainWindow::slotDInfoTabla(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dInfoTabla == NULL)
        dInfoTabla = new DInfoTabla(punteroABolas);

    dInfoTabla->show();
    
}

void MainWindow::slotDControlBolas(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dControlBolas == NULL){
        dControlBolas = new DControlBolas(punteroABolas);

        connect(this, SIGNAL(signalNuevaBola(Bola *)),
            dControlBolas, SLOT(slotBolaNueva(Bola *)));
    }

    dControlBolas->show();
    
}

void MainWindow::slotDArbolBolas(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dArbolBolas == NULL){
        dArbolBolas = new DArbolBolas(punteroABolas);

    }

    dArbolBolas->show();
    
}

void MainWindow::slotChocar(){
    if (trayIcon == NULL) return;
    trayIcon->showMessage(QString("CUIDADO! Choque!"),
                        QString("Juega mejor! que te van a matar"),
                        QSystemTrayIcon::Information, 1000);

}

void MainWindow::slotGuardarPartida(){

    QJsonObject jsonPrincipal;

    QJsonObject jsonJugador;
    jsonJugador["x"] = bolaJugador->posX;
    jsonJugador["y"] = bolaJugador->posY;

    jsonPrincipal["jugador"] = jsonJugador;

    QJsonArray arrayBolas;
    for (Bola* bola : bolas){
        QJsonObject bolaJson;

        bolaJson["x"] = bola->posX;
        bolaJson["y"] = bola->posY;

        arrayBolas.append(bolaJson);
    }

    jsonPrincipal["bolas"] = arrayBolas;


    // Proceso de creación del fichero
    QFile saveFile(QStringLiteral("save.json"));
    saveFile.open(QIODevice::WriteOnly);
    QJsonDocument saveDoc(jsonPrincipal);
    saveFile.write(saveDoc.toJson());
    saveFile.close();

}

void MainWindow::slotCargarPartida(){

    

}
