#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0);//调用摄像头
	double scale = 0.5;//对取得的帧进行缩放
	//0-100
	//肤色
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;
	//0-255
	while (1)
	{
		cv::Mat frame;
		cv::Mat hsvMat;
		cv::Mat detectMat;
		cap >> frame;//捕捉当前帧
		cvtColor(frame, hsvMat, COLOR_BGR2HSV);//转化为HSV格式
		frame.copyTo(detectMat);
		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);//保存到detectMat中
		cv::imshow("white:in the rage", detectMat);//显示肤色捕捉帧
		cv::imshow("frame", frame);//显示当前帧
		waitKey(30);
	}
}