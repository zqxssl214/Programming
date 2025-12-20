#include <stdio.h>

void bin(int a) {
    for (int i = sizeof(a)*8-1; i>=0; i--) {
        printf("%d", (a>>i) & 1);
    }
}

int main () {
    int a, k;
    printf("Number and q pos: ");
    scanf("%d %d", &a, &k);
    printf("\n");
    bin(a);
    printf("\n");

    a = (a<<k) | (a>>(32-k));
    printf("%d", a);
    printf("\n");
    bin(a);
    printf("\n");
    
}