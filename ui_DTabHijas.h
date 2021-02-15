/********************************************************************************
** Form generated from reading UI file 'DTabHijas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABHIJAS_H
#define UI_DTABHIJAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTabHijas
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidgetHijas;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *DTabHijas)
    {
        if (DTabHijas->objectName().isEmpty())
            DTabHijas->setObjectName(QString::fromUtf8("DTabHijas"));
        DTabHijas->resize(783, 717);
        buttonBox = new QDialogButtonBox(DTabHijas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(430, 660, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidgetHijas = new QTabWidget(DTabHijas);
        tabWidgetHijas->setObjectName(QString::fromUtf8("tabWidgetHijas"));
        tabWidgetHijas->setGeometry(QRect(20, 20, 751, 611));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidgetHijas->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidgetHijas->addTab(tab_2, QString());

        retranslateUi(DTabHijas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTabHijas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTabHijas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTabHijas);
    } // setupUi

    void retranslateUi(QDialog *DTabHijas)
    {
        DTabHijas->setWindowTitle(QApplication::translate("DTabHijas", "Dialog", nullptr));
        tabWidgetHijas->setTabText(tabWidgetHijas->indexOf(tab), QApplication::translate("DTabHijas", "Tab 1", nullptr));
        tabWidgetHijas->setTabText(tabWidgetHijas->indexOf(tab_2), QApplication::translate("DTabHijas", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTabHijas: public Ui_DTabHijas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABHIJAS_H
