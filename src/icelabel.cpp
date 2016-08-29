#include "icelabel.h"

CIceLabel::CIceLabel(const QString &text, QWidget *parent) : QLabel(text,parent)
{
    _timer = NULL;
    _ms = 0;
    _context = "";
    _pos = 0;
}

void CIceLabel::SetShownText(const QString &context, int ms)
{
    _context = context;
    _ms = ms;

    if (_ms != 0)
    {
        if (_timer == NULL)
        {
            _timer = new QTimer(this);

            if (_timer)
            {
                connect(_timer, SIGNAL(timeout()), this, SLOT(OnTimeOut()));
                _timer->start(_ms);
            }
        }
    }
}

void CIceLabel::SetStopRolling()
{
    if (_timer)
    {
        if (_timer->isActive())
        {
            _timer->stop();
        }

        delete _timer;
        _timer = NULL;
    }
}

void CIceLabel::OnTimeOut()
{
    if (_pos > _context.count())
    {
        _pos = 0;
    }

    setText(_context.mid(_pos));
    _pos++;
}
