#include <stdio.h>
#include "auto.h"

#define N 5

int main() {
    struct Auto Cars[N];
    
    fill(Cars, N);
    
    printf("========================================\n");
    printf("========================================\n");
    printf("BEFORE SELECTSORT\n");
    PrintArr(Cars, N);
    
    SelectSort(Cars, N);
    
    printf("========================================\n");
    printf("========================================\n");
    printf("AFTER SELECTSORT (SORT BY HORSE POWER) \n");
    PrintArr(Cars, N);
    
    return 0;
}