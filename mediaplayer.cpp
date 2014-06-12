

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
    km_videoWidget->setFixedSize(480,204);                  // 设置画面大小
    hlayout1->addWidget(km_videoWidget);

    QHBoxLayout *hlayout2 = new QHBoxLayout;

    currentTimeLabel = new QLabel("00:00:00", this);


    progressSlider = new Phonon::SeekSlider;
    progressSlider->setMediaObject(&km_MediaObject);
    progressSlider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    totalTimeLabel = new QLabel("00:00:00", this);
    hlayout2->addWidget(currentTimeLabel);
    hlayout2->addStretch();
    hlayout2->addWidget(progressSlider, 1);
    hlayout2->addStretch();

    hlayout2->addWidget(totalTimeLabel);

    QHBoxLayout *hlayout3 = new QHBoxLayout;
    openButton = new QPushButton(this);
    openButton->setIcon(style()->standardIcon(QStyle::));


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
    mainlayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainlayout);

    setFixedSize(480,272);          // 设置播放器尺寸


    //播放控制
   connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));
   connect(playButton, SIGNAL(clicked()), this, SLOT(playPause()));
   connect(rewindButton, SIGNAL(clicked()), this, SLOT(rewind()));
   connect(forwardButton, SIGNAL(clicked()), this, SLOT(forward()));



   connect(&km_MediaObject, SIGNAL(totalTimeChanged(qint64)), this, SLOT(updateTime()));
   connect(&km_MediaObject, SIGNAL(tick(qint64)), this, SLOT(updateTime()));


    Phonon::createPath(&km_MediaObject, km_videoWidget);
    km_audioOutputPath = Phonon::createPath(&km_MediaObject, &km_AudioOutput);

}

/*!
 * ... text ...
 */
MediaPlayer::~MediaPlayer()
{
    //delete ui;
}


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

/*!
  暂停与播放.
*/
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

//! 更新显示时间.
void MediaPlayer::updateTime()
{
    long len = km_MediaObject.totalTime();
    long pos = km_MediaObject.currentTime();
    QString timeString;
    if (pos || len)
    {
        int sec = pos/1000;
        int min = sec/60;
        int hour = min/60;
        int msec = pos;

        QTime playTime(hour%60, min%60, sec%60, msec%1000);
        sec = len / 1000;
        min = sec / 60;
        hour = min / 60;
        msec = len;

        QTime stopTime(hour%60, min%60, sec%60, msec%1000);
        QString timeFormat = "hh:mm:ss";
        timeString = playTime.toString(timeFormat);
        totalTimeLabel->setText(stopTime.toString(timeFormat));

    }
    currentTimeLabel->setText(timeString);

}

void MediaPlayer::backward()
{

}

void MediaPlayer::forward()
{

}

void MediaPlayer::rewind()
{

}

//! 清除播放列表.
void MediaPlayer::clearPlayList()
{

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
