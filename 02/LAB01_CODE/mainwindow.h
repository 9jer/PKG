#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>

class ImageInfoApp : public QMainWindow {
    Q_OBJECT

public:
    ImageInfoApp(QWidget* parent = nullptr);

private slots:
    void onSelectFolderClicked();
    void processImagesInFolder(const QString& folderPath);
    void clearTable();
    QString imageTextFormat(const QImage& image);

private:
    QPushButton* selectFolderButton;
    QTableWidget* tableWidget;
};

#endif // MAINWINDOW_H
