#include <QApplication>

#include <phonon/audiooutput.h>
#include <phonon/backendcapabilities.h>
#include <phonon/effect.h>
#include <phonon/effectparameter.h>
#include <phonon/effectwidget.h>
#include <phonon/mediaobject.h>
#include <phonon/seekslider.h>
#include <phonon/videowidget.h>
#include <phonon/volumeslider.h>
#include "kmplayer.h"
#include <phonon/videoplayer.h>
#include "mediaplayer.h"


//!主函数
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   KMPlayer player;
    player.show();
//    Phonon::VideoPlayer *player1 =
//             new Phonon::VideoPlayer(Phonon::VideoCategory, player.kmp);
//    player.kmp->ui->verticalLayout->addWidget(player1);
//         player1->play(Phonon::MediaSource("C:\\Users\\Public\\Videos\\Sample Videos\\Wildlife.wmv"));


    return a.exec();
}
