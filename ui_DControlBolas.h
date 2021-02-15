/********************************************************************************
** Form generated from reading UI file 'DControlBolas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DCONTROLBOLAS_H
#define UI_DCONTROLBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DControlBolas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabBolas;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonPararBola;
    QCheckBox *checkBoxPararTodas;
    QPushButton *pushButtonAumVel;
    QPushButton *pushButtonRedVel;

    void setupUi(QDialog *DControlBolas)
    {
        if (DControlBolas->objectName().isEmpty())
            DControlBolas->setObjectName(QString::fromUtf8("DControlBolas"));
        DControlBolas->resize(400, 399);
        buttonBox = new QDialogButtonBox(DControlBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 350, 175, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabBolas = new QTabWidget(DControlBolas);
        tabBolas->setObjectName(QString::fromUtf8("tabBolas"));
        tabBolas->setGeometry(QRect(20, 20, 341, 221));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabBolas->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabBolas->addTab(tab_2, QString());
        layoutWidget = new QWidget(DControlBolas);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 259, 341, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonPararBola = new QPushButton(layoutWidget);
        pushButtonPararBola->setObjectName(QString::fromUtf8("pushButtonPararBola"));

        gridLayout->addWidget(pushButtonPararBola, 0, 0, 1, 1);

        checkBoxPararTodas = new QCheckBox(layoutWidget);
        checkBoxPararTodas->setObjectName(QString::fromUtf8("checkBoxPararTodas"));

        gridLayout->addWidget(checkBoxPararTodas, 0, 1, 1, 1);

        pushButtonAumVel = new QPushButton(layoutWidget);
        pushButtonAumVel->setObjectName(QString::fromUtf8("pushButtonAumVel"));

        gridLayout->addWidget(pushButtonAumVel, 1, 0, 1, 1);

        pushButtonRedVel = new QPushButton(layoutWidget);
        pushButtonRedVel->setObjectName(QString::fromUtf8("pushButtonRedVel"));

        gridLayout->addWidget(pushButtonRedVel, 1, 1, 1, 1);


        retranslateUi(DControlBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DControlBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DControlBolas, SLOT(reject()));

        tabBolas->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DControlBolas);
    } // setupUi

    void retranslateUi(QDialog *DControlBolas)
    {
        DControlBolas->setWindowTitle(QApplication::translate("DControlBolas", "Dialog", nullptr));
        tabBolas->setTabText(tabBolas->indexOf(tab), QApplication::translate("DControlBolas", "Tab 1", nullptr));
        tabBolas->setTabText(tabBolas->indexOf(tab_2), QApplication::translate("DControlBolas", "Tab 2", nullptr));
        pushButtonPararBola->setText(QApplication::translate("DControlBolas", "Parar Bola", nullptr));
        checkBoxPararTodas->setText(QApplication::translate("DControlBolas", "Parar todas", nullptr));
        pushButtonAumVel->setText(QApplication::translate("DControlBolas", "Aumentar Velocidad", nullptr));
        pushButtonRedVel->setText(QApplication::translate("DControlBolas", "Reducir Velocidad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DControlBolas: public Ui_DControlBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DCONTROLBOLAS_H
