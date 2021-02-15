/********************************************************************************
** Form generated from reading UI file 'DTabDatosBolas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABDATOSBOLAS_H
#define UI_DTABDATOSBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTabDatosBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidgetDatosBolas;
    QWidget *tab;
    QWidget *tab_2;
    QCheckBox *checkBoxTodas;
    QComboBox *comboBox;
    QPushButton *pushButtonAumVel;
    QPushButton *pushButtonRedVel;
    QPushButton *pushButton;

    void setupUi(QDialog *DTabDatosBolas)
    {
        if (DTabDatosBolas->objectName().isEmpty())
            DTabDatosBolas->setObjectName(QString::fromUtf8("DTabDatosBolas"));
        DTabDatosBolas->resize(783, 717);
        buttonBox = new QDialogButtonBox(DTabDatosBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(430, 660, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidgetDatosBolas = new QTabWidget(DTabDatosBolas);
        tabWidgetDatosBolas->setObjectName(QString::fromUtf8("tabWidgetDatosBolas"));
        tabWidgetDatosBolas->setGeometry(QRect(20, 20, 711, 401));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidgetDatosBolas->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidgetDatosBolas->addTab(tab_2, QString());
        checkBoxTodas = new QCheckBox(DTabDatosBolas);
        checkBoxTodas->setObjectName(QString::fromUtf8("checkBoxTodas"));
        checkBoxTodas->setGeometry(QRect(30, 490, 151, 41));
        comboBox = new QComboBox(DTabDatosBolas);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(240, 500, 141, 25));
        pushButtonAumVel = new QPushButton(DTabDatosBolas);
        pushButtonAumVel->setObjectName(QString::fromUtf8("pushButtonAumVel"));
        pushButtonAumVel->setGeometry(QRect(20, 540, 167, 25));
        pushButtonRedVel = new QPushButton(DTabDatosBolas);
        pushButtonRedVel->setObjectName(QString::fromUtf8("pushButtonRedVel"));
        pushButtonRedVel->setGeometry(QRect(20, 580, 166, 25));
        pushButton = new QPushButton(DTabDatosBolas);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 560, 89, 25));

        retranslateUi(DTabDatosBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTabDatosBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTabDatosBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTabDatosBolas);
    } // setupUi

    void retranslateUi(QDialog *DTabDatosBolas)
    {
        DTabDatosBolas->setWindowTitle(QApplication::translate("DTabDatosBolas", "Dialog", nullptr));
        tabWidgetDatosBolas->setTabText(tabWidgetDatosBolas->indexOf(tab), QApplication::translate("DTabDatosBolas", "Tab 1", nullptr));
        tabWidgetDatosBolas->setTabText(tabWidgetDatosBolas->indexOf(tab_2), QApplication::translate("DTabDatosBolas", "Tab 2", nullptr));
        checkBoxTodas->setText(QApplication::translate("DTabDatosBolas", "Seleccionar Todas", nullptr));
        pushButtonAumVel->setText(QApplication::translate("DTabDatosBolas", "Aumentar Velocidad", nullptr));
        pushButtonRedVel->setText(QApplication::translate("DTabDatosBolas", "Reducir Velocidad", nullptr));
        pushButton->setText(QApplication::translate("DTabDatosBolas", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTabDatosBolas: public Ui_DTabDatosBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABDATOSBOLAS_H
