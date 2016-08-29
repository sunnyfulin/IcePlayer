#ifndef CICEVOLBUTTON_H
#define CICEVOLBUTTON_H

#include "icebutton.h"

class QSlider;

class CIceVolButton : public CIceButton
{
    Q_OBJECT
public:
    CIceVolButton(QWidget * parent = 0);
    ~CIceVolButton(){}

    int GetVolume() const;

public slots:
    void OnSetVolume(int volume);
    void OnIncreaseVolume();
    void OnDecreaseVolume();

signals:
    void SiVolumeChanged(int volume);

private:
    QSlider * _slider;
};

#endif // CICEVOLBUTTON_H
