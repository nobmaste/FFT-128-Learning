#include "FFT_128.h"
#define BASE 32
#define PI 3.14159265358979323846

void FFT_128(int* inputArray, int** Re, int** Im) {
    *Re = (int*)malloc(sizeof(int) * BASE);
    *Im = (int*)malloc(sizeof(int) * BASE);
    

    for(int loop =BASE/2; loop > 1; loop = loop/2) {
        splitArray(inputArray, loop);
    }   
   for(int i=0;i<BASE;i++){//实部和虚部分别赋值
        (*Re)[i] = inputArray[i];
        (*Im)[i] = 0;
    }
   
for (int len = 2; len <= BASE; len <<= 1) {
    int mid = len >> 1;
    int gap = BASE / len;
    for (int i = 0; i < BASE; i += len) {
        for (int j = 0; j < mid; j++) {
            int a = i + j;
            int b = a + mid;
            double real = cos(2 * PI * j / len);
            double imag = -sin(2 * PI * j / len);
            double tReal = real * (*Re)[b] - imag * (*Im)[b];
            double tImag = real * (*Im)[b] + imag * (*Re)[b];
            (*Re)[b] = (*Re)[a] - tReal;
            (*Im)[b] = (*Im)[a] - tImag;
            (*Re)[a] += tReal;
            (*Im)[a] += tImag;
        }
    }
}

}


//排序时间复杂度为NlogN，优化：反转排序，复杂度为N
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