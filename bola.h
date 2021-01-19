#ifndef _BOLA_H
#define _BOLA_H
#include <QPainter>
#include <QColor>
#include <QVector>

class Bola{
public:
    float posX, posY;
    float velX, velY;
    static const int diametro = 50;
    QColor color;
    static int vidaInicial;
    int vida;

    Bola *padre;

    QVector<Bola*> hijas;

    Bola();
    Bola(float posX, float posY, float velX, float velY);

    

    void mover(int,int); // Anchura y altura del area de juego
    void pintar(QPainter &pintor);
    bool choca(Bola *otra);
    void parar();
};

#endif 