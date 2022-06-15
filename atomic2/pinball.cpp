#include "pinball.h"
#include "ui_pinball.h"

int rr[27]={
    0,18,26,26,26,24,24,22,22,20,30,38,38,36,36,34,34,32,40,50,48,48,46,46,44,42,42
};

int cr[27]={
    0,135,0,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,0,19,20,21,22,23,24,25,26
};

int cg[27]={
    0,206,0,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,0,19,20,21,22,23,24,25,26
};

int cb[27]={
    0,250,255,3,4,5,6,7,8,9,205,11,12,13,14,15,16,17,139,19,20,21,22,23,24,25,26
};

Pinball::Pinball(int k, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Pinball)
{
    ui->setupUi(this);
    kind=k;
    this->resize(rr[k],rr[k]);
    col=QColor(cr[k],cg[k],cb[k]);
    vx = 0;
    vy = 0;
    ax = 0;
    ay = 0;
    mava = false;
    rece = false;
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
}

void Pinball::get_speed(int v, double ang)
{
    vx = v*cos(ang/180*3.1415926);
    vy = -v*sin(ang/180*3.1415926);
}

void Pinball::get_position(double x,double y)
{
    double mx = x - this->frameSize().width()/2.0;
    double my = y - this->frameSize().height()/2.0;
    this->move((int)mx,(int)my);
}

void Pinball::onTimeout(void)
{
    ax += vx;
    ay += vy;
    if(ax > 960 - this->frameSize().width()/2.0)
    {
        ax = 960 - this->frameSize().width()/2.0;
        vx = -0.9*vx;
    }
    if(ax < 10 + this->frameSize().width()/2.0)
    {
        ax = 10 + this->frameSize().width()/2.0;
        vx = -0.9*vx;
    }
    if(ay > 710 - this->frameSize().height()/2.0)
    {
        ay = 710 - this->frameSize().height()/2.0;
        vy = -0.9*vy;
    }
    if(ay < 40 + this->frameSize().height()/2.0)
    {
        ay = 40 + this->frameSize().height()/2.0;
        vy = -0.9*vy;
    }
    this->get_position(ax,ay);
    update();
}

void Pinball::paintEvent(QPaintEvent *)
{   if(mava)
    {
        QPainter painter(this);
        QBrush brush(col);
        painter.setBrush(brush);
        painter.drawEllipse(this->frameRect().center(),this->frameRect().width()/2-1,this->frameRect().height()/2-1);
    }
}

Pinball::~Pinball()
{
    delete ui;
}
