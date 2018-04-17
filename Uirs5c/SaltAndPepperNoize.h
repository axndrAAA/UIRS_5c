#pragma once
#include"opencv2/opencv.hpp"
using namespace cv;

class SaltAndPepperNoize
{

private:
	float pa, pb;
	bool isChanging;
public:
	SaltAndPepperNoize();
	SaltAndPepperNoize(float _pa, float _pb,bool _isChanging);
	~SaltAndPepperNoize();

	void addNoise(Mat &scrArr);

};

