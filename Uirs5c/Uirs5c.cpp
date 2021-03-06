// Uirs5c.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"opencv2/opencv.hpp"
#include"DetectorAnalyzer.h"

using namespace std;
using namespace cv;

int main()
{
	char* fin = "video.mp4";
	std::cout << fin << endl;

	CvCapture *capture = cvCreateFileCapture(fin);
	if (!capture) {
		std::cout << "File doesn`t exist. exit" << endl;
		system("pause");
		return 1;
	}

	DetectorAnalyzer detectorAnalyzer(capture);
	detectorAnalyzer.run();

	cvReleaseCapture(&capture);

    return 0;
}

