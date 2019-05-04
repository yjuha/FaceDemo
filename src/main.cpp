#include "mainwindow.h"

#include <QApplication>
#include <QMessageLogContext>
#include <QtGlobal>
#include <QDebug>
#include <cstdio>

// message handler for debug messages
void myMessageOutput(QtMsgType, const QMessageLogContext& context, const QString& msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";

    std::fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    qDebug() << "FaceDemo execution started";

    QApplication a(argc, argv);

    MainWindow w;
    //w.show();

    return a.exec();
}

