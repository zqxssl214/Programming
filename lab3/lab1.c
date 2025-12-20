#include <stdio.h>

int main () {
int size;
printf("Size: ");
scanf("%d",&size);
if (size<5){size=5;}
for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
        if (i + j >= size - 1){
        printf("o");}
        else {printf(" ");}
    }  
printf("\n");}   
}