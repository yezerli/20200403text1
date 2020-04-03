#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}//阈值20,60
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		Mat frame;
		Mat dx;
		Mat dy;
		Mat abs_dx;
		Mat abs_dy;
		Mat edges;
		Mat edge;
		cap.read(frame);
		Sobel(frame, dx, CV_16SC1, 1, 0, 3);
		convertScaleAbs(dx, abs_dx);
		Sobel(frame, dy, CV_16SC1, 0, 1, 3);
		convertScaleAbs(dy, abs_dy);
		Canny(dx, dy, edges, 20, 60);
		Canny(frame, edge, 20, 60);
		imshow("frame", frame);
		imshow("dx", abs_dx);
		imshow("dy", abs_dy);
		imshow("edges", edges);
		imshow("edge", edge);
		waitKey(0);
	}
}