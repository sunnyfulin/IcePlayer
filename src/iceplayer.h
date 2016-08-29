#ifndef CICEPLAYER_H
#define CICEPLAYER_H

#include <QWidget>
#include <QMediaPlayer>

class QMenu;
class QLabel;
class QSlider;
class QAction;
class QActionGroup;
class QTableWidget;
class QMediaPlaylist;

class CIceLabel;
class CIceButton;
class CAboutFrame;
class CIceVolButton;

class CIcePlayer : public QWidget
{
    Q_OBJECT
public:
    explicit CIcePlayer(QWidget *parent = 0);
    ~CIcePlayer();

private:
    void InitMainWindow();
    void InitPlayer();
    void InitConnection();
    void InitSubWindow();

    void paintEvent(QPaintEvent * e);
    void dropEvent(QDropEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void OnMminButtonClicked();
    void OnLogoButtonClicked();
    void OnAddButtonClicked();
    void OnPlayButtonClicked();
    void OnLyricButtonClicked();
    void OnModeButtonClicked();
    void OnNextButtonClicked();
    void OnLastButtonClicked();
    void OnPauseButtonClicked();

    void OnUpdatePlayerPositon(qint64 pos);
    void OnUpdatePlayerDuration(qint64 dur);
    void OnUpdatePlayerState(QMediaPlayer::State state);
    void OnUpdatePlayerMetaData();
    void OnSetPlayPosition(int p);
    void OnSetPosition();

    void OnPlaylistClicked(int row, int column);
    void OnShowCustomContextMenu(const QPoint & p);

private:
    bool _isMoveState;
    unsigned _x, _y;
//    ICE_Lrc *iceLrc;
//    QMap<qint64, QString> _lrcMap;

    QStringList _playList;
    QString _playingFile;
    QString _iceDir;

    int _preIndex;
    int _currentIndex;
    int _playMode;

    CIceButton * _minButton;
    CIceButton * _exitButton;
    CIceButton * _addButton;
    CIceButton * _lyricButton;
    CIceButton * _lastButton;
    CIceButton * _nextButton;
    CIceButton * _playButton;
    CIceButton * _pauseButton;
    CIceButton * _modeButton;
    CIceButton * _mminButton;
    CIceButton * _logoButton;
    CIceVolButton * _volButton;

    CIceLabel * _nameLabel;
    QLabel * _musicianLabel;
    QLabel * _albumLabel;
    QLabel * _timeLabel;
    QLabel * _picLabel;

    QSlider * _playSlider;

    QTableWidget * _playlistTable;

    QMediaPlayer * _mediaPlayer;
    QMediaPlaylist * _mediaList;

    QMenu * _contextMenuLess;
    QMenu * _contextMenuMore;
    QMenu * _playModeMenu;

    QActionGroup * _modeActionGroup;
    QAction * _modeSingal;
    QAction * _modeListCircle;
    QAction * _modeSingalCircle;
    QAction * _modeRandom;
    QAction * _addMusic;
    QAction * _addFileDiv;
    QAction * _removeCurr;
    QAction * _removeAll;


//    miniwindow *miniForm;
    CAboutFrame * _aboutFrame;

//    NetWorker *networker;
    QString _songName;
    QString _songArtist;
    QString _songID;
    QString _picUrl;
    QString _lrcUrl;

    int _receiveState;
    int _playPosition;
};

#endif // CICEPLAYER_H
