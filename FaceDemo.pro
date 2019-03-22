TEMPLATE = app
TARGET = FaceDemo

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/local/include/opencv

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
        -lopencv_flann

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    framereader.cpp \
    videosource.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    mainwindow.h \
    framereader.h \
    videosource.h
