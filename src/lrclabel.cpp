#include "lrclabel.h"

#include <QMenu>
#include <QFont>
#include <QPainter>
#include <QContextMenuEvent>

CLrcLabel::CLrcLabel(QWidget *parent) : CIceLabel("IcePlayer",parent)
{
    _linearGradient.setStart(0, 10);
    _linearGradient.setFinalStop(0, 40);
    _linearGradient.setColorAt(0, QColor(1, 150, 255));
    _lrcFont.setFamily(QStringLiteral("微软雅黑"));
    _lrcFont.setPointSize(25);
}

void CLrcLabel::StartLrcMask(qint64 intervalTime)
{

}

void CLrcLabel::StopLrcMask()
{

}

void CLrcLabel::SetTextSize(int size)
{
    _lrcFont.setPointSize(size);
}

void CLrcLabel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(_lrcFont);

    if(text().size() < 2)
    {
        setText("Music...");
    }

    painter.setPen(QColor(90, 105, 115, 200));
    painter.drawText(1, 1, 800, 60, Qt::AlignCenter, text().toUtf8());

    painter.setPen(QPen(_linearGradient, 0));
    painter.drawText(0, 0, 800, 60, Qt::AlignCenter, text().toUtf8());
}

void CLrcLabel::contextMenuEvent(QContextMenuEvent *e)
{
    QMenu menu;
    menu.addAction("hide", this->parent(), SLOT(hide()));
    menu.exec(e->globalPos());
}

void CLrcLabel::OnLrcLabelTimeOut()
{

}
