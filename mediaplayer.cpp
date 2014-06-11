

#include "mediaplayer.h"
#include "ui_mediaplayer.h"


//! Construct function.
MediaPlayer::MediaPlayer(QWidget *parent) :
    QWidget(parent),km_AudioOutput(Phonon::VideoCategory, this),
    km_videoWidget(new Phonon::VideoWidget(this))
   // ui(new Ui::MediaPlayer)
{
  //  ui->setupUi(this);

   // ui->playButton->setIcon(playIcon);
    //
    QHBoxLayout *hlayout1 = new QHBoxLayout;
    km_videoWidget->setFixedSize(480,204);
    hlayout1->addWidget(km_videoWidget);

    QHBoxLayout *hlayout2 = new QHBoxLayout;
    hlayout2->addStretch();
    progressSlider = new Phonon::SeekSlider;
    progressSlider->setMediaObject(&km_MediaObject);
    hlayout2->addWidget(progressSlider);
    hlayout2->addStretch();


    QHBoxLayout *hlayout3 = new QHBoxLayout;
    openButton = new QPushButton(this);
    openButton->setIcon(style()->standardIcon(QStyle::SP_DirOpenIcon));


    playButton = new QPushButton(this);
    playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
    pauseIcon = style()->standardIcon(QStyle::SP_MediaPause);
    playButton->setIcon(playIcon);

    rewindButton = new QPushButton(this);
    rewindButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipBackward));

    forwardButton = new QPushButton(this);
    forwardButton->setIcon(style()->standardIcon(QStyle::SP_MediaSkipForward));
    forwardButton->setEnabled(false);

    volumeSlider = new Phonon::VolumeSlider(&km_AudioOutput);

    //添加按钮
    hlayout3->addWidget(openButton);
    hlayout3->addStretch();
    hlayout3->addWidget(rewindButton);
    hlayout3->addWidget(playButton);
    hlayout3->addWidget(forwardButton);
    hlayout3->addStretch();
    hlayout3->addWidget(volumeSlider);
    hlayout3->setAlignment(playButton,Qt::AlignHCenter);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addLayout(hlayout1);
    mainlayout->addLayout(hlayout2);
    mainlayout->addLayout(hlayout3);

    setLayout(mainlayout);
    setFixedSize(480,272);


    //信号与槽
   connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
   connect(playButton, SIGNAL(clicked()), this, SLOT(playPause()));
   // connect(forwardButton, SIGNAL(clicked()), this, SLOT(forward()));
    Phonon::createPath(&km_MediaObject, km_videoWidget);
    km_audioOutputPath = Phonon::createPath(&km_MediaObject, &km_AudioOutput);

}

MediaPlayer::~MediaPlayer()
{
    //delete ui;
}

//! Oen Media File.
/*!
  打开窗口，并播放视频.
*/
void MediaPlayer::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, QString(),
                                                    QDesktopServices::storageLocation(QDesktopServices::MusicLocation));

    km_MediaObject.setCurrentSource(Phonon::MediaSource(fileName));
    km_MediaObject.play();
}

void MediaPlayer::playPause()
{
    if (km_MediaObject.state() == Phonon::PlayingState)
    {
        km_MediaObject.pause();
        playButton->setIcon(pauseIcon);
    }
    else {
        if (km_MediaObject.currentTime() == km_MediaObject.totalTime())
            km_MediaObject.seek(0);
        km_MediaObject.play();
        playButton->setIcon(playIcon);
    }
}


/*void MediaPlayer::initVideoWindow()
{
    QVBoxLayout *videoLayout = new QVBoxLayout();
    videoLayout->addWidget(m_videoWidget);
    videoLayout->setContentsMargins(0, 0, 0, 0);
    m_videoWindow.setLayout(videoLayout);
    m_videoWindow.setMinimumSize(100, 100);
}*/
//////查询 视频格式是否受支持
