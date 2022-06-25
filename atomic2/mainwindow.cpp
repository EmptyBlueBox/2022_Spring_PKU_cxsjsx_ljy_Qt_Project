#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board2.h"
#include "ui_board2.h"
#include "pinball.h"
#include "ui_pinball.h"
#include "bomb.h"
#include "ui_bomb.h"
#include "shop.h"
#include "ui_shop.h"
#include <qdebug.h>

int atomheight[3]={70, 120, 170};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bombva = 0;
    bombti = 0;
    maxatom = 1;
    qsrand(QTime::currentTime().msec());
    ui->score->display(bombva);
    ui->thistime->display(bombti);
    ui->atomtable->setSelectionMode(QAbstractItemView::NoSelection);//表格禁止选中
    ui->atomtable->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格禁止编辑
    ui->atomtable->setColumnWidth(0,60);
    ui->atomtable->setColumnWidth(2,60);
    ui->atomtable->setColumnWidth(4,60);
    ui->atomtable->setColumnWidth(1,30);
    ui->atomtable->setColumnWidth(3,30);
    ui->atomtable->setColumnWidth(5,30);
    ui->atomtable->setRowHeight(0,60);
    ui->atomtable->setRowHeight(1,60);
    ui->atomtable->setRowHeight(2,60);
    ui->atomtable->setRowHeight(3,60);//调整行列宽高
    ui->atomtable->setSelectionMode(QAbstractItemView::NoSelection);//表格禁止选中
    ui->itemtable->setEditTriggers(QAbstractItemView::NoEditTriggers);//表格禁止编辑
    ui->itemtable->setColumnWidth(0,64);
    ui->itemtable->setColumnWidth(1,64);
    ui->itemtable->setColumnWidth(2,64);
    ui->itemtable->setRowHeight(0,64);
    ui->itemtable->setRowHeight(1,64);
    ui->itemtable->setRowHeight(2,64);//调整行列宽高
    b1 = new Board2(this);
    setFocusPolicy(Qt::StrongFocus);
    ui->atomtable->setFocusPolicy(Qt::NoFocus);
    ui->itemtable->setFocusPolicy(Qt::NoFocus);//这三行让炮台随时可以用键盘操作
    ui->storeButton->setFocusPolicy(Qt::ClickFocus);
    sh = new Shop(this);
    sh->hide();
    for(int i=1;i<=3;++i)
    {
        p2[i] = new Pinball(1,this,10,960);
    }
    for(int i=1;i<=3;++i)
    {
        p2[3+i] = new Pinball(1,this,10,480);
    }
    for(int i=1;i<=3;++i)
    {
        p2[6+i] = new Pinball(1,this,490,960);
    }//以上是对界面上的原子的初始化，它们位于不同的轨道上
    np3 = 0;
    for(int i=1;i<=19;++i)
    {
        p3[i] = new Pinball(1,this,10,960);
    }//对将来碰撞产生的原子的初始化
    connect(&timer1,SIGNAL(timeout()),this,SLOT(onTimeout1()));
    connect(sh->ui->end_button,SIGNAL(clicked()),this,SLOT(shopupdate()));
    for(int i=0;i<20;++i)
    {
        bb[i] = new Bomb(this);
    }//对爆炸效果的初始化
    for(int i=0;i<=9;++i)
    {
        pb[i] = new Pinball(1,this,10,960);
    }//对原子爆弹初始化
    for(int i=1;i<=9;++i)
    {
        mi[i] = 0;
        il[i] = 1;
    }
    for(int i=0;i<13;++i)
    {
        atomnum[i]=0;
    }
    atomnum[1]=2;
    playgame1();//开始经典模式游戏
}

void MainWindow::playgame1()
{
    pop_prepare();
}

void MainWindow::onTimeout1()
{
    colli_detect1();
    colli_detect2();
    colli_detect3();
    colli_detect4();
    rece_detect1();
    rece_detect2();
    for(int i=0;i<20;++i)
    {
        if(bb[i]->bava)
        {
            bb[i]->newinfo();
        }
    }
    if(b1->rece)
    {
        b1->newinfo();
    }
    end_detect();
    update();
}

void MainWindow::update_atomnum()//更新原子数目，三消
{
    for(int i=1;i<=11;++i)
    {
        int a = atomnum[i] % 3;
        int b = atomnum[i] / 3;
        atomnum[i] = a;
        atomnum[i+1] += b;
    }
}

void MainWindow::update_atomtable()//将更新的原子数目显示到表格中去
{
    ui->atomtable->setItem(0,1,new QTableWidgetItem(QString::number(atomnum[1])));
    ui->atomtable->setItem(1,1,new QTableWidgetItem(QString::number(atomnum[2])));
    ui->atomtable->setItem(2,1,new QTableWidgetItem(QString::number(atomnum[3])));
    ui->atomtable->setItem(3,1,new QTableWidgetItem(QString::number(atomnum[4])));
    ui->atomtable->setItem(0,3,new QTableWidgetItem(QString::number(atomnum[5])));
    ui->atomtable->setItem(1,3,new QTableWidgetItem(QString::number(atomnum[6])));
    ui->atomtable->setItem(2,3,new QTableWidgetItem(QString::number(atomnum[7])));
    ui->atomtable->setItem(3,3,new QTableWidgetItem(QString::number(atomnum[8])));
    ui->atomtable->setItem(0,5,new QTableWidgetItem(QString::number(atomnum[9])));
    ui->atomtable->setItem(1,5,new QTableWidgetItem(QString::number(atomnum[10])));
    ui->atomtable->setItem(2,5,new QTableWidgetItem(QString::number(atomnum[11])));
    ui->atomtable->setItem(3,5,new QTableWidgetItem(QString::number(atomnum[12])));
    bool g = true;
    for(int i = 12;i >= 1;--i)
    {
        if(atomnum[i])
        {
            maxatom = i;
            g = false;
            break;
        }
    }
    if(g)
    {
        maxatom = 0;
    }
}

int MainWindow::rand_atom()
{
    int ra = qrand() % 2022;
    if(ra > 2000)
    {
        return maxatom;
    }
    if(ra % 19 == 0)
    {
        return qMin(maxatom,6);
    }
    if(ra % 17 == 0)
    {
        return qMin(maxatom,5);
    }
    if(ra % 11 == 0)
    {
        return qMin(maxatom,4);
    }
    if(ra % 5 == 0)
    {
        return qMin(maxatom,3);
    }
    if(ra % 2 == 0)
    {
        return 2;
    }
    return 1;
}//随机决定轨道上原子的种类

void MainWindow::pop_prepare()//发射前准备
{
    p1 = new Pinball(maxatom,this,10,960);//原子的初始化
    p1->move(-100,-100);//发射时会闪现原子在初始化的可见的位置，移出去就不可见
    b1->move(440,638);//炮台初始位置
    b1->ava = true;//炮台预备发射
    b1->show();
    bombti++;
    ui->score->display(bombva);
    ui->thistime->display(bombti);//LCD显示
    ui->storeButton->setEnabled(true);
    int ra = qrand() % 2022;
    switch (bombti%6) {//设计了6种原子轨道模式，不断循环，也有些像黄金矿工的机制
    case 0:
        p2[4]->mava = true;
        p2[5]->mava = true;
        p2[6]->mava = true;
        p2[7]->mava = true;
        p2[8]->mava = true;
        p2[9]->mava = true;
        p2[4]->remake(rand_atom());
        p2[5]->remake(rand_atom());
        p2[6]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[8]->remake(rand_atom());
        p2[9]->remake(rand_atom());
        p2[4]->show();
        p2[5]->show();
        p2[6]->show();
        p2[7]->show();
        p2[8]->show();
        p2[9]->show();
        p2[4]->ax = qrand() % 410 + 40;
        p2[5]->ax = qrand() % 410 + 40;
        p2[6]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[8]->ax = qrand() % 410 + 520;
        p2[9]->ax = qrand() % 410 + 520;//初始化x位置
        p2[4]->ay = atomheight[ra%3];
        p2[5]->ay = atomheight[(ra+1)%3];
        p2[6]->ay = atomheight[(ra+2)%3];
        p2[7]->ay = atomheight[(ra+1)%3];
        p2[8]->ay = atomheight[(ra+2)%3];
        p2[9]->ay = atomheight[ra%3];//初始化y位置
        p2[4]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[4]->timer.start(50);//50ms刷新一次
        p2[7]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[7]->timer.start(50);//50ms刷新一次
        p2[8]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[8]->timer.start(50);//50ms刷新一次
        p2[5]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[5]->timer.start(50);//50ms刷新一次
        p2[6]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[6]->timer.start(50);//50ms刷新一次
        p2[9]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[9]->timer.start(50);//50ms刷新一次
        break;
    case 1:
        p2[1]->mava = true;
        p2[2]->mava = true;
        p2[1]->show();
        p2[2]->show();
        p2[1]->remake(rand_atom());
        p2[2]->remake(rand_atom());
        p2[1]->ax = qrand() % 890 + 40;
        p2[2]->ax = qrand() % 890 + 40;
        p2[1]->ay = atomheight[ra%3];
        p2[2]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[1]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[1]->timer.start(50);//50ms刷新一次
        p2[2]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[2]->timer.start(50);//50ms刷新一次
        break;
    case 2:
        p2[4]->mava = true;
        p2[7]->mava = true;
        p2[4]->show();
        p2[7]->show();
        p2[4]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[4]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[4]->ay = atomheight[ra%3];
        p2[7]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[4]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[4]->timer.start(50);//50ms刷新一次
        p2[7]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[7]->timer.start(50);//50ms刷新一次
        break;
    case 3:
        p2[4]->mava = true;
        p2[7]->mava = true;
        p2[8]->mava = true;
        p2[4]->show();
        p2[7]->show();
        p2[8]->show();
        p2[4]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[8]->remake(rand_atom());
        p2[4]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[8]->ax = qrand() % 410 + 520;
        p2[4]->ay = atomheight[ra%3];
        p2[7]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[8]->ay = atomheight[(ra+2)%3];
        p2[4]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[4]->timer.start(50);//50ms刷新一次
        p2[7]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[7]->timer.start(50);//50ms刷新一次
        p2[8]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[8]->timer.start(50);//50ms刷新一次
        break;
    case 4:
        p2[1]->mava = true;
        p2[2]->mava = true;
        p2[3]->mava = true;
        p2[1]->show();
        p2[2]->show();
        p2[3]->show();
        p2[1]->remake(rand_atom());
        p2[2]->remake(rand_atom());
        p2[3]->remake(rand_atom());
        p2[1]->ax = qrand() % 890 + 40;
        p2[2]->ax = qrand() % 890 + 40;
        p2[3]->ax = qrand() % 890 + 40;
        p2[1]->ay = atomheight[ra%3];
        p2[2]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[3]->ay = atomheight[(ra+2)%3];
        p2[1]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[1]->timer.start(50);//50ms刷新一次
        p2[2]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[2]->timer.start(50);//50ms刷新一次
        p2[3]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[3]->timer.start(50);//50ms刷新一次
        break;
    case 5:
        p2[4]->mava = true;
        p2[7]->mava = true;
        p2[8]->mava = true;
        p2[1]->mava = true;
        p2[4]->show();
        p2[7]->show();
        p2[8]->show();
        p2[1]->show();
        p2[4]->remake(rand_atom());
        p2[7]->remake(rand_atom());
        p2[8]->remake(rand_atom());
        p2[1]->remake(rand_atom());
        p2[4]->ax = qrand() % 410 + 40;
        p2[7]->ax = qrand() % 410 + 520;
        p2[8]->ax = qrand() % 410 + 520;
        p2[1]->ax = qrand() % 890 + 40;
        p2[4]->ay = atomheight[ra%3];
        p2[7]->ay = atomheight[(ra+1)%3];//初始化位置
        p2[8]->ay = atomheight[ra%3];
        p2[1]->ay = atomheight[(ra+2)%3];
        p2[4]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[4]->timer.start(50);//50ms刷新一次
        p2[7]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[7]->timer.start(50);//50ms刷新一次
        p2[8]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[8]->timer.start(50);//50ms刷新一次
        p2[1]->get_speed(30-qrand()%60,0);//获取原子速度
        p2[1]->timer.start(50);//50ms刷新一次
        break;
    default:
        break;
    }
    switch (bombti%5) {
    case 0:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[1]->get_speed(30 - qrand() % 60,0);
        pb[1]->timer.start(50);
        pb[2]->mava = true;
        pb[2]->show();
        pb[2]->make_bomb(qrand() % 15 + 25);
        pb[2]->ax = qrand() % 890 + 40;
        pb[2]->ay = qrand() % 250 + 230;
        pb[2]->get_speed(30 - qrand() % 60,0);
        pb[2]->timer.start(50);
        pb[4]->mava = true;
        pb[4]->show();
        pb[4]->make_bomb(qrand() % 15 + 20);
        pb[4]->ax = qrand() % 890 + 40;
        pb[4]->ay = qrand() % 250 + 230;
        pb[4]->get_speed(0,0);
        pb[4]->timer.start(50);
        pb[5]->mava = true;
        pb[5]->show();
        pb[5]->make_bomb(qrand() % 15 + 25);
        pb[5]->ax = qrand() % 890 + 40;
        pb[5]->ay = qrand() % 250 + 230;
        pb[5]->get_speed(0,0);
        pb[5]->timer.start(50);
        pb[3]->mava = true;
        pb[3]->show();
        pb[3]->make_bomb(qrand() % 15 + 30);
        pb[3]->ax = qrand() % 890 + 40;
        pb[3]->ay = qrand() % 250 + 230;
        pb[3]->get_speed(0,0);
        pb[3]->timer.start(50);
        break;
    case 1:
        break;
    case 2:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[1]->get_speed(0,0);
        pb[1]->timer.start(50);
        break;
    case 3:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[1]->get_speed(0,0);
        pb[1]->timer.start(50);
        pb[2]->mava = true;
        pb[2]->show();
        pb[2]->make_bomb(qrand() % 15 + 25);
        pb[2]->ax = qrand() % 890 + 40;
        pb[2]->ay = qrand() % 250 + 230;
        pb[2]->get_speed(0,0);
        pb[2]->timer.start(50);
        pb[3]->mava = true;
        pb[3]->show();
        pb[3]->make_bomb(qrand() % 15 + 30);
        pb[3]->ax = qrand() % 890 + 40;
        pb[3]->ay = qrand() % 250 + 230;
        pb[3]->get_speed(0,0);
        pb[3]->timer.start(50);
        break;
        break;
        break;
        break;
    case 4:
        pb[1]->mava = true;
        pb[1]->show();
        pb[1]->make_bomb(qrand() % 15 + 20);
        pb[1]->ax = qrand() % 890 + 40;
        pb[1]->ay = qrand() % 250 + 230;
        pb[1]->get_speed(30 - qrand() % 60,0);
        pb[1]->timer.start(50);
        pb[2]->mava = true;
        pb[2]->show();
        pb[2]->make_bomb(qrand() % 15 + 25);
        pb[2]->ax = qrand() % 890 + 40;
        pb[2]->ay = qrand() % 250 + 230;
        pb[2]->get_speed(30 - qrand() % 60,0);
        pb[2]->timer.start(50);
        break;
    default:
        break;
    }
    update_atomnum();
    update_atomtable();
    timer1.start();
    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A)//A键炮台左移
    {
        b1->move(b1->pos().x()-15,b1->pos().y());
        if(b1->pos().x()<10)//限制移动范围
        {
            b1->move(10,b1->pos().y());
        }
    }
    if(event->key()==Qt::Key_D)//D键炮台右移
    {
        b1->move(b1->pos().x()+15,b1->pos().y());
        if(b1->pos().x()>880)//限制移动范围
        {
            b1->move(880,b1->pos().y());
        }
    }
    if(event->key()==Qt::Key_Q)//board2.cpp里面有注释
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
    if(event->key()==Qt::Key_Space&&b1->ava)//当可以发射原子的时候，按空格发射原子
    {
        b1->getCenter();
        p1->ax = b1->pos().x()+b1->cter.x()+32*cos(b1->ang/180*3.1415926);
        p1->ay = b1->pos().y()+b1->cter.y()+37-32*sin(b1->ang/180*3.1415926);//原子的初始位置是炮台相应顶端
        p1->get_position(p1->ax,p1->ay);
        p1->get_speed(30,b1->ang);//获取原子速度
        p1->mava = true;//发射出原子，原子可以动了
        p1->show();
        p1->timer.start(50);//50ms刷新一次
        b1->ava = false;//炮台发射过一次，不能再次发射
        atomnum[maxatom]--;
        update_atomtable();
        ui->storeButton->setDisabled(true);
        update();
    }
}

void MainWindow::shopupdate()
{
    bombva = sh->money;
    ui->score->display(bombva);
    for(int i=1;i<=9;++i)
    {
        mi[i] = sh->ava[i];
    }
    sh->hide();
}

void MainWindow::colli_detect1()//检查发射出去的原子与轨道上原子的碰撞
{
    for(int i=1;i<=9;++i)//逐个检验
    {
        if(p1->mava == true&&p2[i]->mava == true)
        {
            if(QRect(p1->pos().x(),p1->pos().y(),p1->frameSize().width(),p1->frameSize().height()).intersects(QRect(p2[i]->pos().x(),p2[i]->pos().y(),p2[i]->frameSize().width(),p2[i]->frameSize().height())))
            {
                p1->mava = false;
                p2[i]->mava = false;//消失，不可用
                for(int j=0;j<20;++j)//爆炸效果
                {
                    if(!bb[j]->bava)
                    {
                        bb[j]->bava = true;
                        bb[j]->move(p2[i]->pos());
                        bb[j]->show();//产生爆炸效果
                        get_new_atom(i,0);//产生新原子
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::colli_detect2()//检查碰撞产生的原子与轨道上原子的碰撞，具体同上
{
    for(int i=1;i<=9;++i)
    {
        if(p2[i]->mava == false)
        {
            continue;
        }
        for(int j=1;j<=19;++j)
        {
            if(p3[j]->mava == false)
            {
                continue;
            }
            if(QRect(p2[i]->pos().x(),p2[i]->pos().y(),p2[i]->frameSize().width(),p2[i]->frameSize().height()).intersects(QRect(p3[j]->pos().x(),p3[j]->pos().y(),p3[j]->frameSize().width(),p3[j]->frameSize().height())))
            {
                p3[j]->mava = false;
                p2[i]->mava = false;
                for(int k=0;k<20;++k)
                {
                    if(!bb[k]->bava)
                    {
                        bb[k]->bava = true;
                        bb[k]->move(p2[i]->pos());
                        bb[k]->show();
                        get_new_atom(i,j);
                        break;
                    }
                }
                break;
            }
        }
    }
}

void MainWindow::colli_detect3()//检查发射出去的原子与原子爆弹的碰撞
{
    for(int i=1;i<=9;++i)//逐个检验
    {
        if(p1->mava == true&&pb[i]->mava == true)
        {
            if(QRect(p1->pos().x(),p1->pos().y(),p1->frameSize().width(),p1->frameSize().height()).intersects(QRect(pb[i]->pos().x(),pb[i]->pos().y(),pb[i]->frameSize().width(),pb[i]->frameSize().height())))
            {
                p1->mava = false;
                pb[i]->mava = false;//消失，不可用
                bombva++;
                ui->score->display(bombva);
                for(int j=0;j<20;++j)//爆炸效果
                {
                    if(!bb[j]->bava)
                    {
                        bb[j]->bava = true;
                        bb[j]->move(pb[i]->pos());
                        bb[j]->show();//产生爆炸效果
                        break;
                    }
                }
            }
        }
    }
}

void MainWindow::colli_detect4()//检查碰撞产生的原子与轨道上原子的碰撞，具体同上
{
    for(int i=1;i<=9;++i)
    {
        if(pb[i]->mava == false)
        {
            continue;
        }
        for(int j=1;j<=19;++j)
        {
            if(p3[j]->mava == false)
            {
                continue;
            }
            if(QRect(pb[i]->pos().x(),pb[i]->pos().y(),pb[i]->frameSize().width(),pb[i]->frameSize().height()).intersects(QRect(p3[j]->pos().x(),p3[j]->pos().y(),p3[j]->frameSize().width(),p3[j]->frameSize().height())))
            {
                p3[j]->mava = false;
                pb[i]->mava = false;
                bombva++;
                ui->score->display(bombva);
                for(int k=0;k<20;++k)
                {
                    if(!bb[k]->bava)
                    {
                        bb[k]->bava = true;
                        bb[k]->move(pb[i]->pos());
                        bb[k]->show();
                        break;
                    }
                }
                break;
            }
        }
    }
}

int MainWindow::produce_new_atom(int i, int k)//产生新的原子，传入的i是轨道上原子的编号，用于定位，k是赋给新原子的序数，传出k
{
    for(int l=1;l<20;++l)
    {
        if(!p3[l]->mava)//一些初始化
        {
            p3[l]->mava = true;
            p3[l]->remake(k);
            p3[l]->show();
            p3[l]->ax = p2[i]->ax;
            p3[l]->ay = p2[i]->ay;
            p3[l]->get_position(p3[l]->ax,p3[l]->ay);
            p3[l]->get_speed((5 + qrand() % 25) * (1 - 2 * qrand() % 2), 150 - qrand() % 120);
            p3[l]->timer.start(50);
            return k+1;
        }
    }
    return 1;
}

void MainWindow::get_new_atom(int i, int j)//决定产生什么新原子，i是轨道上原子的编号，j是主动碰撞的原子编号，j=0代表p1
{
    if(j == 0)
    {
        int add = p1->kind * p2[i]->kind;//爆弹值的增量
        if(p1->kind+p2[i]->kind < 4)//原子序数和小于4，只生成一个原子
        {
            add *= produce_new_atom(i,p1->kind + p2[i]->kind);
        }
        else
        {
            int tmp = qrand() % 7;
            if(tmp < 3)//生成两个原子
            {
                add *= produce_new_atom(i,(p1->kind + p2[i]->kind) / 2);
                add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2);
            }
            else if(tmp < 5)//生成两个原子，序数与前种不同
            {
                add *= produce_new_atom(i, (p1->kind + p2[i]->kind) / 2 + 1);
                add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 - 1);
            }
            else//生成三个原子
            {
                add *= produce_new_atom(i, (p1->kind + p2[i]->kind) / 2);
                add *= produce_new_atom(i,(p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2) / 2);
                add *= produce_new_atom(i, p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2 - (p1->kind + p2[i]->kind - (p1->kind + p2[i]->kind) / 2) / 2);
            }
        }
        bombva += add;
        ui->score->display(bombva);//增加爆弹值，刷新LCD
    }
    else//同上
    {
        int add = p2[i]->kind * p3[j]->kind;
        if(p3[j]->kind+p2[i]->kind < 4)
        {
            add *= produce_new_atom(i,p3[j]->kind + p2[i]->kind);
        }
        else
        {
            int tmp = qrand() % 7;
            if(tmp < 3)
            {
                add *= produce_new_atom(i,(p3[j]->kind + p2[i]->kind) / 2);
                add *= produce_new_atom(i, p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2);
            }
            else if(tmp < 5)
            {
                add *= produce_new_atom(i, (p3[j]->kind + p2[i]->kind) / 2 + 1);
                add *= produce_new_atom(i, p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2 - 1);
            }
            else
            {
                add *= produce_new_atom(i, (p3[j]->kind + p2[i]->kind) / 2);
                add *= produce_new_atom(i,(p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2) / 2);
                add *= produce_new_atom(i, p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2 - (p3[j]->kind + p2[i]->kind - (p3[j]->kind + p2[i]->kind) / 2) / 2);
            }
        }
        bombva += add;
        ui->score->display(bombva);
    }
}

void MainWindow::end_pop()
{
    update_atomnum();
    update_atomtable();
    for(int i=1;i<=9;++i)
    {
        p2[i]->mava = false;
    }
    for(int i=0;i<=9;++i)
    {
        pb[i]->mava = false;
    }
    if(maxatom == 0)
    {
        gameover();
    }
    else if(maxatom == 12)
    {
        win();
    }
    else
    {
        delete p1;
        pop_prepare();
    }
}

void MainWindow::rece_detect1()//检测p1的接收情况
{
    if(p1->mava&&QRect(b1->pos().x(),b1->pos().y()+40,b1->ui->receive->frameSize().width(),b1->ui->receive->frameSize().height()).intersects(QRect(p1->pos().x(),p1->pos().y(),p1->frameSize().width(),p1->frameSize().height())))
    {
        p1->rece = true;//用于计数原子
        b1->rece = true;//用于产生接收的黄光效果
        p1->mava = false;//设置原子为不可用
        atomnum[p1->kind]++;
        update_atomtable();
        bombva += 100 * p1->kind;
        if(bombti < 4)//新手奖励，在前三局接到每个球，分别奖励300,200,100爆弹值
        {
            bombva += (400 - 100 * bombti);
        }
        ui->score->display(bombva);//收到原子得到爆弹值是原子序数的100倍;
    }
}

void MainWindow::rece_detect2()//检测p3系列的接收情况
{
    for(int i=1;i<=19;++i)
    {
        if(!p3[i]->mava)
        {
            continue;
        }
        if(QRect(b1->pos().x(),b1->pos().y()+40,b1->ui->receive->frameSize().width(),b1->ui->receive->frameSize().height()).intersects(QRect(p3[i]->pos().x(),p3[i]->pos().y(),p3[i]->frameSize().width(),p3[i]->frameSize().height())))
        {
            p3[i]->rece = true;
            b1->rece = true;
            p3[i]->mava = false;
            atomnum[p3[i]->kind]++;
            update_atomtable();
            bombva += 100 * p3[i]->kind;
            if(bombti < 4)//新手奖励，在前三局接到每个球，分别奖励300,200,100爆弹值
            {
                bombva += (400 - 100 * bombti);
            }
            ui->score->display(bombva);
        }
    }
}

void MainWindow::end_detect()//检测本次发射产生的效果是否结束
{
    if(p1->mava)
    {
        return;
    }
    for(int i=1;i<=19;++i)
    {
        if(p3[i]->mava)
        {
            return;
        }
    }
    if(!b1->ava)
    {
        end_pop();
    }
}

void MainWindow::win()
{
    int hh[4]={
        148,278,408,538
    };
    int ww[5]={
        153,303,453,603,753
    };
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<5;++j)
        {
            bb[5*i+j]->bava = true;
            bb[5*i+j]->move(ww[j],hh[i]);
            bb[5*i+j]->show();
        }
    }
}

void MainWindow::gameover()//失败的效果展示
{
    int hh[4]={
        148,278,408,538
    };
    int ww[5]={
        153,303,453,603,753
    };
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<5;++j)
        {
            bb[5*i+j]->bava = true;
            bb[5*i+j]->move(ww[j],hh[i]);
            bb[5*i+j]->show();
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_storeButton_clicked()
{
    sh->money = bombva;
    sh->ui->rest->setText(QString::number(sh->money));
    for(int i=1;i<=9;++i)
    {
        sh->level[i] = il[i];
        sh->ava[i] = 0;
    }
    for(int i=1;i<=9;++i)
    {
        if(qrand() % 2)
        {
            sh->pri[i] = bombva+1;
        }
        else if(qrand() % 3 == 0)
        {
            sh->pri[i] = qrand() % 300 + 1;
        }
        else
        {
            sh->pri[i] = qrand() % 300 + 301;
        }
    }
    sh->pri[10] = qrand() % 600 + 1;
    sh->ui->pr1->setText(QString::number(sh->pri[1]));
    sh->ui->pr2->setText(QString::number(sh->pri[2]));
    sh->ui->pr3->setText(QString::number(sh->pri[3]));
    sh->ui->pr4->setText(QString::number(sh->pri[4]));
    sh->ui->pr5->setText(QString::number(sh->pri[5]));
    sh->ui->pr6->setText(QString::number(sh->pri[6]));
    sh->ui->pr7->setText(QString::number(sh->pri[7]));
    sh->ui->pr8->setText(QString::number(sh->pri[8]));
    sh->ui->pr9->setText(QString::number(sh->pri[9]));
    sh->ui->prran->setText(QString::number(sh->pri[10]));
    sh->ui->buy1->setEnabled(true);
    sh->ui->buy2->setEnabled(true);
    sh->ui->buy3->setEnabled(true);
    sh->ui->buy4->setEnabled(true);
    sh->ui->buy5->setEnabled(true);
    sh->ui->buy6->setEnabled(true);
    sh->ui->buy7->setEnabled(true);
    sh->ui->buy8->setEnabled(true);
    sh->ui->buy9->setEnabled(true);
    sh->ui->buyrandom->setEnabled(true);
    sh->show();
}
