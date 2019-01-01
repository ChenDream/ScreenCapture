#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //https://blog.csdn.net/zhuyunfei/article/details/51433822
    void on_pushButton_clicked();
    void on_activatedTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void on_showAction();
    void on_captureAction();
    void on_exitAction();
private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    void initData();
    void initView();

    //tray relate
    QMenu *trayMenu;
    QAction *showAction;
    QAction *captureAction;
    QAction *exitAction;
    QSystemTrayIcon *trayIcon;
    void addTrayMenu();
    void addTrayAction();
};

#endif // MAINWINDOW_H
