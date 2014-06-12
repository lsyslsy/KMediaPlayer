#include "mediaplayer.h"
#include "kmplayer.h"
#include <QtGui>

KMPlayer::KMPlayer(QWidget *parent) :
    QDialog(parent)
{
   kmp = new MediaPlayer(this);
   QVBoxLayout *layout = new QVBoxLayout();
   layout->addWidget(kmp);
   layout->setMargin(0);
   layout->setSpacing(0);

   setLayout(layout);
   setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  // setMinimumSize(100, 100);
  // kmp->ui
}

KMPlayer::~KMPlayer()
{
   // delete ui;
}


/*!
  write settings to ini file.
*/
void KMPlayer::writeSettings()
{
   // delete ui;
}

/*!
  read settings from ini file.
*/
void KMPlayer::readSettings()
{
   // delete ui;
}
