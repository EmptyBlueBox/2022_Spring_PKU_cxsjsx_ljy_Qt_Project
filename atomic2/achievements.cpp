#include "achievements.h"
#include "ui_achievements.h"

Achievements::Achievements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Achievements)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog|Qt::CustomizeWindowHint);
}

Achievements::~Achievements()
{
    delete ui;
}

void Achievements::on___ach_1_clicked()
{
    this->hide();
}
