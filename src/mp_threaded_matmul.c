#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// changed to an i k j loop for cache familiarity + threading using openmp
// compile using g -O3 -fopenmp mp_threaded_matmul.c -o ./bin/mpthreadedmatmul
float* matmul (float* A, float* B, float* C, int m, int n, int k) {
    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int offset = 0; offset < n; offset++) {
            for (int j = 0; j < k; j++) {
                C[i * k + j] += A[i * n + offset] * B[offset * k + j];
            }
        }
    }
    return C;
}

int main() {
    int m = 8192;
    int n = 8192;
    int k = 8192;
    
    float* A = malloc(m * n * sizeof(float));
    float* B = malloc(n * k * sizeof(float));
    float* C = malloc(m * k * sizeof(float));

    for (int i = 0; i < m * n; i++) A[i] = (float)rand() / RAND_MAX;
    for (int i = 0; i < n * k; i++) B[i] = (float)rand() / RAND_MAX;
    for (int i = 0; i < m * k; i++) C[i] = 0.0f;

    clock_t start = clock();
    matmul(A, B, C, m, n, k);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", time_taken);

    free(A);
    free(B);
    free(C);
    return 0;
}
