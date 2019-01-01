#include "canvas.h"
#include "libs/stdafx.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    this->initData();
    this->initView();
}

Canvas::~Canvas()
{
    qDebug("delete canvas");
}

void Canvas::show()
{

    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;
    pixmap = screen->grabWindow(0);

    this->showFullScreen();

    auto pos = QCursor::pos();
    zoominForm->move(pos.x(),pos.y());
    zoominForm->show();
}


void Canvas::mousePressEvent(QMouseEvent *event)
{

}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::NoButton){

    }else if(event->buttons()&Qt::LeftButton){

    }
    auto pos = QCursor::pos();
//    auto pos = event->globalPos();
    // Todo: fix corner position
    zoominForm->move(pos.x()+15,pos.y()+20);
    // Todo: fix side and corner image
    auto imageCopy = [&]()->QPixmap{
        if(pos.x()-15>=0&&pos.y()-15>=0)return pixmap.copy(pos.x()-15,pos.y()-15,30,30);
        //rgb(64, 66, 68)
        int x=0,y=0,width=30,height=30;
        if(pos.x()-15<0){
            width += pos.x()-15;
        }else{
            x = pos.x()-15;
        }
        if(pos.y()-15<0){
            height += pos.y()-15;
        }else{
            y = pos.y()-15;
        }
        auto tem = pixmap.copy(x,y,width,height);
        QImage im(30,30,QImage::Format_RGB32);
        im.fill(QColor(64, 66, 68));

        
    };
    QPixmap pm =pixmap.copy(pos.x()-15,pos.y()-15,30,30);
//    emit sendZoominPixmap(imageCopy());
    emit sendZoomin(pm,pos.x(),pos.y());
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{

}

void Canvas::keyReleaseEvent(QKeyEvent *key)
{
    if(key->key() == Qt::Key_Escape){
        this->hide();
        return;
    }
    QWidget::keyReleaseEvent(key);
}

void Canvas::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pixmap);
}

void Canvas::initView()
{
    zoominForm->hide();
}

void Canvas::initData()
{
    this->setWindowFlags(this->windowFlags()|Qt::SubWindow|Qt::WindowStaysOnTopHint|Qt::FramelessWindowHint);
    setMouseTracking(true);
    zoominForm = new ZoominForm(this);
    QObject::connect(this,SIGNAL(sendZoomin(QPixmap&,int,int)),zoominForm,SLOT(receiveImage(QPixmap&,int,int)));
    //TODO bugs wrong pos!!!!!
//    QCursor *mycursor = new QCursor(QPixmap(QString::fromUtf8(":/cursor.png")),-1,-1);
//    this->setCursor(*mycursor);
}
