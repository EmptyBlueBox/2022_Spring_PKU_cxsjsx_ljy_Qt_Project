#ifndef BOARD2_H
#define BOARD2_H

#include <QFrame>
#include <QPainter>
#include <QKeyEvent>

namespace Ui {
class Board2;
}

class Board2 : public QFrame
{
    Q_OBJECT
private:
    void paintEvent(QPaintEvent *);
    void getCenter();

public:
    explicit Board2(QWidget *parent = 0);
    ~Board2();
    void keyPressEvent(QKeyEvent *);
    double ang;

private:
    Ui::Board2 *ui;
    bool ava;
    QPoint cter;
};

#endif // BOARD2_H
