#include"rng.h"


int tebakan (){
    struct tm* ptr;
    time_t t;
    int a,b,c;
    int i;
    t = time(NULL);
    ptr = localtime(&t);
    a =mktime(ptr);
    b=a%100;
    c=a%b;
    return c;
}

int playgame(int tebak){
    
}