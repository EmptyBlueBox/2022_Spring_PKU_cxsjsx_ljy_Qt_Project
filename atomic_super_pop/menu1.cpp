#include "menu1.h"
#include "ui_menu1.h"

menu1::menu1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu1)
{
    ui->setupUi(this);
}

menu1::~menu1()
{
    delete ui;
}
