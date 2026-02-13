#include <stdio.h>

void bin(int num) {
    for ( int i = sizeof(num)*2-1 ; i>=0 ; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main () { 
    printf("Number and quantity pos: ");
    int a, k;
    scanf("%d %d", &a, &k);
    bin(a);
    printf("\n");
    a = (a<<k) | ((1<<k)-1);
    bin(a);
    printf("\n");
    printf("Number: %d\n", a);
    return 0;

}