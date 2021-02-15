/********************************************************************************
** Form generated from reading UI file 'widgetbolatabla.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETBOLATABLA_H
#define UI_WIDGETBOLATABLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widgetBolaTabla
{
public:
    QTableView *tablaHijas;
    QCheckBox *checkBoxHijas;
    QComboBox *listaHijas;
    QFrame *frameCoordenadas;

    void setupUi(QWidget *widgetBolaTabla)
    {
        if (widgetBolaTabla->objectName().isEmpty())
            widgetBolaTabla->setObjectName(QString::fromUtf8("widgetBolaTabla"));
        widgetBolaTabla->resize(651, 583);
        tablaHijas = new QTableView(widgetBolaTabla);
        tablaHijas->setObjectName(QString::fromUtf8("tablaHijas"));
        tablaHijas->setGeometry(QRect(15, 11, 611, 361));
        checkBoxHijas = new QCheckBox(widgetBolaTabla);
        checkBoxHijas->setObjectName(QString::fromUtf8("checkBoxHijas"));
        checkBoxHijas->setGeometry(QRect(60, 480, 92, 23));
        listaHijas = new QComboBox(widgetBolaTabla);
        listaHijas->setObjectName(QString::fromUtf8("listaHijas"));
        listaHijas->setGeometry(QRect(50, 420, 121, 25));
        frameCoordenadas = new QFrame(widgetBolaTabla);
        frameCoordenadas->setObjectName(QString::fromUtf8("frameCoordenadas"));
        frameCoordenadas->setGeometry(QRect(260, 380, 361, 181));
        frameCoordenadas->setFrameShape(QFrame::StyledPanel);
        frameCoordenadas->setFrameShadow(QFrame::Raised);

        retranslateUi(widgetBolaTabla);

        QMetaObject::connectSlotsByName(widgetBolaTabla);
    } // setupUi

    void retranslateUi(QWidget *widgetBolaTabla)
    {
        widgetBolaTabla->setWindowTitle(QApplication::translate("widgetBolaTabla", "Form", nullptr));
        checkBoxHijas->setText(QApplication::translate("widgetBolaTabla", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widgetBolaTabla: public Ui_widgetBolaTabla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETBOLATABLA_H
