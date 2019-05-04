#include "facetracker.h"

#include <QDebug>
#include <QDir>

//const QString FACECASCADE("../FaceDemo/haarcascade_frontalface_alt_tree.xml");

bool myDetector(cv::InputArray image, cv::OutputArray faces, Config *conf);

bool FaceTracker::init() {

    detector_config = new Config("../FaceDemo/haarcascade_frontalface_alt_tree.xml", 1.4);

    cv::face::FacemarkLBF::Params params;
    facemark = cv::face::FacemarkLBF::create(params);
    facemark->setFaceDetector((cv::face::FN_FaceDetector) myDetector, detector_config);

    facemark->loadModel("../FaceDemo/lbfmodel.yaml");

    return true;
} 

bool myDetector(cv::InputArray image, cv::OutputArray faces, Config *conf) {
    cv::Mat gray;
    if (image.channels() > 1)
        cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);
    else
        gray = image.getMat().clone();
    cv::equalizeHist(gray, gray);
    std::vector<cv::Rect> faces_;
    conf->face_detector.detectMultiScale(gray, faces_, conf->scaleFactor, 2, cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    cv::Mat(faces_).copyTo(faces);
    return true;
}

bool FaceTracker::track(cv::Mat& frame) {
    std::vector<cv::Rect> faces;
    facemark->getFaces(frame, faces);
    for(int j = 0; j < faces.size(); j++){
        cv::rectangle(frame, faces[j], cv::Scalar(255,0,255));
    }

}
