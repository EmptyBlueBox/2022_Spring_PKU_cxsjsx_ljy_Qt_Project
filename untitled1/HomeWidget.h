#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QWidget>
#include "callbacktype.h"

namespace Ui
{
class HomeWidget;
}

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = 0);
    ~HomeWidget();
    void setCallBackEvent(VOID_CallBackEvent_VOID Event);   // 添加回调事件

private slots:
    void on_pushButton_clicked();

private:
    Ui::HomeWidget *ui;
    VOID_CallBackEvent_VOID CallBackEvent;      // 保存回调事件
};

#endif // HOMEWIDGET_H
