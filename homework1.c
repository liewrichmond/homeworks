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
    for(int i = 0; i < 20; i++){
        printf("%d \n", randNumbers[i]);
    }
    return 0;
}