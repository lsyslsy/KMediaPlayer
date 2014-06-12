#ifndef KMPLAYER_H
#define KMPLAYER_H

#include "mediaplayer.h"
#include <QDialog>
#include <QWidget>

class KMPlayer : public QDialog
{


public:
    explicit KMPlayer(QWidget *parent = 0);
    ~KMPlayer();
    MediaPlayer *kmp;

    //! 写入配置文件.
    void writeSettings();
    //! 读取配置文件.
    void readSettings();
private:


};

#endif // KMPLAYER_H
