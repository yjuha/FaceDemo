#include "framereader.h"
#include <QDebug>

FrameReader::FrameReader(QObject *parent) : QObject(parent), frameWidth(320), frameHeight(240)
{
    connect(this, SIGNAL(startFrameReader()), this, SLOT(initFrameReader()), Qt::QueuedConnection);
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

void FrameReader::start()
{
    emit startFrameReader();
}

void FrameReader::initFrameReader()
{
    // Deletes the existing object it is pointing to (if any), and sets the pointer to new VideoSource object
    cap.reset(new VideoSource(frameWidth, frameHeight));

    if ( !cap->isOpened() )
    {
        //qDebuq() << "Failed to open webcam, demo not started.";
        return;
    }

    frame.create(cap->get_height(), cap->get_width(), CV_8UC3);
    //qDebuq() << "Webcam is alive!";

}
