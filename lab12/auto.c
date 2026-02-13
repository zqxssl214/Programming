#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "auto.h"


static char* Names[] = {"Audi", "BMW", "Volkswagen", "Toyota", "Subaru"};


void SelectSort(struct Auto Cars[], int n) {
    int min;
    for (int i = 0; i < n-1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if(Cars[j].HP < Cars[min].HP) {
                min = j;
            }
        }
        if (min != i) {
            struct Auto temp = Cars[i];
            Cars[i] = Cars[min];
            Cars[min] = temp;
        }
    }
}


void fill(struct Auto Cars[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) { 
        Cars[i].Name = Names[rand() % 5];
        Cars[i].Year = rand() % 50 + 1970;
        Cars[i].HP = rand() % 750 + 50;
        Cars[i].Price = rand() % 7500000 + 150000;
    }
}
void PrintArr(struct Auto Cars[], int size) {
    for (int i = 0; i < size; i++) {  
        printf("========================================\n");
        printf("Car number %-10d                  |\n", i+1);
        printf("Model: %-10s                      |\n", Cars[i].Name);
        printf("Year of release: %-10d            |\n", Cars[i].Year);
        printf("Horse Power: %-10d                |\n", Cars[i].HP);
        printf("Price: %-10d                      |\n", Cars[i].Price);
    }
}