#ifndef Lapulasi_Lapulasi_H
#define Lapulasi_Lapulasi_H
#define _GLIBCXX_USE_CXX11_ABI 0
#include<iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <cv.hpp>
using namespace std;
using namespace cv;
typedef uchar ty;

class Lapulasi{
public:
    int X_image,Y_image;
    int TempltExcute(Mat &src,int *tmplt,int tw,int x,int y);
    void SharpLapulasi(Mat &src,Mat &dst);
};

#endif //Lapulasi_Lapulasi_H
