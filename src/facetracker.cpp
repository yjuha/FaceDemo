#include "facetracker.h"

#include <QDebug>
#include <QDir>

const QString FACECASCADE("../FaceDemo/haarcascade_frontalface_alt_tree.xml");

bool FaceTracker::init() {

    if ( !facecascade.load(FACECASCADE.toStdString()) ) {
        qDebug() << "Failed to load face detector.";
        return false;
    }

    return true;
} 
