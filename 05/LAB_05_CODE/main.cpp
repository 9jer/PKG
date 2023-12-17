#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qApp->setStyle(QStyleFactory::create("Fusion"));
    w.resize(700,700);
    w.show();
    return a.exec();
}
