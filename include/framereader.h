#ifndef FRAMEREADER_H
#define FRAMEREADER_H

#include "videosource.h"
#include <QObject>
#include <QScopedPointer>
#include <QMutex>
#include <QSize>
#include <QImage>

class FrameReader : public QObject
{
    Q_OBJECT
public:
    explicit FrameReader(QObject *parent = 0);

    static QSize get_frameSize();
    const QImage get_frame();
    void start();

signals:
    void startFrameReader();
    void frameReady();

public slots:
    void initFrameReader();

private:
    QMutex mutex;
    QScopedPointer<VideoSource> cap;

    // Shared data (protected by mutex)
    cv::Mat frame;
    int frameWidth;
    int frameHeight;
};

#endif // FRAMEREADER_H
