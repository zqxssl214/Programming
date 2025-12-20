#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int isPrime(int x) {
    if(x < 2) return 0;
    if (x == 2) return 1;
    for (int i = 2; i<x; i++) {
        if(x % i==0) return 0;

    }
    return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void array_eznull(int size, int array[size]) {
    int k = 0;
    for ( int i = 0 ; i < size; i++) {
        if (array[i]>=10 && array[i]<=99) {
            if (isPrime(array[i]) == 1) {
                array[i]=0;          
            
        } 
    }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_arr(int size, int array[size]) {
    for ( int i = 0 ; i < size; i++ ) {
        printf("Array[%d] = %d\n", i , array[i]);

    }
    printf("\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void arr_max(int size, int array[size], int maxarr) {
    maxarr = array[0];
    for (int i = 0; i < size; i++)
    if ( array[i]> maxarr  ) {
        maxarr = array[i];
    }
    printf("Max array num: >  %d  <\n", maxarr);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int array_ez(int size, int array[size]) {
    int k = 0;
    for ( int i = 0 ; i < size; i++) {
        if (array[i]>=10 && array[i]<=99) {
            if (isPrime(array[i]) == 1) {
            k++;
            printf("Easy number: s[%d] = %d\n", i, array[i]);
            
        }
        
    }
    }
printf("Value easy: >  %d  <\n", k);
return k;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








int main () {
    printf("Array size: ");
    srand(time(NULL));
    int size;
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i<size; i++) { 
        arr[i] = rand()%100;
    }

    print_arr(size, arr);
    arr_max(size, arr, 0);
    int k = array_ez(size,arr);
    if (k > 2) {
        array_eznull(size,arr);
    }
    printf("After null ez numbers:\n");
    print_arr(size,arr);
    printf("New max: \n");
    arr_max(size,arr, 0);
return 0;
}