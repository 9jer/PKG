#include <QApplication>
#include "mainwindow.h"
#include <QStyleFactory>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImageInfoApp mainWindow;
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette p;
    p = qApp->palette();
    p.setColor(QPalette::Window, QColor(53,53,53));
    p.setColor(QPalette::Button, QColor(53,53,53));
    p.setColor(QPalette::Highlight, QColor(142,45,197));
    p.setColor(QPalette::ButtonText, QColor(255,255,255));
    qApp->setPalette(p);

    mainWindow.show();

    return app.exec();
}
