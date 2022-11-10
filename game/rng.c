#include"rng.h"


int tebakan (){
    struct tm* ptr;
    time_t t;
    int a,b,c;
    t = time(NULL);
    ptr = localtime(&t);
    a =mktime(ptr);
    b=a%100;
    c=a%b;
    return c;
}

int playgame(int tebak){
    int a;//temp
    int i,count;
    boolean play;
    play = true;
    count =0;
    while (play){
    scanf("%d",&a);//temp
    printf("Tebakan : %d\n",a);
    count=count+1;
    if (a==tebak){
        printf ("Ya, X adalah %d.\n",tebak);
        play=false;
    }else if (a<tebak){
        printf("Lebih besar\n");
    }else if (a>tebak){
        printf("Lebih kecil\n");
    }
    }
    return count;
}