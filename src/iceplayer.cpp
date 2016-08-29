#include "iceplayer.h"
#include "icelabel.h"
#include "icebutton.h"
#include "icevolbutton.h"
#include "common.h"
#include "aboutframe.h"

#include <QFrame>
#include <QLabel>
#include <QPixmap>
#include <QSlider>
#include <QPalette>
#include <QPainter>
#include <QMouseEvent>
#include <QHeaderView>
#include <QTableWidget>
#include <QMediaPlaylist>
#include <QMediaPlaylist>
#include <QDragEnterEvent>

CIcePlayer::CIcePlayer(QWidget *parent) : QWidget(parent) , _isMoveState(false)
{
    InitMainWindow();
    InitPlayer();
    InitConnection();
    InitSubWindow();
}

CIcePlayer::~CIcePlayer()
{
    delete _aboutFrame;
    _aboutFrame = NULL;
}

void CIcePlayer::InitMainWindow()
{
    setFixedSize(400,600);
    setAcceptDrops(true);
    setWindowOpacity(0.9);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    _picLabel = new QLabel(this);
    _picLabel->setScaledContents(true);
    _picLabel->setPixmap(QPixmap(":/pic/default_album.jpg"));
    _picLabel->setGeometry(QRect(40,45,100,100));

    QPalette fontPalette;
    fontPalette.setColor(QPalette::WindowText,QColor(1,149,255));

    _nameLabel = new CIceLabel("Name",this);
    _nameLabel->setGeometry(QRect(150,55,220,20));
    _nameLabel->setPalette(fontPalette);
    _nameLabel->setFont(QFont(QStringLiteral("微软雅黑"),12));

    _musicianLabel = new QLabel("Musician",this);
    _musicianLabel->setGeometry(QRect(150,85,220,15));
    _musicianLabel->setPalette(fontPalette);
    _musicianLabel->setFont(QFont(QStringLiteral("微软雅黑"),9));

    _albumLabel = new QLabel("Album",this);
    _albumLabel->setGeometry(QRect(150,115,220,15));
    _albumLabel->setPalette(fontPalette);
    _albumLabel->setFont(QFont(QStringLiteral("微软雅黑"),9));

    _playSlider = new QSlider(Qt::Horizontal,this);
    _playSlider->setGeometry(QRect(40,150,290,20));
    _playSlider->setFont(QFont(QStringLiteral("微软雅黑"),9));

    QPalette timePalette;
    timePalette.setColor(QPalette::WindowText, QColor(106, 182, 240));
    _timeLabel = new QLabel("00:00",this);
    _timeLabel->setGeometry(QRect(340,150,51,16));
    _timeLabel->setPalette(timePalette);

    _addButton = new CIceButton(this);
    _addButton->setGeometry(QRect(40, 190, 31, 31));
    _addButton->setIconSize(QSize(25,25));
    QIcon icon_add(":/pic/addSongButton.png");
    QIcon icon_add_press(":/pic/addSongButton2.png");
    _addButton->SetButtonIcons(icon_add,icon_add_press);

    _modeButton = new CIceButton(this);
    _modeButton->setGeometry(QRect(290, 190, 31, 31));
    _modeButton->setIconSize(QSize(25,25));
    QIcon icon_mode(":/pic/playMode.png");
    QIcon icon_mode_press(":/pic/playMode2.png");
    _modeButton->SetButtonIcons(icon_mode,icon_mode_press);

    _lastButton = new CIceButton(this);
    _lastButton->setGeometry(QRect(120, 185, 41, 41));
    _lastButton->setIconSize(QSize(40,40));
    QIcon icon_last(":/pic/lastSong.png");
    QIcon icon_last_press(":/pic/lastSong2.png");
    _lastButton->SetButtonIcons(icon_last,icon_last_press);

    _nextButton = new CIceButton(this);
    _nextButton->setGeometry(QRect(240, 185, 41, 41));
    _nextButton->setIconSize(QSize(40,40));
    QIcon icon_next(":/pic/nextSong.png");
    QIcon icon_next_press(":/pic/nextSong2.png");
    _nextButton->SetButtonIcons(icon_next,icon_next_press);

    _lyricButton = new CIceButton(this);
    _lyricButton->setGeometry(QRect(80, 190, 31, 31));
    _lyricButton->setIconSize(QSize(25,25));
    QIcon icon_lyric(":/pic/lrcButton.png");
    QIcon icon_lyric_press(":/pic/lrcButton2.png");
    _lyricButton->SetButtonIcons(icon_lyric,icon_lyric_press);

    _playButton = new CIceButton(this);
    _playButton->setGeometry(QRect(170, 175, 61, 61));
    _playButton->setIconSize(QSize(60,60));
    QIcon icon_play(":/pic/playButton.png");
    QIcon icon_play_press(":/pic/playButton2.png");
    _playButton->SetButtonIcons(icon_play,icon_play_press);

    _pauseButton = new CIceButton(this);
    _pauseButton->setGeometry(QRect(170, 175, 61, 61));
    _pauseButton->setVisible(false);
    _pauseButton->setIconSize(QSize(60,60));
    QIcon icon_pause(":/pic/pauseButton.png");
    QIcon icon_pause_press(":/pic/pauseButton2.png");
    _pauseButton->SetButtonIcons(icon_pause,icon_pause_press);

    _volButton = new CIceVolButton(this);
    _volButton->setGeometry(QRect(333, 193, 31, 31));
    _volButton->OnSetVolume(100);

    _mminButton = new CIceButton(this);
    _mminButton->setGeometry(QRect(307, 3, 29, 31));
    _mminButton->setIconSize(QSize(20,20));
    QIcon icon_mmin(":/pic/miniModeButton.png");
    QIcon icon_mmin_press(":/pic/miniModeButton2.png");
    _mminButton->SetButtonIcons(icon_mmin,icon_mmin_press);

    _minButton = new CIceButton(this);

    _minButton->setGeometry(QRect(337, 3, 29, 31));
    _minButton->setIconSize(QSize(20,20));
    QIcon icon_min(":/pic/minButton.png");
    QIcon icon_min_press(":/pic/minButton2.png");
    _minButton->SetButtonIcons(icon_min,icon_min_press);

    _exitButton = new CIceButton(this);
    _exitButton->setGeometry(QRect(364, 3, 29, 31));
    _exitButton->setIconSize(QSize(20,20));
    QIcon icon_exit(":/pic/closeButton.png");
    QIcon icon_exit_press(":/pic/closeButton2.png");
    _exitButton->SetButtonIcons(icon_exit,icon_exit_press);

    _logoButton = new CIceButton(this);
    _logoButton->setGeometry(QRect(8, 3, 120, 48));
    _logoButton->setIconSize(QSize(120,48));
    QIcon icon_logo(":/pic/logoButton.png");
    QIcon icon_logo_press(":/pic/logoButton2.png");
    _logoButton->SetButtonIcons(icon_logo,icon_logo_press);

    _playlistTable = new QTableWidget(this);
    _playlistTable->setColumnCount(2);
    _playlistTable->setColumnWidth(0,300);
    _playlistTable->setColumnWidth(1,45);
    _playlistTable->setGeometry(QRect(25,240,350,320));
    _playlistTable->horizontalHeader()->setVisible(false);
    _playlistTable->verticalHeader()->setVisible(false);

    _playlistTable->setShowGrid(false);
    _playlistTable->setFrameShape(QFrame::NoFrame);
    _playlistTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _playlistTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    _playlistTable->setSelectionMode(QAbstractItemView::SingleSelection);
    _playlistTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    _playlistTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    _playlistTable->setContextMenuPolicy(Qt::CustomContextMenu);

    QPalette pal;
    pal.setBrush(QPalette::Base, QBrush(QColor(255, 255, 255)));
    _playlistTable->setPalette(pal);
    _playlistTable->setAcceptDrops(true);
}

void CIcePlayer::InitPlayer()
{
    _mediaPlayer = new QMediaPlayer(this);
    _mediaList = new QMediaPlaylist(this);
    _mediaPlayer->setPlaylist(_mediaList);

    _playMode = PlayMode::SINGAL;
    _preIndex = -1;
    _currentIndex = 0;

    _mediaList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}

void CIcePlayer::InitConnection()
{
    connect(_exitButton,&CIceButton::clicked,this,&CIcePlayer::close);
    connect(_minButton,&CIceButton::clicked,this,&CIcePlayer::showMinimized);
    connect(_mminButton,&CIceButton::clicked,this,&CIcePlayer::OnMminButtonClicked);
    connect(_logoButton,&CIceButton::clicked,this,&CIcePlayer::OnLogoButtonClicked);
    connect(_addButton,&CIceButton::clicked,this,&CIcePlayer::OnAddButtonClicked);
    connect(_playButton,&CIceButton::clicked,this,&CIcePlayer::OnPlayButtonClicked);
    connect(_lyricButton,&CIceButton::clicked,this,&CIcePlayer::OnLyricButtonClicked);
    connect(_modeButton,&CIceButton::clicked,this,&CIcePlayer::OnModeButtonClicked);
    connect(_nextButton,&CIceButton::clicked,this,&CIcePlayer::OnNextButtonClicked);
    connect(_lastButton,&CIceButton::clicked,this,&CIcePlayer::OnLastButtonClicked);
    connect(_pauseButton,&CIceButton::clicked,this,&CIcePlayer::OnPauseButtonClicked);

    connect(_mediaPlayer,&QMediaPlayer::positionChanged,this,&CIcePlayer::OnUpdatePlayerPositon);
    connect(_mediaPlayer,&QMediaPlayer::durationChanged,this,&CIcePlayer::OnUpdatePlayerDuration);
    connect(_mediaPlayer,&QMediaPlayer::stateChanged,this,&CIcePlayer::OnUpdatePlayerState);
    connect(_mediaPlayer,SIGNAL(metaDataChanged()),this,SLOT(OnUpdatePlayerMetaData()));

    connect(_volButton,&CIceVolButton::SiVolumeChanged,_mediaPlayer,&QMediaPlayer::setVolume);
    connect(_playSlider,&QSlider::sliderMoved,this,&CIcePlayer::OnSetPlayPosition);
    connect(_playSlider,&QSlider::sliderReleased,this,&CIcePlayer::OnSetPosition);

    connect(_playlistTable,&QTableWidget::cellDoubleClicked,this,&CIcePlayer::OnPlaylistClicked);
    connect(_playlistTable,&QTableWidget::customContextMenuRequested,this,&CIcePlayer::OnShowCustomContextMenu);
}

void CIcePlayer::InitSubWindow()
{
    _aboutFrame = new CAboutFrame;
}

void CIcePlayer::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(0, 0 , QPixmap(":/pic/background.png"));
}

void CIcePlayer::dropEvent(QDropEvent *event)
{

}

void CIcePlayer::dragEnterEvent(QDragEnterEvent *event)
{

}

void CIcePlayer::mousePressEvent(QMouseEvent * e)
{
    if(e->button() != Qt::LeftButton && !_isMoveState)
        return;

    _isMoveState = true;

    _x = e->pos().x();
    _y = e->pos().y();
}

void CIcePlayer::mouseMoveEvent(QMouseEvent * e)
{
    if(e->button() != Qt::LeftButton && !_isMoveState)
        return;

    QPoint curPos = e->globalPos();
    move(curPos.x() - _x ,curPos.y() - _y);
}

void CIcePlayer::mouseReleaseEvent(QMouseEvent * e)
{
    if(e->button() != Qt::LeftButton)
        return;

    _isMoveState = false;
}

void CIcePlayer::OnMminButtonClicked()
{

}

void CIcePlayer::OnLogoButtonClicked()
{
    _aboutFrame->show();
}

void CIcePlayer::OnAddButtonClicked()
{

}

void CIcePlayer::OnPlayButtonClicked()
{

}

void CIcePlayer::OnLyricButtonClicked()
{

}

void CIcePlayer::OnModeButtonClicked()
{

}

void CIcePlayer::OnNextButtonClicked()
{

}

void CIcePlayer::OnLastButtonClicked()
{

}

void CIcePlayer::OnPauseButtonClicked()
{

}

void CIcePlayer::OnUpdatePlayerPositon(qint64 pos)
{

}

void CIcePlayer::OnUpdatePlayerDuration(qint64 dur)
{

}

void CIcePlayer::OnUpdatePlayerState(QMediaPlayer::State state)
{

}

void CIcePlayer::OnUpdatePlayerMetaData()
{

}

void CIcePlayer::OnSetPlayPosition(int p)
{

}

void CIcePlayer::OnSetPosition()
{

}

void CIcePlayer::OnPlaylistClicked(int row, int column)
{

}

void CIcePlayer::OnShowCustomContextMenu(const QPoint &p)
{

}
