#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// changed to an i k j loop for cache familiarity
// compile using g -O3 seq_matmul.c -o ./bin/seqmatmul
float* matmul (float* A, float* B, float* C, int m, int n, int k) {
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
    int m = 2048;
    int n = 2048;
    int k = 2048;
    
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
