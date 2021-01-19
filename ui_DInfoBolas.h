/********************************************************************************
** Form generated from reading UI file 'DInfoBolas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINFOBOLAS_H
#define UI_DINFOBOLAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_DInfoBolas
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidgetBolas;

    void setupUi(QDialog *DInfoBolas)
    {
        if (DInfoBolas->objectName().isEmpty())
            DInfoBolas->setObjectName(QString::fromUtf8("DInfoBolas"));
        DInfoBolas->resize(794, 433);
        buttonBox = new QDialogButtonBox(DInfoBolas);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(380, 380, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidgetBolas = new QListWidget(DInfoBolas);
        listWidgetBolas->setObjectName(QString::fromUtf8("listWidgetBolas"));
        listWidgetBolas->setGeometry(QRect(40, 10, 691, 341));

        retranslateUi(DInfoBolas);
        QObject::connect(buttonBox, SIGNAL(accepted()), DInfoBolas, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DInfoBolas, SLOT(reject()));

        QMetaObject::connectSlotsByName(DInfoBolas);
    } // setupUi

    void retranslateUi(QDialog *DInfoBolas)
    {
        DInfoBolas->setWindowTitle(QApplication::translate("DInfoBolas", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DInfoBolas: public Ui_DInfoBolas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINFOBOLAS_H
