#include "aboutframe.h"
#include "icebutton.h"

#include <QPainter>
#include <QMouseEvent>
#include <QPoint>

CAboutFrame::CAboutFrame(QWidget *parent) : QWidget(parent),_isMoveState(false)
{
    CIceButton * exitButton = new CIceButton(this);
    exitButton->setGeometry(QRect(255, 12, 30, 30));
    exitButton->setIconSize(QSize(20,20));

    QIcon icon_exit(":/pic/closeButton.png");
    QIcon icon_exit_press(":/pic/closeButton2.png");
    exitButton->SetButtonIcons(icon_exit, icon_exit_press);
    connect(exitButton,&CIceButton::clicked,this,&CAboutFrame::hide);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowOpacity(0.9);
    setFixedSize(300, 400);
    setVisible(false);
}

void CAboutFrame::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0 , QPixmap(":/pic/about.png"));
}

void CAboutFrame::mousePressEvent(QMouseEvent * e)
{
    if(e->button() != Qt::LeftButton && !_isMoveState)
        return;

    _isMoveState = true;

    _x = e->pos().x();
    _y = e->pos().y();
}

void CAboutFrame::mouseMoveEvent(QMouseEvent * e)
{
    if(e->button() != Qt::LeftButton && !_isMoveState)
        return;

    QPoint curPos = e->globalPos();
    move(curPos.x() - _x ,curPos.y() - _y);
}

void CAboutFrame::mouseReleaseEvent(QMouseEvent * e)
{
    if(e->button() != Qt::LeftButton)
        return;

    _isMoveState = false;
}
