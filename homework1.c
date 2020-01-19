#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int* generateNumbers() {
    static int returnArr[1000000];
    int i = 0;
    srand(time(NULL));
    for(int i = 0; i < 1000000; i++) {
        returnArr[i] = rand();
    }    
    return returnArr; 
}

void merge(int arr[], int l, int m, int r) {
    int leftPtr, rightPtr, mergePtr;
    int sizeLeft = m - l + 1;
    int sizeRight = r - m;

    int left[sizeLeft], right[sizeRight];

    for(int i = 0; i < sizeLeft; i++) {
        left[i] = arr[l + i];
    }
    for(int j = 0; j < sizeRight; j++) {
        right[j] = arr[m + 1 + j];
    }

    leftPtr = 0;
    rightPtr = 0;
    mergePtr = l;

    while(leftPtr < sizeLeft && rightPtr < sizeRight) {
        if(left[leftPtr] <= right[rightPtr]) {
            arr[mergePtr] = left[leftPtr];
            leftPtr++;
        }
        else {
            arr[mergePtr] = right[rightPtr];
            rightPtr++;
        }
        mergePtr++;
    }


    while(leftPtr < sizeLeft) {
        arr[mergePtr] = left[leftPtr];
        leftPtr++;
        mergePtr++;
    }

    while(rightPtr < sizeRight) {
        arr[mergePtr] = right[rightPtr];
        rightPtr++;
        mergePtr++;
    }

}

void mergeSort(int arr[], int l, int r) {
        if (l < r) 
    { 
        int m = l+(r-l)/2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 

}

int main() {
    int* randNumbers = generateNumbers();

    mergeSort(randNumbers, 0, 99999);

    for(int i = 0; i < 50; i++){
        printf("%i \n", randNumbers[i]);
    }
    return 0;
}