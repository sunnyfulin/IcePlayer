QT       += core gui widgets multimedia

TARGET = IcePlayer
TEMPLATE = app

DESTDIR += $$PWD/bin
MOC_DIR += $$PWD/moc
OBJECTS_DIR += $$PWD/obj

include($$PWD/src/src.pri)

RESOURCES += resource.qrc \
    skin.qrc
