#include "opencv2/core/core.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

using namespace cv;
using namespace std;

int main()
{
	char str[26];
    strcpy(str,"xdotool mousemove 0000 0000");
    char x18,x19,x20,x21,x23,x24,x25,x26,x22;
    int a,b;

	CascadeClassifier face_cascade,eyes_cascade;
	face_cascade.load("haarcascade_frontalface_alt.xml");
	eyes_cascade.load("haarcascade_mcs_eyepair_big.xml");

	Mat frame,frame_gray;
	std::vector<Rect> faces;
	std::vector<Rect> eyes;
  	VideoCapture stream1(0);
  	while(true)
  	{

  		stream1.read(frame);
  	cvtColor( frame, frame_gray, CV_BGR2GRAY );
  	equalizeHist( frame_gray, frame_gray );

  //-- Detect faces
  	face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

  for( size_t i = 0; i < faces.size(); i++ )
  {
    Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
    ellipse( frame, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

    Mat faceROI = frame_gray( faces[i] );
    

    //-- In each face, detect eyes
    eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    for( size_t j = 0; j < eyes.size(); j++ )
     {
       Point center( faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5 );
       //int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
       //circle( frame, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
       a=faces[i].x + eyes[j].x + eyes[j].width*0.5;
     b=faces[i].y + eyes[j].y + eyes[j].height*0.5;
     a=(double)(a-527)*5.45;
	 b=(double)(b-292)*4.864;
	 if(a>1500)
    a=1500;
	if(b>800)
    b=800;

	a=1500-a;
        //cout<<"|"<<a<<"*"<<b<<"| ";
        x18=(a/1000)+48;
		x19=(a/100)%10+48;
		x20=(a/10)%10+48;
		x21=(a)%10+48;

		x23=(b/1000)+48;
		x24=(b/100)%10+48;
		x25=(b/10)%10+48;
		x26=(b)%10+48;

		str[18]=x18;
		str[19]=x19;
		str[20]=x20;
		str[21]=x21;
//y-coordiantes
		str[23]=x23;
		str[24]=x24;
		str[25]=x25;
		str[26]=x26;
		system(str);
     }
     

  }

  //imshow( "trial", frame );
  waitKey(10);
	}
}
