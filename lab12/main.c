#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "auto.h"

#define N1 100
#define N2 10000
#define N3 100000

int main() {
    struct timeval start, end;
    double time_taken;
    
    printf("========================================\n");
    printf(" Time sort\n");
    

    struct Auto* Cars1 = malloc(N1 * sizeof(struct Auto));
    fill(Cars1, N1);
    

    struct Auto* temp1 = malloc(N1 * sizeof(struct Auto));
    for (int i = 0; i < N1; i++) temp1[i] = Cars1[i];
    
    gettimeofday(&start, NULL);
    SelectSort(temp1, N1);
    gettimeofday(&end, NULL);
    
    time_taken = (end.tv_sec - start.tv_sec) * 1000000.0;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) / 1000000.0;
    
    printf("----------------------------------------\n");
    printf("N = %d\n", N1);
    printf("Time: %.6f seconds\n", time_taken);
    printf("----------------------------------------\n\n");
    
    free(temp1);
    
    struct Auto* Cars2 = malloc(N2 * sizeof(struct Auto));
    fill(Cars2, N2);
    
    struct Auto* temp2 = malloc(N2 * sizeof(struct Auto));
    for (int i = 0; i < N2; i++) temp2[i] = Cars2[i];
    
    gettimeofday(&start, NULL);
    SelectSort(temp2, N2);
    gettimeofday(&end, NULL);
    
    time_taken = (end.tv_sec - start.tv_sec) * 1000000.0;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) / 1000000.0;
    
    printf("----------------------------------------\n");
    printf("N = %d\n", N2);
    printf("Time: %.6f seconds\n", time_taken);
    printf("----------------------------------------\n\n");
    
    free(temp2);
    
    struct Auto* Cars3 = malloc(N3 * sizeof(struct Auto));
    fill(Cars3, N3);
    
    struct Auto* temp3 = malloc(N3 * sizeof(struct Auto));
    for (int i = 0; i < N3; i++) temp3[i] = Cars3[i];
    
    
    gettimeofday(&start, NULL);
    SelectSort(temp3, N3);
    gettimeofday(&end, NULL);
    
    time_taken = (end.tv_sec - start.tv_sec) * 1000000.0;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) / 1000000.0;
    
    printf("----------------------------------------\n");
    printf("N = %d\n", N3);
    printf("Time: %.6f seconds\n", time_taken);
    printf("----------------------------------------\n");
    
    free(Cars1);
    free(Cars2);
    free(Cars3);
    free(temp3);
    
    
    return 0;
}