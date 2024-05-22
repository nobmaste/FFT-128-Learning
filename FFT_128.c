#include "FFT_128.h"

void FFT_128(int* inputArray, int** Re, int** Im) {
    *Re = (int*)malloc(sizeof(int) * 128);
    *Im = (int*)malloc(sizeof(int) * 128);
    
    splitArray(inputArray, 64);
    for(int i = 0; i < 128; i++) {
        (*Re)[i] = 0;
        (*Im)[i] = inputArray[i];
    }
}



void splitArray(int* inputArray, unsigned char length) {
    int temp[128];
    unsigned char group = (128 / length);
    for(int i = 0; i < 128; i++) {
        temp[i] = inputArray[i];
    }
    
    for (int j = 0; j < group/2; j++) {
        int new_temp[length*2];
        for(int k = 0; k < length*2; k++) {
            new_temp[k] = temp[j*length + k];
        }
        for(int i = 0; i < length; i++){
            inputArray[j*group + i] = new_temp[2*i];     //偶数索引
            inputArray[j*group + i + length] = new_temp[2*i + 1]; //奇数索引
        }
        
    }
}

void main() {
    int inputArray[128];
    int* Re;
    int* Im;
    for(int i = 0; i < 128; i++) {
        inputArray[i] = i;
    }

    FFT_128(inputArray, &Re, &Im);
    for (int i = 0; i < 128; i++) {
        printf("%d \n", inputArray[i]);
    }
    
}