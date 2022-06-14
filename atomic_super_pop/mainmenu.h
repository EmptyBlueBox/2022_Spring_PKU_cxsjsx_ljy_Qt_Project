#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include "menu1.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT
public:
    menu1 w1;

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:
    void on_start_game_button_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
