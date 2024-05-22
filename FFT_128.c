#include "FFT_128.h"
#define BASE 32

void FFT_128(int* inputArray, int** Re, int** Im) {
    *Re = (int*)malloc(sizeof(int) * BASE);
    *Im = (int*)malloc(sizeof(int) * BASE);
    

    for(int loop =BASE/2; loop > 1; loop = loop/2) {
        splitArray(inputArray, loop);
    }   
   
}


//排序
void splitArray(int* inputArray, unsigned char length) {
    int temp[BASE];
    unsigned char group = (BASE / length);
    for(int i = 0; i < BASE; i++) {
        temp[i] = inputArray[i];
    }
    
    for (int j = 0; j < group; j=j+2) {
        int new_temp[length*2];
        for(int k = 0; k < length*2; k++) {
            new_temp[k] = temp[j*length + k];
        }
        for(int i = 0; i < length; i++){
            inputArray[j*length + i] = new_temp[2*i];     //偶数索引
            inputArray[j*length + i + length] = new_temp[2*i + 1]; //奇数索引
        }
        
    }
}

void main() {
    int inputArray[BASE];
    int* Re;
    int* Im;
    for(int i = 0; i < BASE; i++) {
        inputArray[i] = i;
    }

    FFT_128(inputArray, &Re, &Im);
    
}