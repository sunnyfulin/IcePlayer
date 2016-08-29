#include "lrcwidget.h"
#include "lrclabel.h"

#include <QPainter>
#include <QMouseEvent>

CLrcWidget::CLrcWidget(QWidget *parent) : QWidget(parent),_isMoveState(false)
{
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(800, 80);
    setVisible(false);

    _lrcLabel = new CLrcLabel(this);
    _lrcLabel->setGeometry(QRect(0, 6, 800, 60));
}

void CLrcWidget::StartLrcMask(qint64 intervalTime)
{
    _lrcLabel->StartLrcMask(intervalTime);
}

void CLrcWidget::StopLrcMask()
{
    _lrcLabel->StopLrcMask();
}

QString CLrcWidget::GetText() const
{
    return _lrcLabel->text();
}

void CLrcWidget::SetText(const QString &t)
{
    _lrcLabel->setText(t);
}

void CLrcWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(0, 0, QPixmap(":/pic/lrc_background.png"));
}

void CLrcWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() != Qt::LeftButton && !_isMoveState)
        return;

    _isMoveState = true;

    _x = e->pos().x();
    _y = e->pos().y();
}

void CLrcWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->button() != Qt::LeftButton && !_isMoveState)
        return;

    QPoint curPos = e->globalPos();
    move(curPos.x() - _x ,curPos.y() - _y);
}

void CLrcWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() != Qt::LeftButton)
        return;

    _isMoveState = false;
}
