#ifndef DETECTHSCOLOR
#define DETECTHSCOLOR

#include"cv.h"
#include"cxcore.h"
#include"highgui.h"
#include <stdio.h>

using namespace cv;
using namespace std;

void detectHScolor(const cv::Mat& image,
                   double minHue,double maxHue,
                   double minSat,double maxSat,
                   cv::Mat& mask)
{
    Mat hsv;
    cvtColor(image,hsv,CV_BGR2HSV);

    vector<cv::Mat> channels;
    split(hsv,channels);
    //channels[0] 是色度
    //channels[1] 是饱和度
    //channels[2] 是亮度

    Mat mask1;
    threshold(channels[0],mask1,maxHue,255,THRESH_BINARY_INV);//小于maxHue
    Mat mask2;
    threshold(channels[0],mask2,minHue,255,THRESH_BINARY);//大于minHue

    Mat hueMask;//色度掩码
    if(minHue < maxHue)
        hueMask = mask1 & mask2;
    else
        hueMask = mask1 | mask2;//如果区间穿越0度中轴线

    threshold(channels[1],mask1,maxSat,255,THRESH_BINARY_INV);
    threshold(channels[1],mask2,minSat,255,THRESH_BINARY);

    Mat satMask;//饱和度掩码
    satMask = mask1 & mask2;

    mask = hueMask & satMask;//组合掩码
}
#endif // DETECTHSCOLOR

