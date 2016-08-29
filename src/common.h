#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QList>

//枚举播放模式
enum PlayMode
{
    SINGAL,
    LISTCIRCLE,
    SINGALCIRCLE,
    RANDOM
};

//网络音乐信息，专辑图片，歌词获取状态
enum NetWorkInfo
{
    RECEIVE_INFO,
    RECEIVE_LINK,
    RECEIVE_PIC,
    RECEIVE_LRC
};

struct CSongBasicInfo
{
    QString _songID;
    QString _songName;
    QString _encryptedSongID;
    int _hasMv;
    int _artist;
    QString _artistName;
};

struct CAlbumInfo
{
    QString _albumID;
    QString _albumName;
    QString _artistName;
    QString _artistPic;
};

struct CSongInfo
{
    QString _order;
    QString _errorCode;
    QList<CSongBasicInfo *> _songResults;
    QList<CAlbumInfo *> _albumInfos;
};

struct CSongList
{
    QString _queryID;
    QString _songID;
    QString _songName;
    QString _artistID;
    QString _artistName;
    QString _albumID;
    QString _songPicSmall;
    QString _songPicBig;
    QString _songPicRadio;
    QString _lrcLick;
    QString _version;
    QString _copytype;
    QString _time;
    QString _linkCode;
    QString _songLink;
    QString _format;
    QString _rate;
    QString _size;
    QString _relateStatus;
    QString _resourceType;
};

struct CSongData
{
    QString _xcode;
    QList<CSongList *> _songLists;
};

struct CSongLink
{
    QString _errorCode;
    CSongData _songData;
};
#endif // COMMON_H
