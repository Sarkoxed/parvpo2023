#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct aboba{
    int x;
    int y;
    char z;
} aboba;

void modify(aboba* st){
    st->x = 1;
    st->y = 2;
    st->z = 3;
} 

aboba creat(aboba st){
    st.x = 1;
    st.y = 2;
    st.z = 3;
    return st;
}


int main(){
    int b;
    aboba s;
    s.x = 0;
    s.y = 0;
    s.z = 0;

    struct timespec t, t1, t2;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);
    
    for(b = 0; b < 1e9; b++){
        s = creat(s);
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2);
    t.tv_sec=t2.tv_sec-t1.tv_sec;
    
    if((t.tv_nsec = t2.tv_nsec - t1.tv_nsec) < 0){
        t.tv_sec--;
        t.tv_nsec += 1000000000;
    }

    double result = t.tv_sec + t.tv_nsec / 1e9;

    printf("Elapsed nop: %g\n\n", result / 1e9);

    s.x = 0;
    s.y = 0;
    s.z = 0;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t1);
    
    for(b = 0; b < 1e9; b++){
        modify(&s);
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t2);
    t.tv_sec=t2.tv_sec-t1.tv_sec;
    
    if((t.tv_nsec = t2.tv_nsec - t1.tv_nsec) < 0){
        t.tv_sec--;
        t.tv_nsec += 1000000000;
    }

    result = t.tv_sec + t.tv_nsec / 1e9;

    printf("Elapsed p: %g\n\n", result / 1e9);

    return 0;
}
