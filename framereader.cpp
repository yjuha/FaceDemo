#include "framereader.h"

FrameReader::FrameReader(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(startFrameReader()), this, SLOT(initFrameReader()), Qt::QueuedConnection);
}

FrameReader::get_frame()
{
    QMutexLocker locker(&mutex);

    QImage qframe(frame.data, frame.cols, frame.rows, static_cast<int>(frame.step), QImage::Format_RGB888);

    return qframe;
}

FrameReader::start()
{
    emit startFrameReader();
}

FrameReader::initFrameReader()
{
    // Deletes the existing object it is pointing to (if any), and sets the pointer to new VideoSource object
    cap.reset(new VideoSource(320, 240));

    if ( !cap->isOpened() )
    {
        qDebuq() << "Failed to open webcam, demo not started.";
        return;
    }

    frame.create(cap->get_height(), cap->get_width(), CV_8UC3);
    qDebuq() << "Webcam is alive!";

}
