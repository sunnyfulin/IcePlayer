#ifndef CLRCLABEL_H
#define CLRCLABEL_H

#include "icelabel.h"

class CLrcLabel : public CIceLabel
{
    Q_OBJECT
public:
    CLrcLabel(QWidget * parent = 0);
    ~CLrcLabel(){}

public:
    void StartLrcMask(qint64 intervalTime);
    void StopLrcMask();
    void SetTextSize(int size);

protected:
    void paintEvent(QPaintEvent *);
    void contextMenuEvent(QContextMenuEvent * e);

private slots:
    void OnLrcLabelTimeOut();

private:
    QLinearGradient _linearGradient;
    QLinearGradient _maskLinearGradient;
    QFont _lrcFont;
    QTimer * _lrcTimer;
    qreal _lrcMaskWidth;
    qreal _lrcMaskWidthInterval;
    QPoint _offSet;
};

#endif // CLRCLABEL_H
