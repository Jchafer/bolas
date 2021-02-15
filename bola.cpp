#include "bola.h"
#include <QtMath>
#include <QBrush>

int Bola::vidaInicial;

Bola::Bola(float posX, float posY, float velX, float velY, QString nombre)
{
    this->posX = posX;
    this->posY = posY;
    this->velX = velX;
    this->velY = velY;
    this->nombre = nombre;
    this->color = QColor(random()%256, random()%256, random()%256);

    colisiones = 0;
    coliPared = 0;
    vida = vidaInicial;
    padre = NULL;
    imagen = QImage("./png/abrupt-boy-face.png");
    imagen = imagen.scaled(Bola::diametro, Bola::diametro);
    mostrarImagen = true;
}

Bola::Bola(){
    padre = NULL;
    imagen = QImage("./png/abrupt-boy-face.png");
    imagen = imagen.scaled(Bola::diametro, Bola::diametro);
    mostrarImagen = true;
}

void Bola::mover(int ancho, int alto){
    // Seccion de deteccion de colision contra los bordes
    if (posX >= ancho - diametro ){
        velX = -fabs(velX);
        coliPared++;
    }
    if (posX <= 0 ){
        velX = fabs(velX);
        coliPared++;
    }
    if (posY >= alto - diametro){
        velY = -fabs(velY);
        coliPared++;
    }
    if (posY <= 0 ){
        velY = fabs(velY);
        coliPared++;
    } 

    // Seccion de actualizacion de la posicion
    posX = posX + velX;
    posY = posY + velY;
}

void Bola::pintar(QPainter &pintor){

    QBrush brush(color);

    int ancho = diametro;
    float anchoVerde = (((float)vida) / vidaInicial) * (float)ancho;
    float anchoRojo = (ancho - (float)anchoVerde);
    pintor.setBrush(Qt::green);
    pintor.drawRect(posX, posY - 5, anchoVerde, 3);
    pintor.setBrush(Qt::red);
    pintor.drawRect(posX + anchoVerde, posY - 5, anchoRojo, 3);
    pintor.setBrush(color);
    pintor.drawEllipse(posX, posY, Bola::diametro, Bola::diametro);

    if (vida < 0)
        vida = 0;

    if (mostrarImagen) pintor.drawImage(posX,posY,imagen);
    else pintor.drawEllipse(posX,posY,Bola::diametro,Bola::diametro);
    
    pintor.drawText(posX - 10,
                    posY + 65,
                    QString(nombre) + QString(" (") + QString::number(vida) + QString(")"));
    pintor.drawText(posX - 10,
                    posY - 10,
                    QString("Col. Bola: ") + QString::number(colisiones));
    pintor.drawText(posX - 10,
                    posY -30,
                    QString("Col. Pared: ") + QString::number(coliPared));
    
    /*QBrush brush(color);
    pintor.setBrush(brush);
    pintor.drawEllipse(posX, posY, Bola::diametro, Bola::diametro);
    pintor.drawText(posX - 10, posY - 20, QString("VidasJugador ") + QString::number(vidaInicial));*/
}

bool Bola::choca(Bola *otra){

    int aumentoVelocidad = 0;

    Bola *izquierda, *derecha;
    Bola *arriba, *abajo;
    bool rebote = false;

    if (this == otra) return false;

    float distancia = sqrtf(powf((posX-otra->posX),2) + powf((posY-otra->posY),2));

    if (distancia > diametro) return false;    
    
    if (this->posX > otra->posX){
        izquierda = otra;
        derecha = this;
    }else{
        izquierda = this;
        derecha = otra;
    }
    
    if (izquierda->velX > derecha->velX){
        float temp = izquierda->velX;
        izquierda->velX = derecha->velX + aumentoVelocidad;
        derecha->velX = temp + aumentoVelocidad;
        rebote = true;
    }

    if (this->posY > otra->posY){
        arriba = otra;
        abajo = this;
    }else{
        arriba = this;
        abajo = otra;
    }
    
    if (arriba->velY > abajo->velY){
        float temp = abajo->velY;
        abajo->velY = arriba->velY + aumentoVelocidad;
        arriba->velY = temp + aumentoVelocidad;
        rebote = true;
    }

    if (rebote){
        colisiones++;
        otra->colisiones++;
    }

    
    return rebote;
}

void Bola::parar(){
    this->velX = 0;
    this->velY = 0;
}

void Bola::cambiarColor(QColor &colorRecibido){
    this->color = colorRecibido;
}

void Bola::acelerar(){
    this->velX = velX * 1.05;
    this->velY = velY * 1.05;
}

void Bola::frenar(){
    this->velX = velX / 2;
    this->velY = velY / 2;
}