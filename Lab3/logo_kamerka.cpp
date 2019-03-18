#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>  

using namespace std;
using namespace cv;

int main() {

	Mat frame;
	VideoCapture cap;
	Mat logo = imread("logo.bmp", 0);

	cap.open(0);

	if (!cap.isOpened()) {
		cout << "Nie udało się uruchomić kamerki" << endl;
		return -1;
	}

	while (1)
	{
		cap.read(frame);
		cvtColor(frame, frame, COLOR_RGB2GRAY);
		resize(logo, logo, Size(50, 50));
		Rect react(frame.cols - 50, frame.rows - 50, 50, 50);

		frame(react) = logo + frame(react);

		imshow("Logo na kamerce", frame);

		char c = (char)waitKey(33);
		if (c == 27) break;

	}

	destroyAllWindows();
	cap.release();
	return 0;

}
