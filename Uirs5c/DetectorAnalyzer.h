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

	/// Parameters for Shi-Tomasi algorithm
	double qualityLevel = 0.01;
	double minDistance = 10;
	int blockSize = 3;
	bool useHarrisDetector = false;
	double k = 0.04;
	int maxCorners = 1000;
	int MIN_FOUND_POINTS = 900;

public:
	DetectorAnalyzer(CvCapture *capture);
	void run();

	void getNextFrame(Mat &Frame,bool isRGBRangeEnable);
	void drawMarkers(Mat & refImg, Mat &outImg, vector<Point2f>& points, Scalar color);
	void getShiThomasPoints(const Mat & image, vector<Point2f> &corners);
	void show(const Mat & toShow, int winNumber);


	DetectorAnalyzer();
	~DetectorAnalyzer();
};

