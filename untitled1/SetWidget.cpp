#include "SetWidget.h"
#include "ui_SetWidget.h"

SetWidget::SetWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetWidget),
    CallBackEvent(NULL)
{
    ui->setupUi(this);
}

SetWidget::~SetWidget()
{
    delete ui;
}

void SetWidget::setCallBackEvent(VOID_CallBackEvent_VOID Event)
{
    CallBackEvent = Event;
}

void SetWidget::on_pushButton_clicked()
{
    this->hide();
    if (CallBackEvent)
        CallBackEvent();
}
