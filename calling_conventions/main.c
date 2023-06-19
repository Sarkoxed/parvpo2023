#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int __cdecl sum_prod(int x, int y, int z){
    return x * y + z + 5;
}

int main(){
    int b, tmp;
    srand(0xab0ba); 
    int* vals = (int*)calloc(20, sizeof(int));
    for(int i = 0; i < 20; i++){
        vals[i] = rand();
    }

    struct timespec t, t1, t2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);

    for(b = 0; b < 1e9; b++){
        tmp = sum_prod(vals[(7 * b) % 20], vals[(7 * b + 1) % 20], vals[(7 * b + 2) % 20]);//, vals[(7 * b + 3) % 20]);
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2);
    t.tv_sec=t2.tv_sec-t1.tv_sec;
    
    if((t.tv_nsec = t2.tv_nsec - t1.tv_nsec) < 0){
        t.tv_sec--;
        t.tv_nsec += 1000000000;
    }

    double result = t.tv_sec + t.tv_nsec / 1e9;
    

    printf("Elapsed: %g\n", result / 1e9);
    free(vals);
    return 0;
}
