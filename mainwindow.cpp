#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QWidget * xparent = new QWidget;
//    this->setParent(xparent);
    this->initView();
    this->initData();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}

void MainWindow::on_pushButton_clicked()
{


    canvas->show();

}

void MainWindow::on_activatedTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
//    case QSystemTrayIcon::Trigger:
//        trayIcon->showMessage(QString::fromUtf8("显示界面1"),QString::fromUtf8("显示界面2"),QSystemTrayIcon::Information,1000);
//        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    default:
        break;
    }
}

void MainWindow::on_showAction()
{
    this->show();
}

void MainWindow::on_captureAction()
{

}

void MainWindow::on_exitAction()
{
    qApp->quit();
}

void MainWindow::initData()
{
    trayIcon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(QString::fromUtf8(":/tool box.png"));
    trayIcon->setIcon(icon);
    trayIcon->setToolTip(QStringLiteral("ScreenCapture"));
    QObject::connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedTrayIcon(QSystemTrayIcon::ActivationReason)));
    this->addTrayAction();
    this->addTrayMenu();
    trayIcon->show();
}

void MainWindow::initView()
{
    canvas = new Canvas();
}

void MainWindow::addTrayMenu()
{
    trayMenu = new QMenu(this);
    trayMenu->addAction(showAction);
    trayMenu->addAction(captureAction);
    trayMenu->addSeparator();
    trayMenu->addAction(exitAction);
    this->trayIcon->setContextMenu(trayMenu);
}

void MainWindow::addTrayAction()
{
    showAction = new QAction(QString::fromUtf8("显示界面"),this);
    connect(showAction,SIGNAL(triggered(bool)),this,SLOT(on_showAction()));
    captureAction = new QAction(QString::fromUtf8("截屏"),this);
    connect(captureAction,SIGNAL(triggered(bool)),this,SLOT(on_captureAction()));
    exitAction = new QAction(QString::fromUtf8("推出"),this);
    connect(exitAction,SIGNAL(triggered(bool)),this,SLOT(on_exitAction()));
}

