#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void mult(int* A, int* B, int* C){
#pragma clang loop vectorize(assume_safety)
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                C[i * 4 + j] += A[i * 4 + k] * B[k * 4 + j];
            }
        }
    }
//#pragma clang loop unroll_count(4)
//#pragma GCC target("avx2")
//#pragma clang loop vectorize_width(4) interleave_count(4)
}

int main(){
    int b;
    int A[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int B[16] = {21, 46, 18, 43, 75, 17, 96, 68, 55, 66, 59, 12, 26, 54, 38, 100};
    int* C = (int*)calloc(16, sizeof(int));
    int* tmp;

    struct timespec t, t1, t2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);
    
    for(int i = 0; i < 1e8; i++){
        mult(A, B, C);
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2);
    t.tv_sec=t2.tv_sec-t1.tv_sec;
    
    if((t.tv_nsec = t2.tv_nsec - t1.tv_nsec) < 0){
        t.tv_sec--;
        t.tv_nsec += 1000000000;
    }

    double result = t.tv_sec + t.tv_nsec / 1e9;

    printf("Elapsed: %g\n\n", result);
    free(C);
    return 0;
}
