#include "widget.h"
#include "QtWidgets/qapplication.h"
#include "QtGui/qguiapplication.h"
#include "QtCore/qcoreapplication.h"
#include <QStyleFactory>
#include <QColorDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);

    qApp->setPalette(darkPalette);

    qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
    setWindowTitle("Цветовой селектор");

    resize(400,400);



    colorConvert = new QColor();
    space_id = space_name::rgb;
    spaces = {space_name::rgb, space_name::cmyk, space_name::hsv, space_name::hls, space_name::xyz};


    GradientLabel = new QLabel(this);

    back= new QGridLayout;
    back->setAlignment(Qt::AlignLeft);
    sliders= new QGridLayout;
    sliders->setAlignment(Qt::AlignRight);

    back->addLayout(sliders,0,0,4,4);

    left = new QComboBox;
    central = new QComboBox;
    right = new QComboBox();


    slider1 = new QSlider;
    slider1->setRange(0,255);
    slider1->setOrientation(Qt::Horizontal);
    sliderLabel1 = new QLabel;
    sliderLabel1->setMaximumSize(30,30);
    sliderLabel1->setAlignment(Qt::AlignRight);


    slider2 = new QSlider;
    slider2->setRange(0,255);
    slider2->setOrientation(Qt::Horizontal);
    sliderLabel2 = new QLabel;
    sliderLabel2->setMaximumSize(30,30);
    sliderLabel2->setAlignment(Qt::AlignRight);

    slider3 = new QSlider;
    slider3->setRange(0,255);
    slider3->setOrientation(Qt::Horizontal);
    sliderLabel3 = new QLabel;
    sliderLabel3->setMaximumSize(30,30);
    sliderLabel3->setAlignment(Qt::AlignRight);

    slider4 = nullptr;
    sliderLabel4 = new QLabel;
    sliderLabel4->setMaximumSize(30,30);
    sliderLabel4->setAlignment(Qt::AlignRight);

    ColorRect = new QLabel(this);
    ColorRect->setMaximumSize(700,10);
    ColorRect->setMinimumSize(700,10);
    ColorRect->setMinimumHeight(80);
    ColorRect->setMinimumWidth(10);

    ColorRect->setStyleSheet("QLabel{background-color:rgb(0,0,0);border:2px solid black;}");


    connect(slider1, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));
    connect(slider2, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));
    connect(slider3, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));



    left1 = new QSpinBox;
    left2 = new QSpinBox;
    left3 = new QSpinBox;
    left4 = nullptr;
    left1->setMinimumSize(200,20);

    left1->setRange(0, 255);
    left2->setRange(0, 255);
    left3->setRange(0, 255);

    connect(left1, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));
    connect(left2, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));
    connect(left3, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));

    mid1 = new QSpinBox;
    mid2 = new QSpinBox;
    mid3 = new QSpinBox;
    mid4 = new QSpinBox;
    mid1->setMinimumSize(200,20);

    mid1->setReadOnly(true);
    mid2->setReadOnly(true);
    mid3->setReadOnly(true);

    mid1->setRange(0, 255);
    mid2->setRange(0, 255);
    mid3->setRange(0, 255);

    right1 = new QSpinBox;
    right2 = new QSpinBox;
    right3 = new QSpinBox;
    right4 = nullptr;
    right1->setMinimumSize(200,20);

    right1->setReadOnly(true);
    right2->setReadOnly(true);
    right3->setReadOnly(true);

    right1->setRange(0, 359);
    right2->setRange(0, 255);
    right3->setRange(0, 255);

    LLabel1 = new QLabel("R:");
    LLabel1->setFont(QFont("Times", 10));

    LLabel2 = new QLabel("G:");
    LLabel2->setFont(QFont("Times", 10));

    LLabel3 = new QLabel("B:");
    LLabel3->setFont(QFont("Times", 10));

    LLabel4 = new QLabel;
    LLabel4->setFont(QFont("Times", 10));




    MLabel1 = new QLabel("C:");
    MLabel1->setFont(QFont("Times", 10));

    MLabel2 = new QLabel("M:");
    MLabel2->setFont(QFont("Times", 10));

    MLabel3 = new QLabel("Y:");
    MLabel3->setFont(QFont("Times", 10));

    MLabel4 = new QLabel("K:");
    MLabel4->setFont(QFont("Times", 10));

    RLabel1 = new QLabel("H:");
    RLabel1->setFont(QFont("Times", 10));

    RLabel2 = new QLabel("S:");
    RLabel2->setFont(QFont("Times", 10));

    RLabel3 = new QLabel("V:");
    RLabel3->setFont(QFont("Times", 10));

    RLabel4 = new QLabel;
    RLabel4->setFont(QFont("Times", 10));

    LeftLabels_Names("RGB");


    back->addWidget(GradientLabel, 0,4,1,2);
    back->addWidget(ColorRect, 3.5,0,1,6);

    sliders->addWidget(sliderLabel1,0,0,1,1);
    sliders->addWidget(sliderLabel2,1,0,1,1);
    sliders->addWidget(sliderLabel3,2,0,1,1);
    sliders->addWidget(sliderLabel4,3,0,1,1);

    sliders->addWidget(slider1,0,1,1,30);
    sliders->addWidget(slider2,1,1,1,30);
    sliders->addWidget(slider3,2,1,1,30);
    sliders->setAlignment(Qt::AlignTop);
    sliders->setVerticalSpacing(15);

    back->addWidget(left, 2,0,10,2);
    back->addWidget(central, 2,2,10,2);
    back->addWidget(right, 2,4,10,2);

    back->addWidget(left1, 7,1);
    back->addWidget(left2, 8,1);
    back->addWidget(left3, 9,1);

    back->addWidget(LLabel1,7,0);
    back->addWidget(LLabel2,8,0);
    back->addWidget(LLabel3,9,0);
    back->addWidget(LLabel4,10,0);

    back->addWidget(mid1, 7,3);
    back->addWidget(mid2, 8,3);
    back->addWidget(mid3, 9,3);
    back->addWidget(mid4, 10,3);

    back->addWidget(MLabel1,7,2);
    back->addWidget(MLabel2,8,2);
    back->addWidget(MLabel3,9,2);
    back->addWidget(MLabel4,10,2);

    back->addWidget(right1, 7,5);
    back->addWidget(right2, 8,5);
    back->addWidget(right3, 9,5);
    back->addWidget(right4, 10,5);

    back->addWidget(RLabel1,7,4);
    back->addWidget(RLabel2,8,4);
    back->addWidget(RLabel3,9,4);
    back->addWidget(RLabel4,10,4);

    left->setFont(QFont("Times", 10));
    left->addItem("RGB");
    left->addItem("CMYK");
    left->addItem("HSV");
    left->addItem("HLS");
    left->addItem("XYZ");

    central->setFont(QFont("Times", 10));
    central->addItem("CMYK");
    central->addItem("HSV");
    central->addItem("RGB");
    central->addItem("HLS");
    central->addItem("LAB");
    central->addItem("HLS");
    central->addItem("XYZ");

    right->setFont(QFont("Times", 10));
    right->addItem("HSV");
    right->addItem("CMYK");
    right->addItem("HLS");
    right->addItem("RGB");
    right->addItem("XYZ");
    right->addItem("LAB");


    QPushButton *chooseColorBtn = new QPushButton("Choose Color", this);


    back->addWidget(chooseColorBtn, 11, 0);


connect(chooseColorBtn, &QPushButton::clicked, [this]() {
        QColor color = QColorDialog::getColor();

        if (color.isValid()) {

            colorConvert->setRed(color.red());
            colorConvert->setGreen(color.green());
            colorConvert->setBlue(color.blue());


            setSpacesAndLabel();
        }
    });


    connect(left,SIGNAL(currentTextChanged(QString)),this,SLOT(LeftLabels_Names(QString)));
    connect(central,SIGNAL(currentTextChanged(QString)),this,SLOT(MidLabels_Names(QString)));
    connect(right,SIGNAL(currentTextChanged(QString)),this,SLOT(RightLabels_Names(QString)));

    this->setLayout(back);

}
double Widget::RGB_To_XYZ(double a)
{
    double x=a;
    if(x>= 0.04045)
    {
        return pow((x+0.055)/1.055,2.4);
    }
    else return (x/12.92);
}

double Widget::XYZ_To_LAB(double a)
{
    double x=a;
    if(x>= 0.008856)
    {
        return pow(x,1.0/3.0);
    }
    else return (7.787*x + 16.0/116.0);
}


QVector<int> Widget::getValues(space_name value_id)  // получает значение цвета
{
    QVector<int> values;
    switch(value_id)
    {
    case space_name::rgb:
        values.push_back(colorConvert->red());
        values.push_back(colorConvert->green());
        values.push_back(colorConvert->blue());
        break;
    case space_name::cmyk:
        int c,m,y,k;
        colorConvert->getCmyk(&c,&m,&y,&k);
        values= {c,m,y,k};
        break;
    case space_name::hsv:
        int h,s,v;
        colorConvert->getHsv(&h,&s,&v);
        values= {h,s,v};
        break;

    case space_name::hls:
        int h_,l_,s_;
        colorConvert->getHsl(&h_,&s_,&l_);
        values= {h_,l_,s_};
        break;
    case space_name::xyz:
    {
        double X,Y,Z;
        double r = colorConvert->red();
        double g = colorConvert->green();
        double b = colorConvert->blue();

        double Rn, Gn, Bn;
        Rn = qMin(qMax(0.0, RGB_To_XYZ (r / 255.0) *100.0), 100.0);
        Gn = qMin(qMax(0.0, RGB_To_XYZ (g / 255.0) *100.0), 100.0);
        Bn = qMin(qMax(0.0, RGB_To_XYZ (b / 255.0) *100.0), 100.0);

        X = 0.412453*Rn + 0.357580*Gn + 0.180423* Bn;
        Y = 0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
        Z = 0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

        values= {int(X),int(Y),int(Z)};
    }
    break;

    case space_name::lab:
    {
        double L,A,B;
        double X,Y,Z;
        double r = colorConvert->red();
        double g = colorConvert->green();
        double b = colorConvert->blue();

        double Rn, Gn, Bn;
        Rn = RGB_To_XYZ (r / 255.0) *100.0;
        Gn = RGB_To_XYZ (g / 255.0) *100.0;
        Bn = RGB_To_XYZ (b / 255.0) *100.0;

        X= 0.412453*Rn + 0.357580*Gn + 0.18042* Bn;
        Y= 0.212671*Rn + 0.715160*Gn + 0.072169*Bn;
        Z= 0.019334*Rn + 0.119193*Gn + 0.950227*Bn;

        double Xw = 95.047;
        double Yw = 100.0;
        double Zw = 108.883;

        L = 116.0 * XYZ_To_LAB(Y/Yw) -16.0;
        A = 500.0 *(XYZ_To_LAB(X/Xw) - XYZ_To_LAB(Y/Yw));
        B = 200.0 *(XYZ_To_LAB(Y/Yw) - XYZ_To_LAB(Z/Zw));

        values= {int(L),int(A), int (B)};
    }
    break;
    }

    return values;
}



double Widget::LAB_To_XYZ(double a)
{
    double x = a;
    if(pow(x,3)>= 0.008856)
    {
        return pow(x,3);
    }
    else return (x-16.0/116.0)/7.787;
}

double Widget::XYZ_To_RGB(double a)
{
    double x=a;
    if(x >= 0.0031308)
    {
        return (1.055*pow(x,1.0/2.4)-0.055);
    }
    else return 12.92*x;
}


void Widget::setColor(space_name value_id, int a, int b, int c, int d)
{
    switch(value_id)
    {
    case space_name::rgb:
        colorConvert->setRed(a);
        colorConvert->setGreen(b);
        colorConvert->setBlue(c);
        break;
    case space_name::cmyk:
        colorConvert->setCmyk(a,b,c,d);
        break;
    case space_name::hsv:
        colorConvert->setHsv(a,b,c);
        break;

    case space_name::hls:
        colorConvert->setHsl(a,c,b);
        break;
    case space_name::xyz:
    {
        double x = a;
        double y_ = b;
        double z = c;
        double Rn = 0.032406 *x - 0.015372*y_ -0.004986* z;
        double Gn = -0.009689 *x + 0.018758 *y_ + 0.000415 * z;
        double Bn= 0.000557 *x - 0.002040 *y_ + 0.010570 * z;


        double R= qMin(qMax(0.0,XYZ_To_RGB(Rn)*255), 255.0);
        double G= qMin(qMax(0.0, XYZ_To_RGB(Gn)*255), 255.0);
        double B= qMin(qMax(0.0, XYZ_To_RGB(Bn)*255), 255.0);

        colorConvert->setRed(R);
        colorConvert->setGreen(G);
        colorConvert->setBlue(B);
    }
    break;
    case space_name::lab:
    {
        double Xw = 95.047;
        double Yw = 100.0;
        double Zw = 108.883;
        double L=a;
        double A=b;
        double B=c;
        double Y = LAB_To_XYZ((L+16.0)/116.0)*Yw;
        double X = LAB_To_XYZ(A/500.0 + (L+16.0)/116.0)*Xw;
        double Z = LAB_To_XYZ((L+16.0)/116.0 - B/200.0)*Zw;

        double Rn = 0.032406 *X - 0.015372*Y -0.004986* Z;
        double Gn = -0.009689 *X + 0.018758 *Y + 0.000415 * Z;
        double Bn = 0.000557 *X - 0.002040 *Y + 0.010570 * Z;

        double R= XYZ_To_RGB(Rn)*255;
        double G= XYZ_To_RGB(Gn)*255;
        double B_= XYZ_To_RGB(Bn)*255;
        colorConvert->setRed(R);
        colorConvert->setGreen(G);
        colorConvert->setBlue(B_);
    }
    break;
    }
}


void Widget::LeftLabels_Names(QString text)
{
    slider2->setMaximum(255);
    slider3->setMaximum(255);
    if(text=="RGB")
    {
        space_id = space_name::rgb;
        spaces[0]=space_name::rgb;

        LLabel1->setText("R:");
        LLabel2->setText("G:");
        LLabel3->setText("B:");
        LLabel4->setText("");

        sliderLabel1->setText("R:");
        sliderLabel2->setText("G:");
        sliderLabel3->setText("B:");
        sliderLabel4->setText("");

        FirstSliderSetRange();
        FirstSpinSetRange(left1);

        if(left4)
        {
            delete left4;
            left4=nullptr;
        }

        if(slider4)
        {
            delete slider4;
            slider4=nullptr;
        }


    }
    if(text=="CMYK")
    {
        space_id = space_name::cmyk;
        spaces[0]=space_name::cmyk;
        FirstSliderSetRange();
        FirstSpinSetRange(left1);
        left4 = new QSpinBox;
        left4->setRange(0, 255);
        connect(left4, SIGNAL(valueChanged(int)), this, SLOT(spinsChanged(int)));
        back->addWidget(left4, 10,1);
        LLabel1->setText("C:");
        LLabel2->setText("M:");
        LLabel3->setText("Y:");
        LLabel4->setText("K:");

        sliderLabel1->setText("C:");
        sliderLabel2->setText("M:");
        sliderLabel3->setText("Y:");
        sliderLabel4->setText("K:");

        slider4 = new QSlider;
        slider4->setRange(0,255);
        slider4->setOrientation(Qt::Horizontal);
        connect(slider4, SIGNAL(sliderMoved(int)), this, SLOT(slidersMoved(int)));
        sliders->addWidget(slider4,3,1,1,30);

    }
    if(text=="HSV")
    {
        space_id = space_name::hsv;
        spaces[0]=space_name::hsv;
        FirstSliderSetRange(true);
        FirstSpinSetRange(left1, true);
        LLabel1->setText("H:");
        LLabel2->setText("S:");
        LLabel3->setText("V:");
        LLabel4->setText("");

        sliderLabel1->setText("H:");
        sliderLabel2->setText("S:");
        sliderLabel3->setText("V:");
        sliderLabel4->setText("");

        if(left4)
        {
            delete left4;
            left4=nullptr;
        }

        if(slider4)
        {
            delete slider4;
            slider4=nullptr;
        }
    }
    if(text=="HLS")
    {
        space_id = space_name::hls;
        spaces[0]=space_name::hls;
        FirstSliderSetRange(true);
        FirstSpinSetRange(left1, true);
        LLabel1->setText("H:");
        LLabel2->setText("L:");
        LLabel3->setText("S:");
        LLabel4->setText("");

        sliderLabel1->setText("H:");
        sliderLabel2->setText("L:");
        sliderLabel3->setText("S:");
        sliderLabel4->setText("");

        if(left4)
        {
            delete left4;
            left4=nullptr;
        }

        if(slider4)
        {
            delete slider4;
            slider4=nullptr;
        }
    }
    if(text=="XYZ")
    {
        space_id = space_name::xyz;
        spaces[0]=space_name::xyz;
        left1->setMaximum(95);
        slider1->setMaximum(95);
        slider2->setMaximum(100);
        slider3->setMaximum(108);
        LLabel1->setText("X:");
        LLabel2->setText("Y:");
        LLabel3->setText("Z:");
        LLabel4->setText("");

        sliderLabel1->setText("X:");
        sliderLabel2->setText("Y:");
        sliderLabel3->setText("Z:");
        sliderLabel4->setText("");

        if(left4)
        {
            delete left4;
            left4=nullptr;
        }

        if(slider4)
        {
            delete slider4;
            slider4=nullptr;
        }
    }
    setSliders(getValues(space_id));
    QVector<int> empty;
    setSpinBoxes(getValues(space_id),empty,empty);
}



void Widget::MidLabels_Names(QString text)
{
    mid2->setRange(0,255);
    mid3->setRange(0,255);
    if(text=="LAB")
    {
        mid2->setRange(-128,127);
        mid3->setRange(-128,127);
        spaces[1]= space_name::lab;
        MLabel1->setText("L:");
        MLabel2->setText("A:");
        MLabel3->setText("B:");
        MLabel4->setText("");
        if(mid4)
        {
            delete mid4;
            mid4=nullptr;
        }

    }

    if(text=="RGB")
    {
        spaces[1] = space_name::rgb;
        FirstSpinSetRange(mid1);
        MLabel1->setText("R:");
        MLabel2->setText("G:");
        MLabel3->setText("B:");
        MLabel4->setText("");
        if(mid4)
        {
            delete mid4;
            mid4=nullptr;
        }
    }
    if(text=="CMYK")
    {
        spaces[1]= space_name::cmyk;
        FirstSpinSetRange(mid1);
        mid4 = new QSpinBox;
        mid4->setRange(0, 255);
        mid4->setReadOnly(true);
        back->addWidget(mid4, 10,3);
        MLabel1->setText("C:");
        MLabel2->setText("M:");
        MLabel3->setText("Y:");
        MLabel4->setText("K:");
    }
    if(text=="HSV")
    {
        spaces[1] = space_name::hsv;
        FirstSpinSetRange(mid1, true);
        MLabel1->setText("H:");
        MLabel2->setText("S:");
        MLabel3->setText("V:");
        MLabel4->setText("");
        if(mid4)
        {
            delete mid4;
            mid4=nullptr;
        }
    }
    if(text=="XYZ")
    {
        spaces[1]= space_name::xyz;
        MLabel1->setText("X:");
        MLabel2->setText("Y:");
        MLabel3->setText("Z:");
        MLabel4->setText("");
        if(mid4)
        {
            delete mid4;
            mid4=nullptr;
        }
    }
    if(text=="HLS")
    {
        spaces[1] = space_name::hls;
        FirstSpinSetRange(mid1, true);
        MLabel1->setText("H:");
        MLabel2->setText("L:");
        MLabel3->setText("S:");
        MLabel4->setText("");
        if(mid4)
        {
            delete mid4;
            mid4=nullptr;
        }
    }
}

void Widget::RightLabels_Names(QString text)
{
    right2->setRange(0,255);
    right3->setRange(0,255);
    if(text=="LAB")
    {
        right2->setRange(-128,127);
        right3->setRange(-128,127);
        spaces[2] = space_name::lab;
        RLabel1->setText("L:");
        RLabel2->setText("A:");
        RLabel3->setText("B:");
        RLabel4->setText("");
        if(right4)
        {
            delete right4;
            right4=nullptr;
        }
    }

    if(text=="RGB")
    {
        spaces[2] = space_name::rgb;
        FirstSpinSetRange(right1);
        RLabel1->setText("R:");
        RLabel2->setText("G:");
        RLabel3->setText("B:");
        RLabel4->setText("");
        if(right4)
        {
            delete right4;
            right4=nullptr;
        }
    }
    if(text=="CMYK")
    {
        spaces[2]= space_name::cmyk;
        FirstSpinSetRange(right1);
        right4 = new QSpinBox;
        right4->setRange(0, 255);
        right4->setReadOnly(true);
        back->addWidget(right4, 10,5);
        RLabel1->setText("C:");
        RLabel2->setText("M:");
        RLabel3->setText("Y:");
        RLabel4->setText("K:");
    }
    if(text=="HSV")
    {
        spaces[2] = space_name::hsv;
        FirstSpinSetRange(right1, true);
        RLabel1->setText("H:");
        RLabel2->setText("S:");
        RLabel3->setText("V:");
        RLabel4->setText("");
        if(right4)
        {
            delete right4;
            right4=nullptr;
        }
    }
    if(text=="XYZ")
    {
        spaces[2] = space_name::xyz;
        RLabel1->setText("X:");
        RLabel2->setText("Y:");
        RLabel3->setText("Z:");
        RLabel4->setText("");
        if(right4)
        {
            delete right4;
            right4=nullptr;
        }
    }
    if(text=="HLS")
    {
        spaces[2] = space_name::hls;
        FirstSpinSetRange(right1, true);
        RLabel1->setText("H:");
        RLabel2->setText("L:");
        RLabel3->setText("S:");
        RLabel4->setText("");
        if(right4)
        {
            delete right4;
            right4=nullptr;
        }
    }
}




void Widget::FirstSliderSetRange(bool hueSpace)
{
    int max = 255;
    if(hueSpace) max = 359;
    slider1->setMaximum(max);
}

void Widget::FirstSpinSetRange(QSpinBox* spin, bool hueSpace)
{
    int max = 255;
    if(hueSpace) max = 359;
    spin->setMaximum(max);
}



void Widget::setSpacesAndLabel() // обновляет значения
{
    QVector<int> valuesLeft=getValues(spaces[0]);
    QVector<int> valuesMid=getValues(spaces[1]);
    QVector<int> valuesRight=getValues(spaces[2]);

    setSpinBoxes(valuesLeft, valuesMid, valuesRight);
    setColorLabel();
}

void Widget::setSpinsAndLabel()
{
    QVector<int> valuesLeft;
    QVector<int> valuesMid=getValues(spaces[1]);
    QVector<int> valuesRight=getValues(spaces[2]);

    setSpinBoxes(valuesLeft, valuesMid, valuesRight);
    setColorLabel();
}

void Widget::setColorLabel()
{
    r = QString::number(colorConvert->red());
    g = QString::number(colorConvert->green());
    b = QString::number(colorConvert->blue());

    ColorRect->setStyleSheet("QLabel{"
                             "background-color:rgb("+r+","+g+","+b+");"
                                                       "}");
}

void Widget::setSpinBoxes(QVector<int> valuesLeft, QVector<int> valuesMid, QVector<int> valuesRight) {
    if(!valuesLeft.empty())
    {
        spin_changed_manual = true;
        left1->setValue((valuesLeft[0]));
        spin_changed_manual = true;
        left2->setValue((valuesLeft[1]));
        spin_changed_manual = true;
        left3->setValue((valuesLeft[2]));
        if(left4 != nullptr)
        {
            spin_changed_manual = true;
            left4->setValue((valuesLeft[3]));
        }
    }

    if(valuesMid.empty()) return;
    spin_changed_manual = true;
    mid1->setValue((valuesMid[0]));
    spin_changed_manual = true;
    mid2->setValue((valuesMid[1]));
    spin_changed_manual = true;
    mid3->setValue((valuesMid[2]));
    if(mid4 != nullptr)
    {
        spin_changed_manual = true;
        mid4->setValue((valuesMid[3]));
    }

    if(valuesRight.empty()) return;
    spin_changed_manual = true;
    right1->setValue((valuesRight[0]));
    spin_changed_manual = true;
    right2->setValue((valuesRight[1]));
    spin_changed_manual = true;
    right3->setValue((valuesRight[2]));
    if(right4 != nullptr)
    {
        spin_changed_manual = true;
        right4->setValue((valuesRight[3]));
    }
}

void Widget::setSliders(QVector<int> valuesLeft)
{
    slider_changed_manual = true;
    slider1->setValue((valuesLeft[0]));
    slider_changed_manual = true;
    slider2->setValue((valuesLeft[1]));
    slider_changed_manual = true;
    slider3->setValue((valuesLeft[2]));
    if(slider4 != nullptr)
    {
        slider_changed_manual = true;
        slider4->setValue((valuesLeft[3]));
    }
}


void Widget::slidersMoved(int a)
{
    if(slider_changed_manual)
    {
        slider_changed_manual=false;
        return;
    }
    int val1= slider1->value();
    int val2= slider2->value();
    int val3= slider3->value();
    int val4=-1;
    if(slider4 != nullptr)
    {
        val4=slider4->value();
    }

    setColor(space_id, val1, val2, val3, val4);
    setSpacesAndLabel();
}

void Widget::spinsChanged(int a)
{
    if(spin_changed_manual)
    {
        spin_changed_manual=false;
        return;
    }
    int val1= left1->value();
    int val2= left2->value();
    int val3= left3->value();
    int val4=-1;
    if(left4 != nullptr)
    {
        val4=left4->value();
    }


    setColor(space_id, val1, val2, val3, val4);
    setSpinsAndLabel();
    QVector<int> values = {val1, val2, val3, val4};
    setSliders(values);
}


Widget::~Widget()
{
}
