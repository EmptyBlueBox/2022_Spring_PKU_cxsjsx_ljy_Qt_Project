#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "board2.h"
#include "pinball.h"
#include "bomb.h"
#include <QPainter>
#include <QPixmap>
#include <QKeyEvent>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void playgame1();
    void keyPressEvent(QKeyEvent *);
    int rand_atom();
    void pop_prepare();
    void colli_detect1();
    void colli_detect2();
    void colli_detect3();
    void colli_detect4();
    void get_new_atom(int,int);
    int produce_new_atom(int,int);
    void rece_detect1();
    void rece_detect2();
    void end_detect();
    void end_pop();
    void gameover();
    void win();
    void update_atomnum();
    void update_atomtable();

private slots:
    void onTimeout1(void);

public:
    QTimer timer1;

private:
    Ui::MainWindow *ui;
    Board2 *b1 = nullptr;
    Pinball *p1 = nullptr;//发射出的原子
    Pinball *p2[10];//界面上的原子
    Pinball *p3[20];//通过碰撞产生的原子
    Pinball *pb[10];//原子爆弹
    Bomb *bb[20];
    int bombva;//爆弹值
    int bombti;//次数
    int maxatom;//目前所获得的最大原子
    int atomnum[13];
    int np3;

};

#endif // MAINWINDOW_H
