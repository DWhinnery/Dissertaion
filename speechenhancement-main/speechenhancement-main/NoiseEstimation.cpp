//Comment 

#include "NoiseEstimation.h"
#include <iostream>
using namespace std;
#include <math.h>
#define M_PI 3.14159265358979323846

//Averages are clculated based on the first 20 frames
void NoiseEstimation::FrameAvg(float* av,float** x, int nFFT2, int number_of_frames)
{
	
	for (int k = 0; k <= nFFT2; k++)
	{
		av[k] = 0;
	}
	for (int t = 0; t < 20; t++)
	{
		for (int k = 0; k <= nFFT2; k++)
		{
			av[k] += x[t][k];
		}
	}
	for (int k = 0; k <= nFFT2; k++)
	{
		av[k] /= 20;
	}
}



void NoiseEstimation::SpectralSub(float** x, int nFFT2, int number_of_frames)
{
	float* av = new float[nFFT2 + 1];


	for (int k = 0; k <= nFFT2; k++)
	{
		av[k] = 0;
	}
	for (int t = 0; t < 20; t++)
	{
		for (int k = 0; k <= nFFT2; k++)
		{
			av[k] += x[t][k];
		}
	}
	for (int k = 0; k <= nFFT2; k++)
	{
		av[k] /= 20;
	}
	for (int t = 0; t < number_of_frames; t++)
	{
		for (int k = 0; k <= nFFT2; k++) 
		{
			x[t][k] -= av[k];
		}
	}
}
//averages calculated are subtracted from every value in every frame
void NoiseEstimation::SpectralSubSplit(float** x, int nFFT2, int number_of_frames,float* av)
{
	
	for (int t = 0; t < number_of_frames; t++)
	{
		for (int k = 0; k <= nFFT2; k++)
		{
			x[t][k] -= av[k];
		}
	}

}