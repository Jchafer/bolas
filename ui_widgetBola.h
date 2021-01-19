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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBola
{
public:
    QPushButton *pushButtonElegirColor;
    QPushButton *pushButtonPararLaBola;

    void setupUi(QWidget *WidgetBola)
    {
        if (WidgetBola->objectName().isEmpty())
            WidgetBola->setObjectName(QString::fromUtf8("WidgetBola"));
        WidgetBola->resize(233, 182);
        pushButtonElegirColor = new QPushButton(WidgetBola);
        pushButtonElegirColor->setObjectName(QString::fromUtf8("pushButtonElegirColor"));
        pushButtonElegirColor->setGeometry(QRect(60, 40, 89, 25));
        pushButtonPararLaBola = new QPushButton(WidgetBola);
        pushButtonPararLaBola->setObjectName(QString::fromUtf8("pushButtonPararLaBola"));
        pushButtonPararLaBola->setGeometry(QRect(60, 100, 89, 25));

        retranslateUi(WidgetBola);

        QMetaObject::connectSlotsByName(WidgetBola);
    } // setupUi

    void retranslateUi(QWidget *WidgetBola)
    {
        WidgetBola->setWindowTitle(QApplication::translate("WidgetBola", "Form", nullptr));
        pushButtonElegirColor->setText(QApplication::translate("WidgetBola", "Elegir Color", nullptr));
        pushButtonPararLaBola->setText(QApplication::translate("WidgetBola", "Parar la bola", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBola: public Ui_WidgetBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLA_H
