#ifndef ZOOMINFORM_H
#define ZOOMINFORM_H


#include <QWidget>
#include "libs/mylabel.h"

class ZoominForm: public QWidget
{
    Q_OBJECT
public:
    explicit ZoominForm(QWidget *parent = 0);
    ~ZoominForm();
public slots:
    void receiveImage(QPixmap &pixmap,int x,int y);
private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *e);
private:
    void initView();
    void initData();
    void addFrontSight(QPixmap& p);

    MyLabel *background;
    MyLabel *pos;
    MyLabel *color;
    QPixmap pm;
};

#endif // ZOOMINFORM_H
