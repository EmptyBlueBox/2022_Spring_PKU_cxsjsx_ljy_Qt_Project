/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QWidget *centralWidget;
    QFrame *frame;
    QLCDNumber *score;
    QLCDNumber *timerest;
    QLabel *label;
    QLabel *label_2;
    QFrame *atom_show;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QStringLiteral("action_10"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 10, 950, 670));
        frame->setMinimumSize(QSize(950, 670));
        frame->setMaximumSize(QSize(950, 670));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        score = new QLCDNumber(centralWidget);
        score->setObjectName(QStringLiteral("score"));
        score->setGeometry(QRect(980, 10, 190, 70));
        score->setMinimumSize(QSize(190, 70));
        score->setMaximumSize(QSize(190, 70));
        timerest = new QLCDNumber(centralWidget);
        timerest->setObjectName(QStringLiteral("timerest"));
        timerest->setGeometry(QRect(980, 110, 190, 70));
        timerest->setMinimumSize(QSize(190, 70));
        timerest->setMaximumSize(QSize(190, 70));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1100, 80, 70, 30));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(1059, 180, 111, 30));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        atom_show = new QFrame(centralWidget);
        atom_show->setObjectName(QStringLiteral("atom_show"));
        atom_show->setGeometry(QRect(990, 210, 181, 71));
        atom_show->setFrameShape(QFrame::VLine);
        atom_show->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(1029, 280, 141, 30));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_5 = new QMenu(menu);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_6 = new QMenu(menu);
        menu_6->setObjectName(QStringLiteral("menu_6"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(menu_5->menuAction());
        menu->addAction(menu_6->menuAction());
        menu_5->addAction(action_4);
        menu_5->addAction(action_5);
        menu_5->addAction(action_6);
        menu_6->addAction(action_8);
        menu_6->addAction(action_9);
        menu_6->addAction(action_10);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\216\237\345\255\220\347\210\206\345\274\271", 0));
        action_4->setText(QApplication::translate("MainWindow", "\347\273\217\345\205\270\346\250\241\345\274\217", 0));
        action_5->setText(QApplication::translate("MainWindow", "\351\231\220\346\227\266\346\250\241\345\274\217", 0));
        action_6->setText(QApplication::translate("MainWindow", "\345\217\214\344\272\272\346\250\241\345\274\217", 0));
        action_8->setText(QApplication::translate("MainWindow", "\347\273\217\345\205\270\346\250\241\345\274\217", 0));
        action_9->setText(QApplication::translate("MainWindow", "\351\231\220\346\227\266\346\250\241\345\274\217", 0));
        action_10->setText(QApplication::translate("MainWindow", "\345\217\214\344\272\272\346\250\241\345\274\217", 0));
        label->setText(QApplication::translate("MainWindow", "\347\210\206\345\274\271\345\200\274", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\217\221\345\260\204\346\254\241\346\225\260", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\346\234\200\345\244\247\345\216\237\345\255\220", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\270\270\346\210\217", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", 0));
        menu_6->setTitle(QApplication::translate("MainWindow", "\345\212\240\350\275\275\345\255\230\346\241\243", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\210\220\345\260\261", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
