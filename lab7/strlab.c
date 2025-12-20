#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main () {

    char text[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor \
    incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud \
    exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute \
    irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla \
    pariatur. Excepteur sint occaecat cup3i3d3atat non proident, sunt in culpa qui officia \
    deserunt mollit anim id est laborum.\n";


    printf("%s", text);

    int b = strlen(text);
    printf("%d\n", b);
    int sum = 0;

    for ( int i = 0; i<b; i++) {
        if ( isdigit(text[i]) ) {
        sum = sum + (text[i]-'0');
    }
    }
    
if ( sum!=0 ) {
   printf("Sum num: %d\n", sum);
}
else { 
    printf("Numbers not found!\n");
}
}