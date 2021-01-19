/********************************************************************************
** Form generated from reading UI file 'DArbolBolas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DARBOLBOLAS_H
#define UI_DARBOLBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DArbolBolas
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTreeView *vistaArbol;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DArbolBolas)
    {
        if (DArbolBolas->objectName().isEmpty())
            DArbolBolas->setObjectName(QString::fromUtf8("DArbolBolas"));
        DArbolBolas->resize(770, 545);
        widget = new QWidget(DArbolBolas);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(150, 30, 501, 471));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        vistaArbol = new QTreeView(widget);
        vistaArbol->setObjectName(QString::fromUtf8("vistaArbol"));

        verticalLayout->addWidget(vistaArbol);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DArbolBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DArbolBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DArbolBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DArbolBolas);
    } // setupUi

    void retranslateUi(QDialog *DArbolBolas)
    {
        DArbolBolas->setWindowTitle(QApplication::translate("DArbolBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DArbolBolas: public Ui_DArbolBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DARBOLBOLAS_H
