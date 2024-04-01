#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>
#include <malloc.h>

double dot_product_c(double* A, double* B, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += A[i] * B[i];
    }
    return result;
};

extern void asmfunc(double* A, double* B, int n, double* Sdot_asm);

int main() {
    int i = 20; // change as necessary
    int n = 1 << i;
    double* A = (double*)_aligned_malloc(n * sizeof(double), 32);
    double* B = (double*)_aligned_malloc(n * sizeof(double), 32);
    double Sdot_asm;
    if (A == NULL || B == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit the program with an error code
    }

    for (int i = 0; i < n; i++) {
        A[i] = 1.0; // Example initialization
        B[i] = 1.0; // Example initialization
    }

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);
    double result_c = dot_product_c(A, B, n);
    QueryPerformanceCounter(&end);
    double time_c = (end.QuadPart - start.QuadPart) / (double)frequency.QuadPart;

    printf("Vector size: 2^%d\n", i);
    printf("Dot product result (C): %lf\n", result_c);
    printf("Dot product time (C): %lf\n", time_c);


    QueryPerformanceCounter(&start);
    asmfunc(A, B, n, &Sdot_asm);
    QueryPerformanceCounter(&end);
    double time_asm = (end.QuadPart - start.QuadPart) / (double)frequency.QuadPart;

    printf("Dot product result (ASM): %lf\n", Sdot_asm);
    printf("Dot product time (ASM): %lf\n", time_asm);

    _aligned_free(A);
    _aligned_free(B);

    return 0;
}
