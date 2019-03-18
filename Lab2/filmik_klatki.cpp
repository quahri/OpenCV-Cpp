#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<windows.h>
#include<conio.h>           

using namespace cv;
using namespace std;

int c = 0;
int number_of_frames;
string int2str(int &);
clock_t start = clock();

int main(int argc, char **argv) {
	string s;
	cout << "Ile klatek filmu zapisac?: ";
	cin >> number_of_frames;
	VideoCapture cap("snake_synth.avi"); // video
	if (!cap.isOpened())
	{
		cout << "Nie uda³o siê otworzyæ pliku" << endl;
		return -1;
	}

	//double fps = cap.get(CAP_PROP_FPS); //ilosc ramek na sekunde
	
	while (1)
	{
		Mat frame;
	
		bool bSuccess = cap.read(frame);

		if (!bSuccess)
		{
			cout << "Nie uda³o siê odczytaæ ramki" << endl;
			break;
		}
		s = int2str(c);
	
		if (c == number_of_frames)
		{
			break;
		}		
		if (((1000 * (clock() - start)) / CLOCKS_PER_SEC) < 50)
		{
			imshow("Film", frame);
		}
		else
		{
			imshow("Film", frame);
			imwrite("zdj" + s + ".jpg", frame);
			c++;
		}
		
		if (waitKey(30) == 27)
		{
			break;
		}
	}
	return 0;
}

//int to string funkcja
string int2str(int &i) {
	string s;
	stringstream ss(s);
	ss << i;
	return ss.str();
}
