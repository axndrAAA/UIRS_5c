#include "stdafx.h"
#include "DetectorAnalyzer.h"
#include"SaltAndPepperNoize.h"


DetectorAnalyzer::DetectorAnalyzer(CvCapture * capture):DetectorAnalyzer()
{
	this->capture = capture;
}

void DetectorAnalyzer::run()
{
	getNextFrame(curGrayFrame,false);
	SaltAndPepperNoize sapNoize(0.1, 0.05,false);
	vector<Point2f> points;

	while (curFrame) {
		getNextFrame(curGrayFrame,false);//1 - SaltPepper doesnt work

		sapNoize.addNoise(curGrayFrame);


		getShiThomasPoints(curGrayFrame, points);
		drawMarkers(curGrayFrame, curGrayFrame, points, Scalar(124, 252, 0));

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

void DetectorAnalyzer::getNextFrame(Mat & Frame, bool isGray2BGREnable)
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
	if(isGray2BGREnable)
		cvtColor(curGrayFrame, curGrayFrame, CV_GRAY2BGR);
	Frame = curGrayFrame;
}

void DetectorAnalyzer::drawMarkers(Mat & refImg, Mat & outImg, vector<Point2f>& points, Scalar color)
{
	cvtColor(curGrayFrame, curGrayFrame, CV_GRAY2BGR);
	outImg = refImg.clone();

	for (int i = 0; i < points.size(); i++) {
		drawMarker(outImg, Point(points[i].x, points[i].y), color, MARKER_CROSS, 3, 1);
	}
}

void DetectorAnalyzer::getShiThomasPoints(const Mat & image, vector<Point2f>& corners)
{
	Mat img;

	/// Copy the source image

	try {
		cvtColor(image, img, CV_BGR2GRAY);
			}
	catch (...) {
		img = image.clone();

	}

	/// Apply corner detection
	goodFeaturesToTrack(img,
		corners,
		maxCorners,
		qualityLevel,
		minDistance,
		Mat(),
		blockSize,
		useHarrisDetector,
		k);
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
