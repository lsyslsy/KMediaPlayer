#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QWidget>
#include <QtGui>

#include <phonon/audiooutput.h>
#include <phonon/backendcapabilities.h>
#include <phonon/effect.h>
#include <phonon/effectparameter.h>
#include <phonon/effectwidget.h>
#include <phonon/mediaobject.h>
#include <phonon/seekslider.h>
#include <phonon/videowidget.h>
#include <phonon/volumeslider.h>

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = 0);
    ~MediaPlayer();
    //Ui::MediaPlayer *ui;

public slots:
    void openFile();
    //! 播放与暂停
    void playPause();
    //! 重放
    void rewind();
    //! 上一个.
    void backward();
    //! 下一个.
    void forward();
    //! 清除播放列表.
    void clearPlayList();
private slots:
    //! 更新显示时间.
    void updateTime();
private:

    QMenu *fileMenu;
    QPushButton *openButton;
    QPushButton *playButton;                //!< 播放按钮
    QPushButton *rewindButton;              //!< 前一首
    QPushButton *forwardButton;             //!< 下一首

    QLabel * currentTimeLabel;              //!< current time label
    QLabel * totalTimeLabel;                //!< total time label
    QLabel *progressLabel;
    Phonon::VolumeSlider *volumeSlider;           //!< 音量条

    QLabel *info;
    //Phonon::Effect *nextEffect;
    //QDialog *settingsDialog;
    //Ui_settings *ui;
    QAction *km_fullScreenAction;

    QWidget km_videoWindow;
    Phonon::MediaObject km_MediaObject;     //!< 媒体对象.
    Phonon::AudioOutput km_AudioOutput;     //!< Audio 输出.
    Phonon::VideoWidget *km_videoWidget;    //!< 视频窗体.
    Phonon::Path km_audioOutputPath;
    bool km_smallScreen;
    Phonon::SeekSlider *progressSlider;             //!< 视频播放进度条
    QIcon playIcon;         //!< 播放图标.
    QIcon pauseIcon;        //!< 暂停图标.
};

#endif // MEDIAPLAYER_H
