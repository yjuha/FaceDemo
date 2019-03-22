#ifndef FRAMEREADER_H
#define FRAMEREADER_H

#include "videosource.h"
#include <QObject>
#include <QScopedPointer>
#include <QMutex>

class FrameReader : public QObject
{
    Q_OBJECT
public:
    explicit FrameReader(QObject *parent = 0);

    const QImage get_frame();
    void start();

signals:
    startFrameReader();
    frameReady();

public slots:
    initFrameReader();

private:
    QMutex mutex;
    QScopedPointer<VideoSource> cap;

    // Shared data (protected by mutex)
    cv::Mat frame;
};

#endif // FRAMEREADER_H
