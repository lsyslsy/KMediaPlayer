#include "mediaplayer.h"
#include "kmplayer.h"
#include <QtGui>

KMPlayer::KMPlayer(QWidget *parent) :
    QDialog(parent)
{
   kmp = new MediaPlayer(this);
   QVBoxLayout *layout = new QVBoxLayout();
   layout->addWidget(kmp);
   layout->setContentsMargins(0, 0, 0, 0);
   setLayout(layout);
   setMinimumSize(100, 100);
  // kmp->ui
}

KMPlayer::~KMPlayer()
{
   // delete ui;
}
