#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QList>

enum PlayMode
{
    SINGAL,
    LISTCIRCLE,
    SINGALCIRCLE,
    RANDOM
};

enum NetWorkInfo
{
    RECEIVE_INFO,
    RECEIVE_LINK,
    RECEIVE_PIC,
    RECEIVE_LRC
};

struct CSongBasicInfo
{
    QString songID;
    QString songName;
    QString encryptedSongID;
    int hasMv;
    int artist;
    QString artistName;
};

struct CAlbumInfo
{
    QString albumID;
    QString albumName;
    QString artistName;
    QString artistPic;
};

struct CSongInfo
{
    QString order;
    QString errorCode;
    QList<CSongBasicInfo *> songResults;
    QList<CAlbumInfo *> albumInfos;
};

struct CSongList
{
    QString queryID;
    QString songID;
    QString songName;
    QString artistID;
    QString artistName;
    QString albumID;
    QString songPicSmall;
    QString songPicBig;
    QString songPicRadio;
    QString lrcLick;
    QString version;
    QString copytype;
    QString time;
    QString linkCode;
    QString songLink;
    QString format;
    QString rate;
    QString size;
    QString relateStatus;
    QString resourceType;
};

struct CSongData
{
    QString xcode;
    QList<CSongList *> songLists;
};

struct CSongLink
{
    QString errorCode;
    CSongData songData;
};
#endif // COMMON_H
