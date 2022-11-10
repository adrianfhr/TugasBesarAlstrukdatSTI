#include"rng.h"


#include"rng.h"



int playgame(){
    int a;//temp
    int i,count;
    time_t t;
    int b,c;
    t = time(NULL);
    b=t%100;
    c=t%b;
    boolean play;
    play = true;
    count =0;
    while (play){
    scanf("%d",&a);//temp
    printf("Tebakan : %d\n",a);
    count=count+1;
    if (a==c){
        printf ("Ya, X adalah %d.\n",c);
        play=false;
    }else if (a<c){
        printf("Lebih besar\n");
    }else if (a>c){
        printf("Lebih kecil\n");
    }
    }
    return count;
}