/********************************************************************************
** Form generated from reading UI file 'board2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD2_H
#define UI_BOARD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Board2
{
public:
    QLabel *receive;

    void setupUi(QFrame *Board2)
    {
        if (Board2->objectName().isEmpty())
            Board2->setObjectName(QStringLiteral("Board2"));
        Board2->resize(80, 60);
        Board2->setMinimumSize(QSize(0, 60));
        Board2->setMaximumSize(QSize(16777215, 60));
        receive = new QLabel(Board2);
        receive->setObjectName(QStringLiteral("receive"));
        receive->setGeometry(QRect(0, 40, 80, 20));
        receive->setMinimumSize(QSize(0, 20));
        receive->setMaximumSize(QSize(16777215, 20));
        receive->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        retranslateUi(Board2);

        QMetaObject::connectSlotsByName(Board2);
    } // setupUi

    void retranslateUi(QFrame *Board2)
    {
        Board2->setWindowTitle(QApplication::translate("Board2", "Frame", 0));
        receive->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Board2: public Ui_Board2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD2_H
