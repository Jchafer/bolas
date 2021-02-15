#ifndef _WIDGETBOLATABLA_
#define _WIDGETBOLATABLA_

#include <QDialog>
#include <QLabel>
#include <QVector>
#include <bola.h>
#include <ui_widgetbolatabla.h>
#include <QString>
#include <QTimer>

class WidgetBolaTabla : public QWidget, public Ui::widgetBolaTabla{
    Q_OBJECT
    public:
        WidgetBolaTabla(Bola *bola, QWidget * parent = nullptr);
        Bola * miBola;

        QTimer * temporizador;

    public slots:

};

class ModeloBolasHijas : public QAbstractTableModel{
    Q_OBJECT
    public:
        ModeloBolasHijas(QVector<Bola*> *lasBolas, QObject * parent = nullptr);

        QVector<Bola*> *vector;
        QString getInformacionBolas(Bola *bola);

        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole)const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const;

        public slots:
            void slotActualizarDatos();
            void slotActualizarDatosTemp();
            
};

#endif