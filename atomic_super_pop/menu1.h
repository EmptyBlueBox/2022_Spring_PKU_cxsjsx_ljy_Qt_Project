#ifndef MENU1_H
#define MENU1_H

#include <QDialog>

namespace Ui {
class menu1;
}

class menu1 : public QDialog
{
    Q_OBJECT

public:
    explicit menu1(QWidget *parent = 0);
    ~menu1();

private:
    Ui::menu1 *ui;
};

#endif // MENU1_H
