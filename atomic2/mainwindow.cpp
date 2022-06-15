#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board2.h"
#include "ui_board2.h"
#include "pinball.h"
#include "ui_pinball.h"
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    b1 = new Board2(this);
    b1->move(400,638);
    b1->show();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)
    {
        b1->move(b1->pos().x()-10,b1->pos().y());
        if(b1->pos().x()<10)
        {
            b1->move(10,b1->pos().y());
        }
    }
    if(event->key()==Qt::Key_D)
    {
        b1->move(b1->pos().x()+10,b1->pos().y());
        if(b1->pos().x()>880)
        {
            b1->move(880,b1->pos().y());
        }
    }
    if(event->key()==Qt::Key_Q)
    {
        b1->ang+=4.0;
        if(b1->ang>170.0)
        {
            b1->ang=170.0;
        }
        update();
    }
    if(event->key()==Qt::Key_E)
    {
        b1->ang-=4.0;
        if(b1->ang<10.0)
        {
            b1->ang=10.0;
        }
        update();
    }
    if(event->key()==Qt::Key_Space&&b1->ava)
    {
        p1 = new Pinball(1,this);
        p1->mava = true;
        p1->show();
        b1->getCenter();
        p1->ax = b1->pos().x()+b1->cter.x()+32*cos(b1->ang/180*3.1415926);
        p1->ay = b1->pos().y()+b1->cter.y()+37-32*sin(b1->ang/180*3.1415926);
        p1->get_speed(5,b1->ang);
        p1->timer.start(50);
        b1->ava = false;
        update();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
