#ifndef _DGUARDARCONF_
#define _DGUARDARCONF_

#include <QDialog>
#include <QLabel>
#include <QVector>
#include <bola.h>
#include <ui_dguardarconf.h>
#include <QString>
#include <QTimer>

class DGuardarConf : public QDialog, public Ui::dGuardarConf{
    Q_OBJECT
    public:
    DGuardarConf(QWidget * parent = nullptr);

    int alto, ancho;

    public slots:
       void slotEnviarGuardar();

    signals:
        void guardarEsto(int, int);

};

#endif