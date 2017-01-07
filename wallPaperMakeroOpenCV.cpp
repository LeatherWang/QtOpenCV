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
    //�����������أ�����������ֵ
    for (int i = 0; i < colorim.rows; i++)
    for (int j = 0; j < colorim.cols;j++)
    {
        Vec3b pixel;//��������pixel
        pixel[0] = i % 255;
        pixel[1] = j % 255;
        pixel[2] = 0;
                  /*�������ݶ��߿ɺ���
            image.at<cv::Vec3b>(j, i)[0] = 255;
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;��������ǿ�*/
        //����i��j�е�����ֵ��Ϊ����ֵΪpixel����ɫ
        colorim.at<Vec3b>(i, j) = pixel;

        //��i��j�е�����ֵ��Ϊ128
        grayim.at<uchar>(i, j) = (i+j)%255;
    }
    imshow("colcorim", colorim);
    imshow("grayim", grayim);
    imwrite("./123.jpg",grayim);
    cv::waitKey();
	return 1;
}