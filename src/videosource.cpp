#include "videosource.h"

VideoSource::VideoSource(const int width, const int height, const int camIdx) :
    winWidth(width),
    winHeight(height),
    cap(camIdx)
{
    cap.open(-1);
}

bool VideoSource::isOpened()
{
    return cap.isOpened();
}

cv::Mat VideoSource::queryFrame()
{
    cv::Mat frame;
    cap >> frame;
    return frame;
}

