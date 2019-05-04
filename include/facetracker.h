#ifndef FACETRACKER_H_
#define FACETRACKER_H_

#include "opencv2/opencv.hpp"
#include "opencv2/face.hpp"

struct Config {
    // This part is taken directly from OpenCV's "Using FaceMark API" example
    Config(cv::String s, double d) {
        model_path = s;
        scaleFactor = d;
        face_detector.load(model_path);
    }
    cv::String model_path;
    double scaleFactor;
    cv::CascadeClassifier face_detector;
};

class FaceTracker
{
public:
    FaceTracker() {}
    ~FaceTracker() {}

    bool init();
    bool track(cv::Mat& frame);
private:

    Config* detector_config;
    cv::Ptr<cv::face::FacemarkLBF> facemark;

};

#endif
