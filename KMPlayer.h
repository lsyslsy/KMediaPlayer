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
private:


};

#endif // KMPLAYER_H
