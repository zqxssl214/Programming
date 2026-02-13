// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void m1x1(int m, int matrix[m][m]) {
//     printf("%d", matrix[0][0]);
// }

// void m2x2(int m, int matrix[m][m]) {
//     int det = 0;
//     det = matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
//     printf("%d",det);
// }

// void m3x3(int m, int matrix[m][m]) {
//     int det = 0;
//     det = (matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[0][1]*matrix[1][2]*matrix[2][0])+
//     (matrix[0][2]*matrix[1][0]*matrix[2][1])-(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[0][1]*matrix[1][0]*matrix[2][2])-
//     (matrix[0][0]*matrix[1][2]*matrix[2][1]);
//     printf("%d", det);
// }

// void gldiag (int m, int matrica[m][m]) {
//     for (int i = 0; i<m; i++ ) {
//         for (int j = 0; j<m; j++ ){
//     if (i==j) {
//         printf("%d\n", matrica[i][j]);
//         }
//     }
// }
// }
// int main () {

//     srand(time(NULL));
//     printf("Matrix size: ");
//     int N;
//     scanf("%d", &N);
//     int matrix[N][N];

//     for ( int i = 0; i < N; i++) { 
//         for ( int j = 0;  j < N; j++ )
//         matrix[i][j]=rand()%10;

//     }

//     for ( int i = 0; i<N; i++) {
//         for (int j = 0; j < N; j++) {
//         printf(" %d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// gldiag(N, matrix);
// if (N==1) {
//     printf("Determinant = ");
//     m1x1(N,matrix);
//     printf("\n");
// }
// if (N==2) {
//     printf("Determinant = ");
//     m2x2(N, matrix);
//     printf("\n");
// }
// if (N==3) {
//     printf("Determinant = ");
//     m3x3(N, matrix);
//     printf("\n");
// }

// }


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void printf_matrix(int n, int matrix[n][n]) {
    for (int i = 0 ; i<n ; i++) {
        for (int j = 0 ; j<n; j++) {
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");
    }
}

void printf_arrb(int size, int array[size]) {
    for ( int i = 0 ; i < size ; i++) {
        printf("%d   ", array[i]);
    }
}

int det2x2(int matrix[2][2]) {
    int det;
    det = matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
    return det;
}

int det3x3(int matrix[3][3]) {
    int det;
    det = (matrix[0][0]*matrix[1][1]*matrix[2][2])+(matrix[0][1]*matrix[1][2]*matrix[2][0])+
    (matrix[0][2]*matrix[1][0]*matrix[2][1])-(matrix[0][2]*matrix[1][1]*matrix[2][0])-(matrix[0][1]*matrix[1][0]*matrix[2][2])-
    (matrix[0][0]*matrix[1][2]*matrix[2][1]);
    return det;
}


void replacek(int n, int matrix[n][n], int col, int newcol[n]) {
    for (int i = 0; i < n; i++) {
        matrix[i][col]= newcol[i];
    }

}

void copy(int n, int original[n][n], int copiya[n][n]) {
    for ( int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            copiya[i][j]=original[i][j];
        }
    }
}


void sistema2x2() {
    int A[2][2];
    int B[2];
    int C[2][2];
    srand(time(NULL));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j]=rand()%1000;
        }
    }
    for (int i = 0; i<2; i++) {
        B[i]= rand()%1000;
    }
    printf("Matrix coefficent: \n");
    printf_matrix(2, A);
    printf("Free vectors: \n");
    printf_arrb(2, B);
    printf("\n");
    int main_det = det2x2(A);
    if (main_det == 0) {
        printf("System have no solution\n");
        return;
    }
    copy(2, A, C);
    replacek(2,C,0,B);
    int detx = det2x2(C);
    copy(2,A,C);
    replacek(2,C,1,B);
    int dety = det2x2(C);

    float x = (float)detx/(float)main_det;
    float y = (float)dety/(float)main_det;

    printf("det = %d\n", main_det);
    printf("detX = %d\n", detx);
    printf("detY = %d\n", dety);
    printf("X = %.2f\n", x);
    printf("Y = %.2f\n", y);

}

void sistema3x3() {
    srand(time(NULL));
    int A[3][3];
    int B[3];
    int C[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j]=rand()%1000;
        }
    }
    for (int i = 0; i<3; i++) {
        B[i]= rand()%1000;
    }

    int main_det = det3x3(A);
    if (main_det==0) {
        printf("System have no solution");
        return;
    }
    copy(3,A,C);
    replacek(3,C,0,B);
    int detx = det3x3(C);
    copy(3,A,C);
    replacek(3,C,1,B);
    int dety = det3x3(C);
    copy(3, A, C);
    replacek(3,C,2,B);
    int detz = det3x3(C);

    float x = (float)detx/(float)main_det;
    float y = (float)dety/(float)main_det;
    float z = (float)detz/(float)main_det;

    printf("Matrix coefficents: \n");
    printf_matrix(3, A);
    printf("Free vectors: \n");
    printf_arrb(3,B);
    printf("\n");
    printf("det = %d\n", main_det);
    printf("detX = %d\n", detx);
    printf("detY = %d\n", dety);
    printf("detZ = %d\n", detz);
    printf("X = %.2f  Y = %.2f   Z = %.2f \n", x, y, z);



    


    

}


int main () {
    printf("Size SL(2 OR 3): ");
    int n;
    scanf("%d", &n );
    if (n==2) {

    sistema2x2();
    }
    else if (n == 3) {
        sistema3x3();
    }
    return 0;
}