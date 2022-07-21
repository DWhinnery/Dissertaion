
#ifndef FFT_H
#define FFT_H

class FFT {
public:
	static void fft(float* x, float* re, float* im, int nFFT, int nFFT2, short int* w, int f);
	static int nfftpower(int x);
	static float* hamwin(int nFFT, int nFFT2);
	static void Pha(float* p, int nFFT, int nFFT2, float* re, float* im);
	static void iFFT(float* x, int nFFT, int nFFT2, float* re, float* im);
	static void iFFT2(float* a, float* p, float* x, int nFFT, int nFFT2, float* re, float* im);
};





#endif // !FFT_H

