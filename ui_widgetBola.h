/********************************************************************************
** Form generated from reading UI file 'widgetBola.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLA_H
#define UI_WIDGETBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButtonElegirColor;
    QPushButton *pushButtonAumVel;
    QPushButton *pushButtonPararLaBola;
    QPushButton *pushButtonRedVel;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(348, 173);
        gridLayout = new QGridLayout(WidgetBola);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonElegirColor = new QPushButton(WidgetBola);
        pushButtonElegirColor->setObjectName(QString::fromUtf8("pushButtonElegirColor"));

        gridLayout->addWidget(pushButtonElegirColor, 0, 0, 1, 1);

        pushButtonAumVel = new QPushButton(WidgetBola);
        pushButtonAumVel->setObjectName(QString::fromUtf8("pushButtonAumVel"));

        gridLayout->addWidget(pushButtonAumVel, 0, 1, 1, 1);

        pushButtonPararLaBola = new QPushButton(WidgetBola);
        pushButtonPararLaBola->setObjectName(QString::fromUtf8("pushButtonPararLaBola"));

        gridLayout->addWidget(pushButtonPararLaBola, 1, 0, 1, 1);

        pushButtonRedVel = new QPushButton(WidgetBola);
        pushButtonRedVel->setObjectName(QString::fromUtf8("pushButtonRedVel"));

        gridLayout->addWidget(pushButtonRedVel, 1, 1, 1, 1);


        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", nullptr));
        pushButtonElegirColor->setText(QApplication::translate("WidgetBola", "Elegir Color", nullptr));
        pushButtonAumVel->setText(QApplication::translate("WidgetBola", "Aumentar Velocidad", nullptr));
        pushButtonPararLaBola->setText(QApplication::translate("WidgetBola", "Parar la bola", nullptr));
        pushButtonRedVel->setText(QApplication::translate("WidgetBola", "Reducir Velocidad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
