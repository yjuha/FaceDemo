#ifndef VIDEOSOURCE_H
#define VIDEOSOURCE_H

#include "opencv2/opencv.hpp"

class VideoSource
{
public:
    VideoSource(const int width, const int height, const int camIdx = 0);
    int get_width() {return winWidth;}
    int get_height() {return winHeight;}
    bool isOpened();
    cv::Mat queryFrame();
private:
    int winWidth;
    int winHeight;
    cv::VideoCapture cap;

};

#endif // VIDEOSOURCE_H
