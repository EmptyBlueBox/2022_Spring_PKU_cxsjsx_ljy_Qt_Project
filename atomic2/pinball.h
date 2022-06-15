#ifndef PINBALL_H
#define PINBALL_H

#include <QFrame>
#include <QPainter>
#include <QTimer>

namespace Ui {
class Pinball;
}

class Pinball : public QFrame
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *);
private slots:
    void onTimeout(void);
public:
    QColor col;
    int kind;
    double vx;
    double vy;
    double ax;
    double ay;
    bool mava;
    bool rece;
    QTimer timer;
public:
    explicit Pinball(int k = 1, QWidget *parent = 0);
    ~Pinball();
    void get_speed(int,double);
    void get_position(double,double);

private:
    Ui::Pinball *ui;
};

#endif // PINBALL_H
