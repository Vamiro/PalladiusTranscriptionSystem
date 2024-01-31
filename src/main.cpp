#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("Fusion");
    a.setWindowIcon(QIcon(":/Icon.ico"));
    MainWindow w;
    w.setWindowTitle("Palladius Transcription System");
    w.show();
    return a.exec();
}
