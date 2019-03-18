#include "opencv2/opencv.hpp"
#include<opencv2/highgui/highgui.hpp>
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main() {

	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "Blad otwarcia kamerki" << endl;
		return -1;
	}
	
	int fps = 5;
	
	VideoWriter video("outcpp.avi", VideoWriter::fourcc('M', 'P', 'E', 'G'), fps, Size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT)));
	int i = 0;
	waitKey(50);
	while (1)
	{
		Mat frame, img;
		
		cap >> frame;
		cvtColor(frame, frame, COLOR_RGB2GRAY,0); 

		for (int i = 0; i < 460; i++)
		{
			for (int j = 0; j < 640; j++)
			{
				frame.at<uchar>(i, j) = 255 - frame.at<uchar>(i, j);
			}
		}
	
		if (frame.empty())
			break;

		cvtColor(frame, frame, COLOR_GRAY2BGR, 0);
		video.write(frame); 
		imshow("Frame", frame);
		
		char c = (char)waitKey(15);
		if (c == 27)
			break;
		if (i == 100) {
			break;
		}
		i++;
	}

	waitKey(30);

	cap.release();
	video.release();

	destroyAllWindows();
	return 0;
}
