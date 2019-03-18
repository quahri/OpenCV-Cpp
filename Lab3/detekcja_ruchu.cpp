#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<windows.h>
#include<conio.h>           

using namespace cv;
using namespace std;


int main(int argc, char **argv) {

	VideoCapture cap("robot_no_loop.avi"); // video
	if (!cap.isOpened())
	{
		cout << "Nie udało się otworzyć pliku" << endl;
		return -1;
	}
	Mat klatka, film_bin,wynik, wynik2, prev;
	
	cap >> klatka;
	cvtColor(klatka, klatka, COLOR_RGB2GRAY, 1);
	
	while (1)
	{
		cap >> prev;
		cap >> film_bin;
	
		cvtColor(film_bin, film_bin, COLOR_RGB2GRAY, 1);
		cvtColor(prev,prev, COLOR_RGB2GRAY, 1);
		
		absdiff(film_bin, klatka, wynik);
		threshold(wynik,wynik, 150, 255, THRESH_TRUNC);
		imshow("Aktualna i pierwsza", wynik);
		
		absdiff(film_bin,prev, wynik2);
		threshold(wynik2, wynik2, 150, 255, THRESH_TRUNC);
		imshow("Aktualna i poprzednia", wynik2);
	
		if (waitKey(30) == 27)
		{
			break;
		}
		
	}
	return 0;
}
