#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_start_game_button_clicked()
{
    w1.show();
    this->hide();
}
