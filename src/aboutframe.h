#ifndef CABOUTFRAME_H
#define CABOUTFRAME_H

#include <QWidget>

class CIceButton;

class CAboutFrame : public QWidget
{
public:
    CAboutFrame(QWidget * parent = 0);
    ~CAboutFrame(){}

private:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    CIceButton * _exitButton;

    bool _isMoveState;

    unsigned _x;   //鼠标点击位置相对该widget左上角的横坐标差值
    unsigned _y;   //鼠标点击位置相对该widget左上角的纵坐标差值
};

#endif // CABOUTFRAME_H
