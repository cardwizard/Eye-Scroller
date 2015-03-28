#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	VideoCapture stream2(0);
	Mat image,image2;
	CascadeClassifier eye_cascade="eye"

	while(true)
	{
	//stream1.read(image);
	stream2.read(image2);
	//imshow("cam1",image);
	imshow("cam2",image2);
	waitKey(10);
	}
	return 0;
}