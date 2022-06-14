#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board2.h"
#include "ui_board2.h"

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
        b1->ang+=2.0;
        if(b1->ang>170.0)
        {
            b1->ang=170.0;
        }
        update();
    }
    if(event->key()==Qt::Key_E)
    {
        b1->ang-=2.0;
        if(b1->ang<10.0)
        {
            b1->ang=10.0;
        }
        update();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
