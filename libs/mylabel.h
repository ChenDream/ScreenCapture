#ifndef MYLABEL_H
#define MYLABEL_H
#include "stdafx.h"

class MyLabel:public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0):QLabel(parent){
        father = parent;
        setMouseTracking(true);
    }

protected:
    void mouseMoveEvent(QMouseEvent *e){
        auto pos = QCursor::pos();
        //label do not neet to move,parent need to move
        father->move(pos.x(),pos.y());
    }

private:
    QWidget *father;
};
#endif // MYLABEL_H
