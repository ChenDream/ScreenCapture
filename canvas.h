#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
//#include "floatingwindow.h"
#include "zoominform.h"

class Canvas: public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();
    void show();
signals:
    void sendZoomin(QPixmap &pixmap,int x,int y);
private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyReleaseEvent(QKeyEvent *key);
    void paintEvent(QPaintEvent *e);

private:
    void initView();
    void initData();
    QPixmap pixmap;
//    FloatingWindow *floatWindow;
    ZoominForm *zoominForm;

};

#endif // CANVAS_H
