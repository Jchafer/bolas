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
#include <QByteArray>
#include <QBuffer>

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
    dChart = NULL;
    dTablaInfo = NULL;
    dTabHijas = NULL;
    dTabDatosBolas = NULL;
    dGuardarConf = NULL;

    drag = NULL;

    trayIcon = NULL;
    /*bola = Bola(100, 100, 0.2, 0.5);
    otraBola = Bola(200, 200, 0.5, 0.8);*/

    initialMouseClickY = 0;
    initialMouseClickY = 0;
    altoInicio = height();
    anchoInicio = width();

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

void MainWindow::closeEvent(QCloseEvent *event){
    //slotGuardarDatos();
    if (dGuardarConf == NULL){
        dGuardarConf = new DGuardarConf();

        connect(dGuardarConf, SIGNAL(guardarEsto(int, int)),
                this, SLOT(slotGuardarDatos(int, int)));
    }

    dGuardarConf->exec();
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
    (float) (event->y() - initialMouseClickY) / height() *10,
    QString("Bola ") + QString::number(bolas.size())));
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
        bolas.append(new Bola(random()%width() - 100,
                                random()%height() - 100,
                                (0.1 + random()%50) / 50.1,
                                (0.1 + random()%50) / 50.1,
                                QString("Bola ") + QString::number(i)));
       /*Bola bola = new Bola(100, 100, 0.2, 0.5);
       bolas.push_back(*bola);*/

    }

    bolaJugador = new Bola(100, 100, 0, 0, "Bola Jugador");
    bolaJugador->color = QColor("black");

    // bolas.append(bolaJugador);
}

void MainWindow::inicializarMenus(){
    QMenu *menuFichero = menuBar()->addMenu("Fichero");
    QMenu *menuInformacion = menuBar()->addMenu("Información");
    QMenu *menuPrueba = menuBar()->addMenu("Prueba");

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

    accionDChart = new QAction("Grafico", this);
    //accionDChart->setIcon(QIcon("./icons/salir.png"));
    //accionDChart->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDChart->setToolTip("Grafico");              // Texto sobre el icono
    accionDChart->setStatusTip("Grafico"); // Texto en la barra de estado.

    connect(accionDChart, SIGNAL(triggered()),
            this, SLOT(slotDChart()));

    accionDTablaInfo = new QAction("Datos Prueba", this);
    //accionDTablaInfo->setIcon(QIcon("./icons/salir.png"));
    //accionDTablaInfo->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDTablaInfo->setToolTip("Datos de bolas");              // Texto sobre el icono
    accionDTablaInfo->setStatusTip("Datos de bolas"); // Texto en la barra de estado.

    connect(accionDTablaInfo, SIGNAL(triggered()),
            this, SLOT(slotDTablaInfo()));

    accionDTabHijas = new QAction("Datos Hijas", this);
    //accionDTabHijas->setIcon(QIcon("./icons/salir.png"));
    //accionDTabHijas->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionDTabHijas->setToolTip("Datos de bolas hijas");              // Texto sobre el icono
    accionDTabHijas->setStatusTip("Datos de bolas hijas"); // Texto en la barra de estado.

    connect(accionDTabHijas, SIGNAL(triggered()),
            this, SLOT(slotDTabHijas()));

    acciondTabDatosBolas = new QAction("Datos Bolas", this);
    //acciondTabDatosBolas->setIcon(QIcon("./icons/salir.png"));
    //acciondTabDatosBolas->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    acciondTabDatosBolas->setToolTip("Datos de las bolas");              // Texto sobre el icono
    acciondTabDatosBolas->setStatusTip("Datos de las bolas"); // Texto en la barra de estado.

    connect(acciondTabDatosBolas, SIGNAL(triggered()),
            this, SLOT(slotDTabDatosBolas()));                           

    accionCargarConf = new QAction("Cargar configuración", this);
    //accionCargarConf->setIcon(QIcon("./icons/salir.png"));
    //accionCargarConf->setShortcut(QKeySequence::Quit);  // Ctrl+Q
    accionCargarConf->setToolTip("Cargar datos");              // Texto sobre el icono
    accionCargarConf->setStatusTip("Cargar datos"); // Texto en la barra de estado.

    connect(accionCargarConf, SIGNAL(triggered()),
            this, SLOT(slotCargarDatos()));

    menuContextual = new QMenu("Contextual");
    menuContextual->addAction(accionDInformacion);

    this->setContextMenuPolicy(Qt::ActionsContextMenu);
    this->addAction(accionDInfoBolas);

    menuFichero->addAction(accionDControlBolas);
    menuFichero->addAction(accionDArbolBolas);
    menuFichero->addAction(accionGuardarPartida);
    menuFichero->addAction(accionCargarPartida);
    menuFichero->addAction(accionDChart);

    menuInformacion->addAction(accionDInformacion);
    menuInformacion->addAction(accionDInfoBolas);
    menuInformacion->addAction(accionDInfoTabla);

    menuPrueba->addAction(accionDTablaInfo);
    menuPrueba->addAction(accionDTabHijas);
    menuPrueba->addAction(acciondTabDatosBolas);
    menuPrueba->addAction(accionCargarConf);
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
                            ((0.1+random()%50) / 50.1) -0.5,
                            ((0.1+random()%50) / 50.1) -0.5,
                            QString("Bola ") + QString::number(bolas.size()));
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

void MainWindow::slotDChart(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dChart == NULL){
        dChart = new DChart(punteroABolas);

    }

    dChart->show();
}

void MainWindow::slotDTablaInfo(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dTablaInfo == NULL)
        dTablaInfo = new DTablaInfo(punteroABolas);

    dTablaInfo->show();
}

void MainWindow::slotDTabHijas(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dTabHijas == NULL)
        dTabHijas = new DTabHijas(punteroABolas);

    dTabHijas->show();
}

void MainWindow::slotDTabDatosBolas(){
    QVector<Bola*> *punteroABolas = &bolas;
    if (dTabDatosBolas == NULL)
        dTabDatosBolas = new DTabDatosBolas(punteroABolas);

    dTabDatosBolas->show();
}

void MainWindow::slotGuardarPartida(){

    QJsonObject jsonPrincipal;

    QJsonObject jsonJugador;
    
    jsonJugador["posX"] = bolaJugador->posX;
    jsonJugador["posY"] = bolaJugador->posY;
    jsonJugador["velX"] = bolaJugador->velX;
    jsonJugador["velY"] = bolaJugador->velY;
    jsonJugador["vida"] = bolaJugador->vida;
    jsonJugador["colisionesBolas"] = bolaJugador->colisiones;
    jsonJugador["colisionesPared"] = bolaJugador->coliPared;

    QImage img = bolaJugador->imagen;
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    img.save(&buffer, "PNG");
    QString imgBase64 = QString::fromLatin1(byteArray.toBase64().data());
    
    jsonJugador["imagen"] = imgBase64;

    jsonJugador["nombre"] = bolaJugador->nombre;

    QJsonObject colorJsonJugador;
        colorJsonJugador["red"] = bolaJugador->color.red();
        colorJsonJugador["green"] = bolaJugador->color.green();
        colorJsonJugador["blue"] = bolaJugador->color.blue();

        jsonJugador["color"] = colorJsonJugador;

    jsonPrincipal["jugador"] = jsonJugador;

    QJsonArray arrayBolas;
    for (Bola* bola : bolas){
        QJsonObject bolaJson;

        bolaJson["posX"] = bola->posX;
        bolaJson["posY"] = bola->posY;
        bolaJson["velX"] = bola->velX;
        bolaJson["velY"] = bola->velY;
        bolaJson["vida"] = bola->vida;
        bolaJson["colisionesBolas"] = bola->colisiones;
        bolaJson["colisionesPared"] = bola->coliPared;

        if (bola->padre != NULL)
            bolaJson["padre"] = bola->padre->nombre;
        else
            bolaJson["padre"] = "Sin padre";

        QImage img = bola->imagen;
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        img.save(&buffer, "PNG");
        QString imgBase64 = QString::fromLatin1(byteArray.toBase64().data());
        
        bolaJson["imagen"] = imgBase64;

        bolaJson["nombre"] = bola->nombre;

        QJsonObject colorJson;
        colorJson["red"] = bola->color.red();
        colorJson["green"] = bola->color.green();
        colorJson["blue"] = bola->color.blue();

        bolaJson["color"] = colorJson;

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
    for (Bola* bola : bolas){
        delete bola;
    }
    bolas.clear();

    // Proceso de lectura del fichero
    QFile loadFile(QStringLiteral("save.json"));

    if (!loadFile.open(QIODevice::ReadOnly))
        return;
    
    QByteArray savedData = loadFile.readAll();

    QJsonDocument readDoc(QJsonDocument::fromJson(savedData));
    QJsonObject jsonPrincipal = readDoc.object();
    if (! jsonPrincipal.contains("bolas") && jsonPrincipal["bolas"].isArray()){
        qDebug() << "Cargar partida: bolas no encontradas en archivo";
        return;
    }

    QJsonArray arrayBolas = jsonPrincipal["bolas"].toArray();
    for (int i = 0; i < arrayBolas.size(); i++){
        QJsonObject objetoBola = arrayBolas[i].toObject();

        float posXNuevaBola = objetoBola["posX"].toDouble();
        float posYNuevaBola = objetoBola["posY"].toDouble();
        float velXNuevaBola = objetoBola["velX"].toDouble();
        float velYNuevaBola = objetoBola["velY"].toDouble();
        QString nombreBola = objetoBola["nombre"].toString();

        Bola * nuevaBola = new Bola(posXNuevaBola, posYNuevaBola, 
                            velXNuevaBola, velYNuevaBola, nombreBola);
        
        QString nombrePadre = objetoBola["padre"].toString();
        foreach (Bola* b, bolas){
            if (nombrePadre == b->nombre){
                    b->hijas.append(nuevaBola);
                    nuevaBola->padre = b;
            }
        }

        QImage imagenNB;
        // Leer el elemento json y convertirlo
        QString imgBase64 = objetoBola["imagen"].toString();
        QByteArray byteArray = imgBase64.toLatin1();
        byteArray = QByteArray::fromBase64(byteArray, QByteArray::Base64Encoding);
        QBuffer buffer(&byteArray);

        imagenNB.loadFromData(byteArray, "PNG");
        nuevaBola->imagen = imagenNB;

        int vidaNuevaBola = objetoBola["vida"].toInt();
        nuevaBola->vida = vidaNuevaBola;

        QJsonObject objetoColor = objetoBola["color"].toObject();
        int colorRojoNuevaBola = objetoColor["red"].toInt();
        int colorVerdeNuevaBola = objetoColor["green"].toInt();
        int colorAzulNuevaBola = objetoColor["blue"].toInt();
        nuevaBola->color.setRgb(colorRojoNuevaBola, colorVerdeNuevaBola, colorAzulNuevaBola);

        int colisionesBola = objetoBola["colisionesBola"].toInt();
        nuevaBola->colisiones = colisionesBola;

        int colisionesPared = objetoBola["colisionesPared"].toInt();
        nuevaBola->coliPared = colisionesPared;

        bolas.append(nuevaBola);
    }

    QJsonObject objetoJugador = jsonPrincipal["jugador"].toObject();
    float posXNuevaBola = objetoJugador["posX"].toDouble();
    float posYNuevaBola = objetoJugador["posY"].toDouble();
    float velXNuevaBola = objetoJugador["velX"].toDouble();
    float velYNuevaBola = objetoJugador["velY"].toDouble();
    QString nombreBola = objetoJugador["nombre"].toString();

    Bola * nuevaBolaJugador = new Bola(posXNuevaBola, posYNuevaBola, 
                        velXNuevaBola, velYNuevaBola, nombreBola);

    QImage imagenNB;
    // Leer el elemento json y convertirlo
    QString imgBase64 = objetoJugador["imagen"].toString();
    QByteArray byteArray = imgBase64.toLatin1();
    byteArray = QByteArray::fromBase64(byteArray, QByteArray::Base64Encoding);
    QBuffer buffer(&byteArray);

    imagenNB.loadFromData(byteArray, "PNG");
    nuevaBolaJugador->imagen = imagenNB;

    int vidaNuevaBola = objetoJugador["vida"].toInt();
    nuevaBolaJugador->vida = vidaNuevaBola;

    QJsonObject objetoColor = objetoJugador["color"].toObject();
    int colorRojoNuevaBola = objetoColor["red"].toInt();
    int colorVerdeNuevaBola = objetoColor["green"].toInt();
    int colorAzulNuevaBola = objetoColor["blue"].toInt();
    nuevaBolaJugador->color.setRgb(colorRojoNuevaBola, colorVerdeNuevaBola, colorAzulNuevaBola);

    int colisionesBolaJugador = objetoJugador["colisionesBola"].toInt();
    nuevaBolaJugador->colisiones = colisionesBolaJugador;

    int colisionesParedJugador = objetoJugador["colisionesPared"].toInt();
    nuevaBolaJugador->coliPared = colisionesParedJugador;

    bolaJugador = nuevaBolaJugador;

    loadFile.close();
}

void MainWindow::slotGuardarDatos(int gAlto, int gAncho){

    QJsonObject jsonPrincipal;

    QJsonObject jsonDatos;
    
    //jsonDatos["alto"] = this->height();
    //jsonDatos["ancho"] = this->width();
    if (gAlto == 1){
            jsonDatos["alto"] = this->height();
    }else{
            jsonDatos["alto"] = altoInicio;
    }

    if (gAncho == 1){
            jsonDatos["ancho"] = this->width();
    }else{
            jsonDatos["ancho"] = anchoInicio;
    }
    jsonPrincipal["configuracion"] = jsonDatos;


    // Proceso de creación del fichero
    QFile saveFile(QStringLiteral("saveConf.json"));
    saveFile.open(QIODevice::WriteOnly);
    QJsonDocument saveDoc(jsonPrincipal);
    saveFile.write(saveDoc.toJson());
    saveFile.close();

}

void MainWindow::slotCargarDatos(){
    QFile loadFile(QStringLiteral("saveConf.json"));

    if (!loadFile.open(QIODevice::ReadOnly))
        return;
    
    QByteArray savedData = loadFile.readAll();

    QJsonDocument readDoc(QJsonDocument::fromJson(savedData));
    QJsonObject jsonPrincipal = readDoc.object();

    if (! jsonPrincipal.contains("configuracion")){
        qDebug() << "Problemas al cargar configuración";
        return;
    }

    QJsonObject objetoConf = jsonPrincipal["configuracion"].toObject();
    int alto = objetoConf["alto"].toDouble();
    int ancho = objetoConf["ancho"].toDouble();

    resize(ancho, alto);

    loadFile.close();
}