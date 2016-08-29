#include "icebutton.h"

#include <QMouseEvent>

CIceButton::CIceButton(QWidget *parent) : QPushButton(parent)
{
    setFlat(true);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");
}

void CIceButton::SetButtonIcons(const QIcon &normal, const QIcon &pressed)
{
    _normalIcon = normal;
    _pressedIcon = pressed;
    setIcon(_normalIcon);
}

void CIceButton::mousePressEvent(QMouseEvent *event)
{
    setIcon(_pressedIcon);
    QPushButton::mousePressEvent(event);
}

void CIceButton::mouseReleaseEvent(QMouseEvent *event)
{
    setIcon(_normalIcon);
    QPushButton::mouseReleaseEvent(event);
}
