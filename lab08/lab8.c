#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int** input_matrix(int N) {
    int** matrix=malloc(N*sizeof(int*));
    if (matrix==NULL) {
        printf("Error!");
        exit(1);
    }
    for ( int i = 0; i < N; i++) {
        matrix[i]=malloc(N*sizeof(int));
        if(matrix[i]==NULL) {
            printf("Error!");
            exit(1);
        }
    }

    printf("Write elements of Matrix\n");
    for ( int i = 0; i < N; i++) {
        for ( int j = 0; j < N; j++) {
            printf("Matrix[%d][%d]= ", i , j);
            scanf("%d", &matrix[i][j]);
        }
    }
    return matrix;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_matrix(int size, int **matrix) {
    for (int i=0; i<size; i++) {
        for (int j = 0; j<size; j++) {
            printf("[%d][%d]=%d   ", i, j,  matrix[i][j]);
        }
        printf("\n");
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void print_arr(int size, int* array) {
    for ( int i = 0; i < size; i++) {
        printf("[%d]=%d", i, array[i]);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int center(int n, int** matrix) {
    return matrix[n/2][n/2];
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int* array_size(int** matrix, int n, int *count) {
    *count = 0;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++) {
            if ( j > i && j > n - 1 - i) {
                *count = *count + 1;
            }
        }
    }


    int* array=malloc(*count * sizeof(int));
    if (array==NULL) {
        printf("Error!");
        exit(1);
    }
    int k = 0;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0 ; j < n; j++) {
            if ( j>i && j > n - 1 - i) {
                array[k]=matrix[i][j];
                k = k + 1;
        }
    }
    }
    return array;


}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int summa(int* array, int center, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if ( array[i] < center) {
            sum = sum + array[i];
        }

    }
    return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void freem(int** matrix, int n) {
    for ( int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    printf("Size of matrix: \n");
    int n;
    scanf("%d", &n);
    int** A= input_matrix(n);
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    print_matrix(n, A);
    printf("||||||||||||||||||||||||||||||||||||||||\n");
    int cent=center(n, A);
    int count;
    int* B=array_size(A,n,&count);
    printf("Size of array = %d\n", count);
    printf("Peresek element: %d\n", cent);
    print_arr(count,B);
    printf("\n");
    printf("\n");
    int sum = summa(B,cent, count);
    printf("Sum elements < cent = %d\n", sum);
    freem(A,n);
    free(B);
    return 0;



}