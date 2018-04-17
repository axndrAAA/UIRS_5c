#include "stdafx.h"
#include "SaltAndPepperNoize.h"


SaltAndPepperNoize::SaltAndPepperNoize()
{
}

SaltAndPepperNoize::SaltAndPepperNoize(float _pa, float _pb, bool _isChanging)
{
	pa = _pa;
	pb = _pb;
	isChanging = _isChanging;
}


SaltAndPepperNoize::~SaltAndPepperNoize()
{
}

void SaltAndPepperNoize::addNoise(Mat & srcArr)
{
	RNG rng; // random number generator

	if(isChanging)
		rng = RNG(time(0)); // random number generator
	int amount1 = srcArr.rows*srcArr.cols*pa;
	int amount2 = srcArr.rows*srcArr.cols*pb;
	for (int counter = 0; counter<amount1; ++counter){		
		srcArr.at<uchar>(rng.uniform(0, srcArr.rows), rng.uniform(0, srcArr.cols)) = 0;
	}

	for (int counter = 0; counter<amount2; ++counter){
		srcArr.at<uchar>(rng.uniform(0, srcArr.rows), rng.uniform(0, srcArr.cols)) = 255;
	}
	

}
