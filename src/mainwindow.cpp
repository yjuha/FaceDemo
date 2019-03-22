#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create here a FrameReader object and make a thread
    frameReader.moveToThread(&frameReaderThread);
    frameReader.start();

    connect(&frameReader, SIGNAL(frameReady()), this, SLOT(refreshWindows()));
    // obj.start();
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(&labelVideoSource);

    widgetVideoSource.setParent(this);
    widgetVideoSource.setWindowFlags(Qt::Window);
    widgetVideoSource.resize(FrameReader::get_frameSize());
    widgetVideoSource.setWindowTitle("FaceDemo");
    widgetVideoSource.setLayout(layout);
    widgetVideoSource.show();
    widgetVideoSource.move(0, 0);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshWindows()
{
    labelVideoSource.setPixmap(QPixmap::fromImage(frameReader.get_frame()));
}
