/********************************************************************************
** Form generated from reading UI file 'DTablaInfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLAINFO_H
#define UI_DTABLAINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DTablaInfo
{
public:
    QDialogButtonBox *buttonBox;
    QTableView *tableInfo;

    void setupUi(QDialog *DTablaInfo)
    {
        if (DTablaInfo->objectName().isEmpty())
            DTablaInfo->setObjectName(QString::fromUtf8("DTablaInfo"));
        DTablaInfo->resize(797, 564);
        buttonBox = new QDialogButtonBox(DTablaInfo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(430, 500, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tableInfo = new QTableView(DTablaInfo);
        tableInfo->setObjectName(QString::fromUtf8("tableInfo"));
        tableInfo->setGeometry(QRect(65, 21, 701, 451));

        retranslateUi(DTablaInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaInfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaInfo, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaInfo);
    } // setupUi

    void retranslateUi(QDialog *DTablaInfo)
    {
        DTablaInfo->setWindowTitle(QApplication::translate("DTablaInfo", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaInfo: public Ui_DTablaInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLAINFO_H
