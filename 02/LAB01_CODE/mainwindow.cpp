#include "mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QTableWidgetItem>
#include <QImage>
#include <QStringList>
#include <QImageWriter>
#include <QVBoxLayout>
#include <QPushButton>


ImageInfoApp::ImageInfoApp(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Информация об изображениях");
    resize(770, 600);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(5);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "Имя файла" << "Размер" << "Разрешение" << "Глубина цвета" << "Сжатие");
    for (int i = 0; i < 5; i++) {
        tableWidget->setColumnWidth(i, 150);
    }

    QPushButton *openButton = new QPushButton("Выбрать папку", this);
    connect(openButton, &QPushButton::clicked, this, &ImageInfoApp::onSelectFolderClicked);

    QPushButton *clearButton = new QPushButton("Очистить", this);
    connect(clearButton, &QPushButton::clicked, this, &ImageInfoApp::clearTable);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(openButton);
    layout->addWidget(clearButton);
    layout->addWidget(tableWidget);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void ImageInfoApp::clearTable()
{
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
}

void ImageInfoApp::onSelectFolderClicked() {
    QString folderPath = QFileDialog::getExistingDirectory(this, "Выберите папку с изображениями", QDir::homePath());

    if (!folderPath.isEmpty()) {
        processImagesInFolder(folderPath);
    }
}

void ImageInfoApp::processImagesInFolder(const QString& folderPath) {
    QDir folder(folderPath);
    QStringList filters;
    filters << "*.jpg" << "*.gif" << "*.tif" << "*.bmp" << "*.png" << "*.pcx";
    QStringList imageFiles = folder.entryList(filters, QDir::Files);

    tableWidget->clearContents();
    tableWidget->setRowCount(imageFiles.size());

    for (int i = 0; i < imageFiles.size(); i++) {
        QString filePath = folder.absoluteFilePath(imageFiles[i]);
        QImage image(filePath);
        QImageWriter imageWriter(filePath);

        if (!image.isNull()) {
            QTableWidgetItem* fileNameItem = new QTableWidgetItem(imageFiles[i]);
            tableWidget->setItem(i, 0, fileNameItem);

            QString imageSize = QString("%1 x %2").arg(image.width()).arg(image.height());
            QTableWidgetItem* sizeItem = new QTableWidgetItem(imageSize);
            tableWidget->setItem(i, 1, sizeItem);

            double resolutionX = image.dotsPerMeterX() * 0.0254;
            double resolutionY = image.dotsPerMeterY() * 0.0254;
            QString resolution = QString("%1 x %2").arg(resolutionX, 0, 'f', 2).arg(resolutionY, 0, 'f', 2);
            QTableWidgetItem* resolutionItem = new QTableWidgetItem(resolution);
            tableWidget->setItem(i, 2, resolutionItem);

            int depth = image.depth();
            QTableWidgetItem* depthItem = new QTableWidgetItem(QString::number(depth));
            tableWidget->setItem(i, 3, depthItem);

            QString compression = imageTextFormat(image);
            QTableWidgetItem* compressionItem = new QTableWidgetItem(QString::number(imageWriter.compression()));
            tableWidget->setItem(i, 4, compressionItem);
        }
    }
}

QString ImageInfoApp::imageTextFormat(const QImage& image) {
    if (image.format() == QImage::Format_Indexed8) {
        return "Indexed Color";
    } else if (image.format() == QImage::Format_RGB32 || image.format() == QImage::Format_ARGB32) {
        return "RGB Color";
    } else {
        return "Unknown";
    }
}
