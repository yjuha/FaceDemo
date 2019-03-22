#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create here a FrameReader object and make a thread
    connect(&reader, SIGNAL(frameReady()), this, SLOT(refreshWindows()));
    // obj.start();
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(&labelVideoSource);

    widgetVideoSource.setParent(this);
    widgetVideoSource.setWindowFlags(Qt::Window);
    widgetVideoSource.resize(FrameProcesser::frameSize(sourceFilename));
    widgetVideoSource.setWindowTitle("FaceDemo");
    widgetVideoSource.setLayout(layout1);
    widgetVideoSource.show();
    widgetVideoSource.move(0, 0);
}


MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::refreshWindows()
{
    labelVideoSource.setPixmap(QPixmap::fromImage(reader.get_frame()));
}
