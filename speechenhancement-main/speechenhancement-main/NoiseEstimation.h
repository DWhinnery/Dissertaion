#ifndef NoiseEstimation_h
#define NoiseEstimation_h

class NoiseEstimation {
public:
	//static void fft(float* x, float* re, float* im, int nFFT, int nFFT2, short int* w, int f);
	static void FrameAvg(float* av, float** x, int nFFT2, int number_of_frames);
	//static float* hamwin(int nFFT, int nFFT2);
	static void SpectralSub(float** x, int nFFT2, int numbet_of_frames);
	static void SpectralSubSplit(float** x, int nFFT2, int numbet_of_frames,float* av);
	
};

#endif