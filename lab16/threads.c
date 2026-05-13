#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#define N 5
// #define NOF_THREADS 2


//Gloval variables:
char* msg[] = {"Text N1", "Text N2", "Text N3", "Text N4", "Text N5", "Text N6", "Text N7", "Text N8"};

int numbers[] = {2, 5, 6, 3, 7, 4 };

pthread_mutex_t mutex;

int turn_flag = 0;

int **A;
int **B;
int **C;

int NOF_THREADS2;
int SIZE;

typedef struct thread_data {
    int start_row;
    int end_row;
} thread_data_t;






void *cleanup_msg(void *arg){
    printf("Thread was canceled!\n");
    return NULL;
}

void *Terminal_print(void *arg) {
    pthread_cleanup_push(cleanup_msg, NULL);
    char* msg = (char *) arg;
    for ( int i = 0; i < N; i++) {
        while (1) {
            pthread_mutex_lock(&mutex);
            if (turn_flag == 1) {
                printf("%s\n", msg);
                turn_flag = 0;
                pthread_mutex_unlock(&mutex);
                break;
            }
            pthread_mutex_unlock(&mutex);
        }
    }
    pthread_cleanup_pop(0);
    return NULL;
}

void *matrix_calculate(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    for ( int i = data->start_row; i < data->end_row; i++ ){
        for (int j = 0; j< SIZE; j++){
        C[i][j]=0;
        for ( int k = 0 ; k < SIZE; k++) {
            C[i][j] += A[i][k] * B[k][j];
        }
        }
    }
    return NULL;
}

void *Sleep_sort(void *arg) {
    int value = *(int *) arg;
    sleep(value);
    printf("%d \n", value);
    fflush(stdout);
    return NULL;
}



int main (int argc, char *argv[]) {

//////////////////////////////////////////SYNC/////////////////////////////

    // pthread_t tids[NOF_THREADS];

    // pthread_mutex_init(&mutex, NULL);

    // for ( int i = 0; i < NOF_THREADS; i++) {
    //     pthread_create(&tids[i], NULL, Terminal_print, msg[i]);
    // }

///////////////////////////////////////////////With sync will be deadlock

    // sleep(2);

    // for(int i = 0; i < NOF_THREADS; i++) { 
    //     pthread_cancel(tids[i]);
    // }

///////////////////////////////////////////////

    // for (int i = 0; i < NOF_THREADS*N; i++) {
    //     while(1) {
    //         pthread_mutex_lock(&mutex);
    //         if (turn_flag == 0) {
    //             printf("Text father\n");
    //             turn_flag = 1;
    //             pthread_mutex_unlock(&mutex);
    //             break;
    //         }
    //         pthread_mutex_unlock(&mutex);
    //     }
    // }

/////////////////////////////////////////SLEEPSORT/////////////////////////////////////////////

    // int a = sizeof(numbers)/4;
    // pthread_t tids[a];
    // for ( int i = 0; i< a; i++) {
    //     pthread_create(&tids[i], NULL, Sleep_sort, &numbers[i]);
    // }
    // for (int i = 0; i < a; i++) {
    //     pthread_join(tids[i], NULL);
    // }





////////////////////////////////////////MATRIX(COMMENT DEF NOF)////////////////////////////////////////////////////    


    struct timespec start, end;
    if ( argc < 3) {
        printf("Uncorrecs usage: 1) matrix size 2) threads number\n");
        return 1;  
    }

    SIZE = atoi(argv[1]);
    NOF_THREADS2 = atoi(argv[2]);

    A = malloc(SIZE * sizeof(int *));
    B = malloc(SIZE * sizeof(int *));
    C = malloc(SIZE * sizeof(int *));
    for ( int i = 0; i < SIZE; i++) {
        A[i] = malloc(SIZE * sizeof(int));
        B[i] = malloc(SIZE * sizeof(int));
        C[i] = malloc(SIZE * sizeof(int));
    }
    pthread_t *tids = malloc(NOF_THREADS2* sizeof(pthread_t));
    thread_data_t *data = malloc (NOF_THREADS2 * sizeof(thread_data_t));
    for (int i = 0; i < SIZE;i++) {
        for (int j = 0; j <SIZE; j++){
            A[i][j] = 1;
            B[i][j] = 1;
        }
    }

    int rows_for_thread = SIZE / NOF_THREADS2;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i = 0; i < NOF_THREADS2; i++){
        data[i].start_row = i * rows_for_thread;
        data[i].end_row = (i + 1) * rows_for_thread;


        pthread_create(&tids[i], NULL, matrix_calculate, &data[i]);
    }

    for( int i = 0; i < NOF_THREADS2; i++) {
        pthread_join(tids[i], NULL);

    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    printf("Matrix A: \n");
    for ( int i = 0; i < SIZE; i++) {
        printf("\n");
        for ( int j = 0; j < SIZE; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");

    }
    printf("Matrix B: \n");
    for ( int i = 0; i < SIZE; i++) {
        printf("\n");
        for ( int j = 0; j < SIZE; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");

    }
    printf("Matrix C: \n");
    for ( int i = 0; i < SIZE; i++) {
        printf("\n");
        for ( int j = 0; j < SIZE; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");

    }
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Size: %d, Threads: %d, Time: %f sec\n", SIZE, NOF_THREADS2, time_taken);

// /////////////////////////////////////////////////////////////////////////////////////////
    }
