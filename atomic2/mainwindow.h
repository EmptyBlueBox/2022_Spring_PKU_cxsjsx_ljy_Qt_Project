#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board2.h"
#include "pinball.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
    Board2 *b1 = nullptr;
    Pinball *p1 = nullptr;
};

#endif // MAINWINDOW_H