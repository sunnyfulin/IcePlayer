#include "icevolbutton.h"

#include <QMenu>
#include <QSlider>
#include <QWidgetAction>
#include <QToolButton>

CIceVolButton::CIceVolButton(QWidget *parent) : CIceButton(parent)
{
    QIcon icon_button(":/pic/volume.png");
    QIcon icon_button_focus(":/pic/volume2.png");
    SetButtonIcons(icon_button,icon_button_focus);
    setIconSize(QSize(25,25));
    setGeometry(QRect(0,0,25,25));

    _slider = new QSlider(Qt::Horizontal, this);
    _slider->setRange(0, 100);
    _slider->setGeometry(QRect(26,0,75,25));
    connect(_slider,&QSlider::valueChanged,this,&CIceVolButton::SiVolumeChanged);

    QWidgetAction * action = new QWidgetAction(this);
    action->setDefaultWidget(_slider);

    QMenu * menu = new QMenu(this);
    menu->addAction(action);

    setMenu(menu);
}

void CIceVolButton::OnSetVolume(int volume)
{
    _slider->setValue(volume);
}

int CIceVolButton::GetVolume() const
{
    return _slider->value();
}

void CIceVolButton::OnIncreaseVolume()
{
    _slider->triggerAction(QSlider::SliderPageStepAdd);
}

void CIceVolButton::OnDecreaseVolume()
{
    _slider->triggerAction(QSlider::SliderPageStepSub);
}
