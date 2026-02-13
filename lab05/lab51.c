#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void print_arr(int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    printf("\n");
}

int main () {
printf("Size array of complex: ");
int N;
scanf("%d", &N);
srand(time(NULL));
int l = N * 2;
int complex[l];

for (int i=0; i<l;i++) {
    complex[i] = rand()%65536-32768;
}
printf("Signal value:\n");
for (int i = 0 ; i < N ; i++ ) {
    int real = complex[ 2*i];
    int mnim = complex[2*i+1];
    printf("s[%d] = %d + j*(%d)\n", i , real, mnim);

}
printf("Energy signal:\n");
long long sige=0;
for ( int i = 0; i < N; i++) { 
    int real = complex[2 * i];
    int mnim = complex[2 * i + 1];
    sige = sige + real * real + mnim * mnim;

}
printf("%lld\n", sige);

int max = complex[0];
for ( int i = 0 ; i < N ; i++) {
    int real = complex[2 * i];
    if ( real > max ) {
        max = real;
    }



}
printf("Maximal real chast: %d\n", max);
printf("Isxodni massiv s chislami:\n");
print_arr(l, complex);


}