#include "stdafx.h"
#include "DetectorAnalyzer.h"


DetectorAnalyzer::DetectorAnalyzer(CvCapture * capture):DetectorAnalyzer()
{
	this->capture = capture;
}

void DetectorAnalyzer::run()
{
	getNextFrame(curGrayFrame);
	while (curFrame) {
		getNextFrame(curGrayFrame);
		show(curGrayFrame, 0);

		char c = cvWaitKey(33);
		if (c == 27) { break; }
		if (c == char(' ')) {
			c = 0;
			while (c != char(' '))
			{
				c = cvWaitKey(33);
			}

		}
	}


}

void DetectorAnalyzer::getNextFrame(Mat & Frame)
{
	//чтение кадра
	curFrame = cvQueryFrame(capture);
	if (!curFrame) {
		std::cout << "Error! Frame not captured";
		cvWaitKey(33);
		return;
	}

	curRGBFrame = cvarrToMat(curFrame);
	//перевод в градации серго
	cvtColor(curRGBFrame, curGrayFrame, CV_BGR2GRAY);
	//масштабирование в градациях серго
	cvtColor(curGrayFrame, curGrayFrame, CV_GRAY2BGR);
	Frame = curGrayFrame;
}

void DetectorAnalyzer::show(const Mat & toShow, int winNumber)
{
	imshow(windowNames[winNumber], toShow);
}








DetectorAnalyzer::DetectorAnalyzer()
{
	for (int i = 0; i < windowNames.size(); i++) {
		namedWindow(windowNames[i], CV_WINDOW_AUTOSIZE);

	}
}


DetectorAnalyzer::~DetectorAnalyzer()
{
	for (int i = 0; i < windowNames.size(); i++) {
		cvDestroyWindow(windowNames[i].c_str());
	}
}
