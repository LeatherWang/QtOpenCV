#include <iostream>

#include "cv.h"
#include "highgui.h"
#include "histogram.h"
using namespace std;
using namespace cv;
int main()
{

    Mat grayim(1080, 1920, CV_8UC1);
    Mat colorim(1080, 1920, CV_8UC3);
    //遍历所有像素，并设置像素值
    for (int i = 0; i < colorim.rows; i++)
    for (int j = 0; j < colorim.cols;j++)
    {
        Vec3b pixel;//创建数组pixel
        pixel[0] = i % 255;
        pixel[1] = j % 255;
        pixel[2] = 0;
                  /*以下内容读者可忽略
            image.at<cv::Vec3b>(j, i)[0] = 255;
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;椒盐噪点那块*/
        //将第i行j列的像素值设为像素值为pixel的颜色
        colorim.at<Vec3b>(i, j) = pixel;

        //将i行j列的像素值设为128
        grayim.at<uchar>(i, j) = (i+j)%255;
    }
    imshow("colcorim", colorim);
    imshow("grayim", grayim);
    imwrite("./123.jpg",grayim);
    cv::waitKey();
	return 1;
}