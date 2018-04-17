#pragma once
#include"opencv2/opencv.hpp"
#include<vector>

using namespace cv;
using namespace std;


class DetectorAnalyzer
{
private:

	CvCapture* capture;
	vector<cv::String> windowNames = { "Show1" ,"Show2" };

	Mat curGrayFrame, curRGBFrame, referenceFrame;
	IplImage* curFrame = 0;

public:
	DetectorAnalyzer(CvCapture *capture);
	void run();

	void getNextFrame(Mat &Frame);
	void show(const Mat & toShow, int winNumber);


	DetectorAnalyzer();
	~DetectorAnalyzer();
};

