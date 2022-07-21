
#include "FFT.h"
#include <iostream>
using namespace std;
#include <math.h>
#define M_PI 3.14159265358979323846

void FFT::fft(float* x, float* re, float* im, int nFFT, int nFFT2, short int* w, int f)
{
	// real part
	re[0] = 0.;
	for (int n = 0; n < nFFT; n++) re[0] += x[n];
	re[nFFT2] = 0.;
	for (int n = 0; n < nFFT; n++) {
		float a = (n % 2) ? -x[n] : x[n];
		re[nFFT2] += a;
	}
	for (int k = 1; k < nFFT2; k++) {
		re[k] = 0.;
		for (int n = 0; n < nFFT; n++)
			re[k] += x[n] * cos(2 * M_PI * k * n / nFFT);
	}

	// imaginary part
	im[0] = im[nFFT2] = 0.;
	for (int k = 1; k < nFFT2; k++) {
		im[k] = 0.;
		for (int n = 0; n < nFFT; n++)
			im[k] += x[n] * sin(2 * M_PI * k * n / nFFT);
	}
}
  
//value inputted is put to 2 to the power of inputted value to be used for the fft value
int FFT::nfftpower(int x)
	{
		return pow(2, x);
	}
//method to calulate hamming window
float* FFT::hamwin(int nFFT, int nFFT2) {
	float* hw = new float[nFFT];
	for (int n = 0; n < nFFT; n++)
	{
		hw[n] = 0.54 - 0.46 * (cos(2 * M_PI * n / (nFFT - 1)));
	}
	return hw;
	
}

void FFT::Pha(float* p, int nFFT, int nFFT2, float* re, float* im)
{
	float ph;
	for (int k = 0; k <= nFFT2; k++) {
		if (re[k] == 0.)
			ph = (im[k] >= 0.F) ? M_PI / 2.F : -M_PI / 2.F;
		else {
			ph = atan(im[k] / re[k]);
			if (re[k] < 0. && im[k] < 0.)
				ph -= M_PI;
			else if (re[k] < 0. && im[k] >= 0.)
				ph += M_PI;
		}
		p[k] = ph;
	}
}

void FFT::iFFT(float* x, int nFFT, int nFFT2, float* re, float* im)
{
	for (int n = 0; n < nFFT; n++) {
		float a = (n % 2) ? -re[nFFT2] : re[nFFT2];
		x[n] = re[0] + a;
		for (int k = 1; k < nFFT2; k++)
			x[n] += re[k] * (float)cos(2 * M_PI * k * n / nFFT) + im[k] * (float)sin(2 * M_PI * k * n / nFFT);
		for (int k = nFFT2 + 1; k < nFFT; k++) {
			int k1 = nFFT - k;
			int k2 = k - nFFT2;
			float a = re[k1] * (float)cos(2 * M_PI * k2 * n / nFFT) - im[k1] * (float)sin(2 * M_PI * k2 * n / nFFT);
			if (n % 2) a = -a;
			x[n] += a;
		}
		x[n] /= nFFT;
	}
}

void FFT::iFFT2(float* a, float* p, float* x, int nFFT, int nFFT2, float* re, float* im)
{
	for (int k = 0; k <= nFFT2; k++) {
		re[k] = a[k] * cos(p[k]);
		im[k] = a[k] * sin(p[k]);
	}
	iFFT(x, nFFT, nFFT2, re, im);

}



