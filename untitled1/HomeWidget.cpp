#include "HomeWidget.h"
#include "ui_HomeWidget.h"

HomeWidget::HomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWidget),
    CallBackEvent(NULL)
{
    ui->setupUi(this);
}

HomeWidget::~HomeWidget()
{
    delete ui;
}

void HomeWidget::setCallBackEvent(VOID_CallBackEvent_VOID Event)
{
    CallBackEvent = Event;
}

void HomeWidget::on_pushButton_clicked()
{
    this->hide();

    if (CallBackEvent)
    {
        CallBackEvent();
    }
}


