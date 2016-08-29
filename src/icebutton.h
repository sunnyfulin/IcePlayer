#ifndef CICEBUTTON_H
#define CICEBUTTON_H

#include <QPushButton>
#include <QIcon>

class CIceButton : public QPushButton
{
    Q_OBJECT
public:
    CIceButton(QWidget * parent = 0);
    ~CIceButton(){}

    void SetButtonIcons(const QIcon &normal, const QIcon &pressed);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QIcon _normalIcon;
    QIcon _pressedIcon;
};

#endif // CICEBUTTON_H
