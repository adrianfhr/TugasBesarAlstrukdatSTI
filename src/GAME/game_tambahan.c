#include"game_tammbahan.h"
int game_tambahan(){
    struct tm* ptr;
    time_t t;
    int a,b,c;
    t = time(NULL);
    ptr = localtime(&t);
    a =mktime(ptr);
    b=a%100;
    c=a%b;
    printf("GAME OVER\n");
    printf("FINAL SCORE : %d \n",c);
}