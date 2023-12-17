#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"
#include "QDebug"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),scale(10)
{

    ui->setupUi(this);
    qApp->installEventFilter(this);

}

void MainWindow::on_darkPushButton_clicked()
{
    QPalette darkPalette;

    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(!ready_) return;
    QPainter p;
    QPixmap pix(600,600);
    pix.fill(Qt::white);
    p.begin(&pix);

    Xmin = ui->dsb_Xmin->value();
    Ymin = ui->dsb_Ymin->value();
    Xmax = ui->dsb_Xmax->value();
    Ymax = ui->dsb_Ymax->value();


    double step = 0.9/20;
    double stp = 0.9/(2*scale);

    p.setPen(QPen(Qt::magenta,3));
    p.drawRect(QRect(QPoint(pix.width()*(0.5+stp*Xmin),pix.height()*(0.5-stp*Ymax)),QPoint(pix.width()*(0.5+stp*Xmax),pix.height()*(0.5-stp*Ymin))));

    p.setPen(QPen(Qt::black,3));
    p.drawLine(pix.width()*0.05,pix.height()/2,pix.width()*0.95,pix.height()/2);
    p.drawLine(pix.width()/2,pix.height()*0.95,pix.width()/2,pix.height()*0.05);


    for(int i = 0; i < 20;i++)
    {
        p.setPen(QPen(Qt::black,1));
        p.drawLine(pix.width()*(0.05+step*i),pix.height()*0.05,pix.width()*(0.05+step*i),pix.height()*0.95);
        p.drawLine(pix.width()*0.05,pix.height()*(0.05+step*i),pix.width()*0.95,pix.height()*(0.05+step*i));
        p.drawText(pix.width()*(0.04+step*i),pix.height()/1.90,QString::number(scale/10*(i-10)));
        if(i!=10)
            p.drawText(pix.width()/2.10,pix.height()*(0.955-step*i),QString::number(scale/10*(i-10)));

    }

    QVector<QVector<QPair<QPointF,QPointF>>> clipSegments = cutSegments(segments);
    QVector<QPointF> clipPolygon = cutPolygon(polygon); // here error


    p.setPen(QPen(Qt::black,2,Qt::DashLine));
    for(auto segment:segments)
        p.drawLine(pix.width()*(0.5+stp*segment.first.x()),pix.height()*(0.5-stp*segment.first.y()),pix.width()*(0.5+stp*segment.second.x()),pix.height()*(0.5-stp*segment.second.y()));
    for(int i = 1; i<polygon.size();i++)
        p.drawLine(pix.width()*(0.5+stp*polygon[i-1].x()),pix.height()*(0.5-stp*polygon[i-1].y()),pix.width()*(0.5+stp*polygon[i].x()),pix.height()*(0.5-stp*polygon[i].y()));

    p.setPen(QPen(Qt::green,3));
    for(auto otrezok:clipSegments[0])
        p.drawLine(pix.width()*(0.5+stp*otrezok.first.x()),pix.height()*(0.5-stp*otrezok.first.y()),pix.width()*(0.5+stp*otrezok.second.x()),pix.height()*(0.5-stp*otrezok.second.y()));
    p.setPen(QPen(Qt::green,3));
    for(int i = 1; i<clipPolygon.size();i++)
        p.drawLine(pix.width()*(0.5+stp*clipPolygon[i-1].x()),pix.height()*(0.5-stp*clipPolygon[i-1].y()),pix.width()*(0.5+stp*clipPolygon[i].x()),pix.height()*(0.5-stp*clipPolygon[i].y()));


    ui->label->setPixmap(pix);
    p.end();

}
QVector<QVector<QPair<QPointF, QPointF>>> MainWindow::cutSegments(QVector<QPair<QPointF, QPointF>> segments)
{
    QVector<QVector<QPair<QPointF, QPointF>>> clipSegments(2);

    for (int i = 0; i < segments.size(); i++)
    {
        QPointF P1 = segments[i].first;
        QPointF P2 = segments[i].second;

        QVector<QPair<QPointF, QPointF>> clippedSegment = cohenSutherlandClip(P1, P2);

        if (!clippedSegment.isEmpty())
        {
            if (clippedSegment.size() == 1)
            {
                clipSegments[0].push_back(clippedSegment[0]);
            }
            else
            {
                clipSegments[1].push_back(clippedSegment[1]);
            }
        }
    }

    return clipSegments;
}
QVector<QPair<QPointF, QPointF>> MainWindow::cohenSutherlandClip(QPointF P1, QPointF P2)
{
    QVector<QPair<QPointF, QPointF>> clippedSegment;

    unsigned int C1 = 0;
    if (P1.x() < Xmin) C1 += 1;
    if (P1.x() > Xmax) C1 += 2;
    if (P1.y() < Ymin) C1 += 4;
    if (P1.y() > Ymax) C1 += 8;

    unsigned int C2 = 0;
    if (P2.x() < Xmin) C2 += 1;
    if (P2.x() > Xmax) C2 += 2;
    if (P2.y() < Ymin) C2 += 4;
    if (P2.y() > Ymax) C2 += 8;

    if ((C1 == 0) && (C2 == 0))
    {
        // Отрезок полностью видим
        clippedSegment.push_back(qMakePair(P1, P2));
    }
    else if ((C1 & C2) != 0)
    {
        // Отрезок полностью видим вне окна
        // Не добавляем его в результат
    }
    else
    {
        // Отрезок пересекает границы окна, применяем алгоритм Коэна-Сазерленда
        QPointF intersectionPoint;

        while (true)
        {
            if ((C1 == 0) && (C2 == 0))
            {
                clippedSegment.push_back(qMakePair(P1, P2));
                break;
            }

            if ((C1 & C2) != 0)
            {
                break;
            }

            if (C1 != 0)
            {
                if (C1 & 1)
                {
                    intersectionPoint = QPointF(Xmin, P1.y() + (Xmin - P1.x()) * (P2.y() - P1.y()) / (P2.x() - P1.x()));
                }
                else if (C1 & 2)
                {
                    intersectionPoint = QPointF(Xmax, P1.y() + (Xmax - P1.x()) * (P2.y() - P1.y()) / (P2.x() - P1.x()));
                }
                else if (C1 & 4)
                {
                    intersectionPoint = QPointF(P1.x() + (Ymin - P1.y()) * (P2.x() - P1.x()) / (P2.y() - P1.y()), Ymin);
                }
                else if (C1 & 8)
                {
                    intersectionPoint = QPointF(P1.x() + (Ymax - P1.y()) * (P2.x() - P1.x()) / (P2.y() - P1.y()), Ymax);
                }

                P1 = intersectionPoint;
                C1 = 0;
                if (P1.x() < Xmin) C1 += 1;
                if (P1.x() > Xmax) C1 += 2;
                if (P1.y() < Ymin) C1 += 4;
                if (P1.y() > Ymax) C1 += 8;
            }
            else if (C2 != 0)
            {
                if (C2 & 1)
                {
                    intersectionPoint = QPointF(Xmin, P2.y() + (Xmin - P2.x()) * (P1.y() - P2.y()) / (P1.x() - P2.x()));
                }
                else if (C2 & 2)
                {
                    intersectionPoint = QPointF(Xmax, P2.y() + (Xmax - P2.x()) * (P1.y() - P2.y()) / (P1.x() - P2.x()));
                }
                else if (C2 & 4)
                {
                    intersectionPoint = QPointF(P2.x() + (Ymin - P2.y()) * (P1.x() - P2.x()) / (P1.y() - P2.y()), Ymin);
                }
                else if (C2 & 8)
                {
                    intersectionPoint = QPointF(P2.x() + (Ymax - P2.y()) * (P1.x() - P2.x()) / (P1.y() - P2.y()), Ymax);
                }

                P2 = intersectionPoint;
                C2 = 0;
                if (P2.x() < Xmin) C2 += 1;
                if (P2.x() > Xmax) C2 += 2;
                if (P2.y() < Ymin) C2 += 4;
                if (P2.y() > Ymax) C2 += 8;
            }
        }
    }

    return clippedSegment;
}


int MainWindow::getCode(QPointF point)
{
    double x = point.x();
    double y = point.y();

    int code = 0;

    if(x < Xmin)
        code +=1;
    if(x>Xmax)
        code +=2;
    if(y<Ymin)
        code +=4;
    if(y>Ymax)
        code +=8;
    return code;
}


QVector<QPointF> MainWindow::cutPolygon(QVector<QPointF> polygon)
{
    QVector<QPointF> outputList = polygon;

    int borders[]  = {1,2,4,8};

    for(int i = 0; i < 4;i++)
    {
        QVector<QPointF> inputList = outputList;
        inputList.push_back(inputList[0]);
        outputList.clear();

        for(int j = 1;j < inputList.size();j++)
        {
            QPointF currentPoint = inputList[j];
            QPointF prevPoint = inputList[j-1];

            int PrevP_code = getCode(prevPoint), curP_code = getCode(currentPoint);
            if(!(curP_code & borders[i]))
            {
                if(PrevP_code & borders[i])
                    outputList.push_back(intersectionPoint(prevPoint,currentPoint,borders[i]));
                outputList.push_back(currentPoint);
            }
            else if(!(PrevP_code & borders[i]))
                outputList.push_back(intersectionPoint(currentPoint,prevPoint,borders[i]));
        }

    }
    outputList.push_back(outputList[0]);
    return outputList;


}

QPointF MainWindow::intersectionPoint(QPointF P1, QPointF P2, int border){

    int P1_code = getCode(P1);

    QPointF intersectionPoint;
    if ((border ==  8) || ( border == -1 && (P1_code & 8)))
        intersectionPoint = QPointF(P1.x() + (P2.x()- P1.x()) * (Ymax - P1.y()) / (P2.y() - P1.y()),Ymax);
    else if ((border ==  4) || ( border == -1 && (P1_code & 4)))
        intersectionPoint = QPointF(P1.x() + (P2.x()- P1.x()) * (Ymin - P1.y()) / (P2.y() - P1.y()),Ymin);
    else if ((border ==  2) || ( border == -1 && (P1_code & 2)))
        intersectionPoint = QPointF(Xmax,P1.y() + (P2.y()- P1.y()) * (Xmax - P1.x()) / (P2.x() - P1.x()));
    else if ((border ==  1) || ( border == -1 && (P1_code & 1)))
        intersectionPoint = QPointF(Xmin,P1.y() + (P2.y()- P1.y()) * (Xmin - P1.x()) / (P2.x() - P1.x()));


    return intersectionPoint;
}


void MainWindow::on_comboBox_activated(int index)
{
    scale = 10*qPow(2,index);
}


void MainWindow::on_selectDirectoryB_clicked()
{
    QFileDialog* dial = new QFileDialog(this);
    QString path = dial->getOpenFileName(this,tr("Выберите файл"),"/",tr("txt(*.txt)"));
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {

        QTextStream in(&file);
        int segments_number = in.readLine().toInt();
        QStringList line;
        polygon.clear();
        segments.clear();
        for(int i = 0; i< segments_number;i++)
        {
            line = in.readLine().split(" ");
            segments.push_back(qMakePair(QPointF(line[0].toDouble(),line[1].toDouble()),QPointF(line[2].toDouble(),line[3].toDouble())));
        }

        int polygon_number = in.readLine().toInt();
        for(int i = 0;i<polygon_number; i++)
        {
            line = in.readLine().split(" ");
            polygon.push_back(QPointF(line[0].toDouble(),line[1].toDouble()));
        }

        polygon.push_back(polygon[0]);

        ready_ = 1;
    }

}
