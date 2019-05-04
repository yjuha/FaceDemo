#include "framereader.h"
#include <QDebug>
#include <QtGlobal>
#include <QMutexLocker>

FrameReader::FrameReader(QObject *parent) : QObject(parent), frameWidth(320), frameHeight(240)
{
    connect(this, SIGNAL(signalInitFrameReader()), this, SLOT(initFrameReader()), Qt::QueuedConnection);
    connect(this, SIGNAL(signalReadFrame()), this, SLOT(readFrame()), Qt::QueuedConnection);
}

QSize FrameReader::get_frameSize()
{
    QSize size;

    size.setWidth(320);
    size.setHeight(240);

    return size;
}

const QImage FrameReader::get_frame()
{
    QMutexLocker locker(&mutex);

    QImage qframe(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888);

    return qframe;
}

void FrameReader::set_frame(const cv::Mat& data)
{
    QMutexLocker locker(&mutex);

    data.copyTo(frame);

}

void FrameReader::start()
{
    emit signalInitFrameReader();
}

void FrameReader::initFrameReader()
{
    // Deletes the existing object it is pointing to (if any), and sets the pointer to new VideoSource object
    cap.reset(new VideoSource(frameWidth, frameHeight));
    tracker.reset(new FaceTracker());

    if ( !cap->isOpened() )
    {
        qDebug() << "Failed to open webcam, demo not started.";
        return;
    }

    frame.create(cap->get_height(), cap->get_width(), CV_8UC3);
    qDebug() << "Webcam is alive!";
    tracker->init();

    emit signalReadFrame();

}

void FrameReader::readFrame()
{
    qDebug() << "Reading frame";
    cv::Mat frame = cap->queryFrame();
    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

    tracker->track(frame);

    set_frame(frame);
    emit signalFrameReady();
    emit signalReadFrame();
}
