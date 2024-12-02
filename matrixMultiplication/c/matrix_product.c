#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DP double  // Define DP as double for double precision
#define N_LARGE 500
#define N_SMALL 100

void allocate_and_fill(DP ***A, DP ***B, DP ***C, int n);
void matrix_multiply(DP **A, DP **B, DP **C, int n);
void free_matrix(DP **matrix, int n);

int main() {
    DP **A, **B, **C;
    clock_t start, finish;
    double elapsed_large, elapsed_small;

    // Timing benchmark for large matrix
    allocate_and_fill(&A, &B, &C, N_LARGE);
    start = clock();
    matrix_multiply(A, B, C, N_LARGE);
    finish = clock();
    elapsed_large = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time taken for %dx%d matrix: %f seconds\n", N_LARGE, N_LARGE, elapsed_large);

    free_matrix(A, N_LARGE);
    free_matrix(B, N_LARGE);
    free_matrix(C, N_LARGE);

    // Timing benchmark for small matrix
    allocate_and_fill(&A, &B, &C, N_SMALL);
    start = clock();
    matrix_multiply(A, B, C, N_SMALL);
    finish = clock();
    elapsed_small = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time taken for %dx%d matrix: %f seconds\n", N_SMALL, N_SMALL, elapsed_small);

    free_matrix(A, N_SMALL);
    free_matrix(B, N_SMALL);
    free_matrix(C, N_SMALL);

    return 0;
}

// Function to allocate and fill matrices A and B with random values
void allocate_and_fill(DP ***A, DP ***B, DP ***C, int n) {
    int i, j;

    *A = (DP **)malloc(n * sizeof(DP *));
    *B = (DP **)malloc(n * sizeof(DP *));
    *C = (DP **)malloc(n * sizeof(DP *));
    for (i = 0; i < n; i++) {
        (*A)[i] = (DP *)malloc(n * sizeof(DP));
        (*B)[i] = (DP *)malloc(n * sizeof(DP));
        (*C)[i] = (DP *)malloc(n * sizeof(DP));
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            (*A)[i][j] = (DP)rand() / RAND_MAX;
            (*B)[i][j] = (DP)rand() / RAND_MAX;
            (*C)[i][j] = 0.0;
        }
    }
}

// Function for matrix multiplication: C = A * B
void matrix_multiply(DP **A, DP **B, DP **C, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0.0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to free allocated memory for a matrix
void free_matrix(DP **matrix, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
