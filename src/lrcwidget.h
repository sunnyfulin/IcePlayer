#ifndef CLRCWIDGET_H
#define CLRCWIDGET_H

#include <QWidget>

class CLrcLabel;

class CLrcWidget : public QWidget
{
    Q_OBJECT
public:
    CLrcWidget(QWidget *parent = 0);
    ~CLrcWidget(){}

public:
    void StartLrcMask(qint64 intervalTime);
    void StopLrcMask();

    QString GetText() const;
    void SetText(const QString & t);

private:
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent * e);
    void mouseMoveEvent(QMouseEvent * e);
    void mouseReleaseEvent(QMouseEvent * e);

private:
    CLrcLabel * _lrcLabel;

    bool _isMoveState;
    unsigned _x,_y;
};

#endif // CLRCWIDGET_H
