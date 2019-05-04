TEMPLATE = app
TARGET = FaceDemo

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/local/include/opencv4

LIBS += -L/usr/local/lib \
        -lopencv_core \
        -lopencv_imgcodecs \
        -lopencv_highgui \
        -lopencv_imgproc \
        -lopencv_videoio \
        -lopencv_ml \
        -lopencv_video \
        -lopencv_features2d \
        -lopencv_calib3d \
        -lopencv_objdetect \
        -lopencv_flann \
        -lopencv_face

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/framereader.cpp \
    src/videosource.cpp \
    src/facetracker.cpp

FORMS += \
    forms/src/mainwindow.ui

HEADERS += \
    include/mainwindow.h \
    include/framereader.h \
    include/videosource.h \
    include/facetracker.h

INCLUDEPATH += ./include

DISTFILES += \
    haarcascade_frontalface_alt_tree.xml \
    lbfmodel.yaml
