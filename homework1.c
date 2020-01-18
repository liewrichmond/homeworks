#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generateNumbers() {
    static int returnArr[1000000];
    int i = 0;
    srand(time(NULL));
    for(int i = 0; i < 1000000; i++) {
        returnArr[i] = rand();
    }    
    return returnArr;
}



int main() {
    int* randNumbers = generateNumbers();
    printf("%d \n", randNumbers[0]);
    return 0;
}