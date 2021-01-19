/********************************************************************************
** Form generated from reading UI file 'DInfoTabla.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFOTABLA_H
#define UI_DINFOTABLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DInfoTabla
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *vistaTabla;
    QPushButton *botonActualizar;
    QComboBox *comboBox;

    void setupUi(QDialog *DInfoTabla)
    {
        if (DInfoTabla->objectName().isEmpty())
            DInfoTabla->setObjectName(QString::fromUtf8("DInfoTabla"));
        DInfoTabla->resize(794, 655);
        buttonBox = new QDialogButtonBox(DInfoTabla);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(390, 590, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        vistaTabla = new QTableView(DInfoTabla);
        vistaTabla->setObjectName(QString::fromUtf8("vistaTabla"));
        vistaTabla->setGeometry(QRect(70, 20, 661, 531));
        botonActualizar = new QPushButton(DInfoTabla);
        botonActualizar->setObjectName(QString::fromUtf8("botonActualizar"));
        botonActualizar->setGeometry(QRect(170, 590, 83, 25));
        comboBox = new QComboBox(DInfoTabla);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(350, 590, 86, 25));

        retranslateUi(DInfoTabla);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInfoTabla, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInfoTabla, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInfoTabla);
    } // setupUi

    void retranslateUi(QDialog *DInfoTabla)
    {
        DInfoTabla->setWindowTitle(QApplication::translate("DInfoTabla", "Dialog", nullptr));
        botonActualizar->setText(QApplication::translate("DInfoTabla", "Actualizar", nullptr));
        comboBox->setItemText(0, QApplication::translate("DInfoTabla", "Alta", nullptr));
        comboBox->setItemText(1, QApplication::translate("DInfoTabla", "Media", nullptr));
        comboBox->setItemText(2, QApplication::translate("DInfoTabla", "Baja", nullptr));

    } // retranslateUi

};

namespace Ui {
    class DInfoTabla: public Ui_DInfoTabla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFOTABLA_H
