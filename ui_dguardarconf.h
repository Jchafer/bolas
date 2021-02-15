/********************************************************************************
** Form generated from reading UI file 'dguardarconf.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DGUARDARCONF_H
#define UI_DGUARDARCONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_dGuardarConf
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkAlto;
    QCheckBox *checkAncho;

    void setupUi(QDialog *dGuardarConf)
    {
        if (dGuardarConf->objectName().isEmpty())
            dGuardarConf->setObjectName(QString::fromUtf8("dGuardarConf"));
        dGuardarConf->resize(291, 266);
        buttonBox = new QDialogButtonBox(dGuardarConf);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-110, 190, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkAlto = new QCheckBox(dGuardarConf);
        checkAlto->setObjectName(QString::fromUtf8("checkAlto"));
        checkAlto->setGeometry(QRect(80, 50, 111, 21));
        checkAncho = new QCheckBox(dGuardarConf);
        checkAncho->setObjectName(QString::fromUtf8("checkAncho"));
        checkAncho->setGeometry(QRect(80, 110, 131, 21));

        retranslateUi(dGuardarConf);
        QObject::connect(buttonBox, SIGNAL(accepted()), dGuardarConf, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dGuardarConf, SLOT(reject()));

        QMetaObject::connectSlotsByName(dGuardarConf);
    } // setupUi

    void retranslateUi(QDialog *dGuardarConf)
    {
        dGuardarConf->setWindowTitle(QApplication::translate("dGuardarConf", "Dialog", nullptr));
        checkAlto->setText(QApplication::translate("dGuardarConf", "Guardar Alto", nullptr));
        checkAncho->setText(QApplication::translate("dGuardarConf", "Guardar Ancho", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dGuardarConf: public Ui_dGuardarConf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DGUARDARCONF_H
