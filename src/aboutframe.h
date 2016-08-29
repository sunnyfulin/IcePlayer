#ifndef CABOUTFRAME_H
#define CABOUTFRAME_H

#include <QWidget>

class CIceButton;

class CAboutFrame : public QWidget
{
public:
    CAboutFrame(QWidget * parent = 0);
    ~CAboutFrame(){}

protected:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    bool _isMoveState;

    unsigned _x , _y;   //鼠标点击位置相对该widget左上角的坐标差值
};

#endif // CABOUTFRAME_H
