#ifndef _BOLA_H
#define _BOLA_H
#include <QPainter>
#include <QColor>
#include <QVector>
#include <QImage>
#include <QColor>

class Bola{
public:
    Bola();
    Bola(float posX, float posY, float velX, float velY, QString nombre);

    float posX, posY, velX, velY;
    static const int diametro = 50;
    QColor color;
    static int vidaInicial;
    int vida, colisiones, coliPared;
    QString nombre;

    QImage imagen;
    bool mostrarImagen;

    Bola *padre;

    QVector<Bola*> hijas;

    void mover(int,int); // Anchura y altura del area de juego
    void pintar(QPainter &pintor);
    bool choca(Bola *otra);
    void parar();
    void cambiarColor(QColor &color);
    void ponImagen(QImage&);
    void acelerar();
    void frenar();
};

#endif 