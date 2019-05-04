#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "framereader.h"
#include <QMainWindow>
#include <QLabel>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void refreshWindows();

private:
    Ui::MainWindow *ui;

    QWidget widgetVideoSource;
    QLabel labelVideoSource;
    QLabel labelVideoSource2;

    FrameReader frameReader;
    QThread frameReaderThread;
};

#endif // MAINWINDOW_H
