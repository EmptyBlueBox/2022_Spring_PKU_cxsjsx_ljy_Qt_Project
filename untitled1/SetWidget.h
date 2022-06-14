#ifndef SETWIDGET_H
#define SETWIDGET_H

#include <QWidget>
#include "callbacktype.h"

namespace Ui
{
class SetWidget;
}

class SetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SetWidget(QWidget *parent = 0);
    ~SetWidget();

    void setCallBackEvent(VOID_CallBackEvent_VOID Event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::SetWidget *ui;
    VOID_CallBackEvent_VOID CallBackEvent;
};

#endif // SETWIDGET_H
