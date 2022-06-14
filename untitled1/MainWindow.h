#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

class HomeWidget;
class SetWidget;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void HideHomeWidget();
    void HideSetWidget();

private:
    Ui::MainWindow *ui;
    QStackedWidget* m_pStackedWidget;
    HomeWidget* m_pHomeWidget;
    SetWidget*  m_pSetWidget;
};

#endif // MAINWINDOW_H
