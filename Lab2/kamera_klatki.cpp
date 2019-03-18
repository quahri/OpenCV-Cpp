#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace cv;
using namespace std;
int c = 0;
string int2str(int &);
int main()
{
	string s; 
	clock_t start = clock();
	int number_of_frames;
	VideoCapture cap;
	cap.open(0);

	double dWidth = cap.set(CAP_PROP_FRAME_WIDTH, 640);
	double dHeight = cap.set(CAP_PROP_FRAME_HEIGHT, 480);
	cout << "Ile klatek zapisaæ?: ";
	cin >> number_of_frames;
	while (true)
	{
		Mat image;
		cap >> image;
		
		bool bSuccess = cap.read(image);

		if (!bSuccess)
		{
			cout << "Nie mozna otworzyc pliku wideo" << endl;
			break;
		}
		s = int2str(c);
	
		if (c == number_of_frames)
		{
			break;
		}
		
		if (((1000 * (clock() - start)) / CLOCKS_PER_SEC) < 50)
		{
			imshow("Kamerka", image);
		}
		else {
				imshow("Kamerka", image);
				imwrite("zdj" + s + ".jpg", image);	
				c++;
		}
		if (waitKey(30) == 27)
		{
			break;
		}
	}
	return 0;
}
//int to string
string int2str(int &i) {
	string s;
	stringstream ss(s);
	ss << i;
	return ss.str();
}
