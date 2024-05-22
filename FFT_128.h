#ifndef FFT_128_H
#define FFT_128_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void FFT_128(int* inputArray, int** Re, int** Im);
void splitArray(int* inputArray, unsigned char length);

#endif