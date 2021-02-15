/********************************************************************************
** Form generated from reading UI file 'widgetBol.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOL_H
#define UI_WIDGETBOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetBol
{
public:

    void setupUi(QWidget *WidgetBol)
    {
        if (WidgetBol->objectName().isEmpty())
            WidgetBol->setObjectName(QString::fromUtf8("WidgetBol"));
        WidgetBol->resize(687, 364);

        retranslateUi(WidgetBol);

        QMetaObject::connectSlotsByName(WidgetBol);
    } // setupUi

    void retranslateUi(QWidget *WidgetBol)
    {
        WidgetBol->setWindowTitle(QApplication::translate("WidgetBol", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetBol: public Ui_WidgetBol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOL_H
