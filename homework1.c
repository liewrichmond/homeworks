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

void merge(int arr[], int l, int m, int r, bool ascending) {
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
        if(ascending) {
            if(left[leftPtr] <= right[rightPtr]) {
                arr[mergePtr] = left[leftPtr];
                leftPtr++;
            }
            else {
                arr[mergePtr] = right[rightPtr];
                rightPtr++;
            }
        }
        else
        {
            if(left[leftPtr] >= right[rightPtr]) {
                arr[mergePtr] = left[leftPtr];
                leftPtr++;
            }
            else {
                arr[mergePtr] = right[rightPtr];
                rightPtr++;
            }
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

void mergeSort(int arr[], int l, int r, bool ascending) {
        if (l < r) 
    { 
        int m = l+(r-l)/2; 

        mergeSort(arr, l, m, ascending); 
        mergeSort(arr, m+1, r, ascending); 
  
        merge(arr, l, m, r, ascending); 
    } 

}

int main() {

    clock_t t;
    t = clock();

    int* randNumbers = generateNumbers();
    int secondHalf[500000];

    for(int i = 0; i < 499999; i++) {
        secondHalf[i] = randNumbers[500000 + i];
    }

    mergeSort(randNumbers, 0, 999999, true);
    mergeSort(secondHalf, 0, 499999, false);

    // for(int i = 0; i < 50; i++){
    //     printf("%i \n", randNumbers[i]);
    //     printf("%i \n", secondHalf[i]);
    // }

    t = clock() - t;
    double exec_time = ((double) t)/ CLOCKS_PER_SEC;
    printf("Execution Time: %f\n", exec_time);
    return 0;
}