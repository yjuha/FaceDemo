#ifndef FRAMEREADER_H
#define FRAMEREADER_H

#include "videosource.h"
#include <QObject>
#include <QScopedPointer>
#include <QMutex>
#include <QSize>
#include <QImage>
#include "opencv2/opencv.hpp"

class FrameReader : public QObject
{
    Q_OBJECT
public:
    explicit FrameReader(QObject *parent = 0);

    static QSize get_frameSize();
    const QImage get_frame();
    void set_frame(const cv::Mat& data);
    void start();

signals:
    void signalInitFrameReader();
    void signalReadFrame();
    void signalFrameReady();

public slots:
    void initFrameReader();
    void readFrame();

private:
    QMutex mutex;
    QScopedPointer<VideoSource> cap;

    // Shared data (protected by mutex)
    cv::Mat frame;
    int frameWidth;
    int frameHeight;
};

#endif // FRAMEREADER_H
