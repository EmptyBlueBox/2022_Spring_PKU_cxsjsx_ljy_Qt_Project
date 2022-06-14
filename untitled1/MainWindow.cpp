#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "HomeWidget.h"
#include "SetWidget.h"
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pHomeWidget(NULL),
    m_pSetWidget(NULL)
{
    ui->setupUi(this);

    m_pHomeWidget = new HomeWidget(this);
    m_pHomeWidget->setCallBackEvent(BindEvent(&MainWindow::HideHomeWidget,this)); // 绑定类对象 回调函数, 传递回掉函数进去B类

    m_pSetWidget = new SetWidget(this);
    m_pSetWidget->setCallBackEvent(BindEvent(&MainWindow::HideSetWidget,this));
    m_pSetWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_pHomeWidget)
        delete m_pHomeWidget;
    if (m_pSetWidget)
        delete m_pSetWidget;
}

void MainWindow::HideHomeWidget()
{
    m_pSetWidget->show();
}

void MainWindow::HideSetWidget()
{
    m_pHomeWidget->show();
}
