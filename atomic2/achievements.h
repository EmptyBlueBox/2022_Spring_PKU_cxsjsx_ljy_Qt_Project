#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include <QDialog>

namespace Ui {
class Achievements;
}

class Achievements : public QDialog
{
    Q_OBJECT

public:
    explicit Achievements(QWidget *parent = 0);
    ~Achievements();

private slots:
    void on___ach_1_clicked();

private:
    Ui::Achievements *ui;
};

#endif // ACHIEVEMENTS_H
