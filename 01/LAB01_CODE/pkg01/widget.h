#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QMouseEvent>
#include <QImage>
#include <QColor>
#include <QPainter>
#include <QApplication>
#include <QComboBox>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QLineEdit>
#include <QSlider>
#include <QLabel>
#include <QPainterPath>
#include <QMessageBox>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QSpinBox>
#include <QtMath>
enum space_name
{
    rgb=0,
    cmyk,
    hsv,
    xyz,
    hls,
    lab
};



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void Color(QColor color);
public slots:
    
    void LeftLabels_Names(QString text);
    void MidLabels_Names(QString text);
    void RightLabels_Names(QString text);
    QVector <int> getValues(space_name value_id);
    void setColor(space_name value_id, int a,int b,int c, int d = -1);
    void slidersMoved(int a);
    void spinsChanged(int a);
    void setSpacesAndLabel();
    void setColorLabel();
    void setSpinBoxes(QVector<int> valuesLeft, QVector<int> valuesMid, QVector<int> valuesRight);
    void setSliders(QVector<int> valuesLeft);
    void setSpinsAndLabel();
    
    double RGB_To_XYZ(double a);
    double XYZ_To_LAB(double a);
    
    double XYZ_To_RGB(double a);
    double LAB_To_XYZ(double a);

protected:



private:
    Ui::Widget *ui;
    QColor *colorConvert;
    space_name space_id;

    bool spin_changed_manual=false;
    bool slider_changed_manual = false;
    QVector<space_name> spaces;
    QLabel *ColorRect;

    QString r;
    QString g;
    QString b;
    
    QSlider *slider1;
    QSlider *slider2;
    QSlider *slider3;
    QSlider *slider4;
    
    QComboBox *left;
    QComboBox *central;
    QComboBox *right;
    
    QGridLayout *back;
    QGridLayout *sliders;
    
    QSpinBox *left1;
    QSpinBox *left2;
    QSpinBox *left3;
    QSpinBox *left4;
    
    QSpinBox *mid1;
    QSpinBox *mid2;
    QSpinBox *mid3;
    QSpinBox *mid4;
    
    QSpinBox *right1;
    QSpinBox *right2;
    QSpinBox *right3;
    QSpinBox *right4;
    
    QLabel*sliderLabel1;
    QLabel*sliderLabel2;
    QLabel*sliderLabel3;
    QLabel*sliderLabel4;


    QLabel *LLabel1;
    QLabel *LLabel2;
    QLabel *LLabel3;
    QLabel *LLabel4;

    QLabel *MLabel1;
    QLabel *MLabel2;
    QLabel *MLabel3;
    QLabel *MLabel4;

    QLabel *RLabel1;
    QLabel *RLabel2;
    QLabel *RLabel3;
    QLabel *RLabel4;

    void FirstSliderSetRange(bool hueSpace = false);
    void FirstSpinSetRange(QSpinBox* spin, bool hueSpace = false);

};
#endif // WIDGET_H

