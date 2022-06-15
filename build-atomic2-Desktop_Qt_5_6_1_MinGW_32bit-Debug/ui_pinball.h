/********************************************************************************
** Form generated from reading UI file 'pinball.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINBALL_H
#define UI_PINBALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Pinball
{
public:

    void setupUi(QFrame *Pinball)
    {
        if (Pinball->objectName().isEmpty())
            Pinball->setObjectName(QStringLiteral("Pinball"));
        Pinball->resize(20, 20);
        Pinball->setMaximumSize(QSize(50, 50));

        retranslateUi(Pinball);

        QMetaObject::connectSlotsByName(Pinball);
    } // setupUi

    void retranslateUi(QFrame *Pinball)
    {
        Pinball->setWindowTitle(QApplication::translate("Pinball", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class Pinball: public Ui_Pinball {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINBALL_H
