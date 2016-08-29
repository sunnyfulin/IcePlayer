#ifndef CICELABEL_H
#define CICELABEL_H

#include <QLabel>
#include <QTimer>

class CIceLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CIceLabel(const QString & text, QWidget *parent=0);
    ~CIceLabel();

    void SetShownText(const QString &context, int ms);
    void SetStopRolling();

private slots:
    void OnTimeOut();

private:
    QString _context;
    QTimer * _timer;
    int _ms;
    int _pos;
};

#endif // CICELABEL_H
