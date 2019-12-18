//
// Created by nivtal9 on 16.12.2019.
//
#include "isort.h"

void shift_element(int* arr, int i){
    for (int j = i-1; j >-1 ; j--) {
        *(j+arr+1)=*(j+arr);
    }
}
void insertion_sort(int* arr,int len){
    int p,j,i;
    for (i = 1; i < len; i++) {j=i-1;
        while(j>=0) {
            if (*(j+arr+1)<*(j+arr)) {
                p = *(arr + 1 + j);
            shift_element(j+arr, 1);
            *(j+arr) = p;
        }
            j=j-1;
        }
    }
}