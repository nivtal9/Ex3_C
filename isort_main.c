#include <stdio.h>
#include "isort.h"
#define SIZE 50
int main() {
    int arr[SIZE];
    printf("Please enter 50 numbers for the arr:\n");
    for (int i = 0; i < SIZE; i++) {
        int temp_numb;
        scanf(" %d", &temp_numb);
        *(i+arr) = temp_numb;
    }
    printf("your arr before sort is:\n");
    for (int j = 0; j < SIZE; j++) {
        if (j == SIZE-1) {
            printf("%d.\n", arr[j]);
        } else {
            printf("%d|", arr[j]);
        }
    }
        insertion_sort(arr, SIZE);
        printf("your arr after sort is:\n");
        for (int j = 0; j < SIZE; j++) {
            if (j == SIZE-1) {
                printf("%d.\n", arr[j]);
            } else {
                printf("%d|", arr[j]);
            }
        }
    }
