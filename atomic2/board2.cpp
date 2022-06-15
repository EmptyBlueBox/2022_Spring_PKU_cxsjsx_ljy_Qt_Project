#include "board2.h"
#include "ui_board2.h"

Board2::Board2(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Board2)
{
    ui->setupUi(this);
    ava = true;
    ang = 90.0;
}

void Board2::getCenter()
{
    QRect rct = ui->receive->frameRect();
    cter = QPoint(rct.center());
}

void Board2::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(ava)
    {
        getCenter();
        painter.setPen(QPen(Qt::red,20,Qt::SolidLine,Qt::RoundCap));
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawLine(QPoint(cter.x(),cter.y()+37),QPoint(cter.x()+32*cos(ang/180*3.1415926),cter.y()+37-32*sin(ang/180*3.1415926)));
    }
}

void Board2::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Q)
    {
        ang+=2.0;
        if(ang>170.0)
        {
            ang=170.0;
        }
        update();
    }
    if(event->key()==Qt::Key_E)
    {
        ang-=2.0;
        if(ang<10.0)
        {
            ang=10.0;
        }
        update();
    }
}

Board2::~Board2()
{
    delete ui;
}
