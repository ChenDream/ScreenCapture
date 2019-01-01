#include "zoominform.h"
#include "libs/stdafx.h"


ZoominForm::ZoominForm(QWidget *parent): QWidget(parent)
{
    this->initView();
    this->initData();
}

ZoominForm::~ZoominForm()
{

}

void ZoominForm::receiveImage(QPixmap &pixmap,int x,int y)
{
    pm =pixmap.scaled(pm.width(),pm.height());
    this->addFrontSight(pm);
    background->setPixmap(pm);
    this->pos->setText(QStringLiteral("pos(")+
                       QString::number(x)+QStringLiteral(",")+QString::number(y)+QStringLiteral(")"));

}

void ZoominForm::mousePressEvent(QMouseEvent *event)
{

}

void ZoominForm::mouseMoveEvent(QMouseEvent *event)
{
    auto pos = QCursor::pos();
    //label do not neet to move,parent need to move
    this->move(pos.x(),pos.y());
}

void ZoominForm::mouseReleaseEvent(QMouseEvent *event)
{

}

void ZoominForm::paintEvent(QPaintEvent *e)
{

}

void ZoominForm::initView()
{
    //120,164
    this->resize(140,190);
//    this->setStyleSheet(QLatin1String("background-color: rgb(64, 66, 68);\n"));
    QWidget *widget = new QWidget(this);
    widget->setObjectName(QStringLiteral("back"));
    widget->setGeometry(QRect(0,0,140,190));
    widget->setStyleSheet(QLatin1String("background-color: rgb(64, 66, 68);\n"));


    background = new MyLabel(this);
    background->setObjectName(QStringLiteral("background"));
    background->setGeometry(QRect(2, 2, 136, 136));
    background->setStyleSheet(QLatin1String("border:1px solid white;\n"));

    pos = new MyLabel(this);
    pos->setObjectName(QStringLiteral("pos"));
    pos->setGeometry(QRect(0, 140, 140, 25));
    QFont font;
    font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font.setPointSize(9);
    font.setBold(false);
    font.setWeight(50);
    pos->setFont(font);
    pos->setStyleSheet(QLatin1String("border:none;color: rgb(255, 255, 255);"));
    pos->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    pos->setMargin(4);

    color = new MyLabel(this);
    color->setObjectName(QStringLiteral("color"));
    color->setGeometry(QRect(0, 165, 140, 25));
    QFont font1;
    font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font1.setPointSize(9);
    color->setFont(font1);
    color->setStyleSheet(QLatin1String("border:none;color: rgb(255, 255, 255);"));
    color->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
    color->setMargin(4);

    pos->setText(QLatin1String("pos(1980,1024)"));
    color->setText(QLatin1String("RGB:(255,255,255)"));
}

void ZoominForm::initData()
{
    //30*30 pp
//    this->setWindowFlags(this->windowFlags()|Qt::SubWindow|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    pm = QPixmap(background->width(),background->height());
    this->addFrontSight(pm);
    background->setPixmap(pm);
}

void ZoominForm::addFrontSight(QPixmap &p)
{
    if(p.isNull())return;
    int width = p.width();
    int height = p.height();
    QPainter painter(&p);
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(0,229,238));
    painter.setPen(pen);
    //from left to right
    painter.drawLine(0,height/2,width,height/2);
    //from top to bottom
    painter.drawLine(width/2,0,width/2,height);
}
