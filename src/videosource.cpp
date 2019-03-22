#include "videosource.h"

VideoSource::VideoSource(const int width, const int height, const int camIdx) :
    winWidth(width),
    winHeight(height),
    cap(camIdx)
{
}

bool FrameReader::isOpened()
{
    return cap.isOpened();
}

VideoSource::queryFrame()
{
    Mat frame;
    cap >> frame;
    return frame;
}

