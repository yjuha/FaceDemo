#ifndef FACETRACKER_H_
#define FACETRACKER_H_

#include "opencv2/opencv.hpp"
#include "opencv2/face.hpp"

class FaceTracker
{
public:
    FaceTracker() {}
    ~FaceTracker() {}

    bool init();
private:
    cv::CascadeClassifier facecascade;

};

#endif
