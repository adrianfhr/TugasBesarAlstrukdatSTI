#include "intmap.c"
#include "stdio.h"

int main(){
    intMap M;
    CreateEmptyintMap(&M);
    if(IsEmptyintMap)
    {
        printf("Map kosong\n");
    }
    else
    {
        printf("Map tidak kosong\n");
    }
    
    InsertintMap(&M, 1, "Nama saya adrian");
    InsertintMap(&M, 2, "Nama saya salman");
    InsertintMap(&M, 3, "Nama saya yunis");
    if(IsEmptyintMap(M)){
        printf("Map kosong\n");
    }else{
        printf("Map tidak kosong\n");
    }

    if(IsFullintMap(M)){
        printf("Map penuh\n");
    }else{
        printf("Map tidak penuh\n");
    }

    printf("Value dengan key 1: %s\n", ValueintMap(M, 1));
    printf("Value dengan key 2: %s\n", ValueintMap(M, 2));
    printf("Value dengan key 3: %s\n", ValueintMap(M, 3));

    DeleteintMap(&M, 2);
    if(IsMemberintMap(M, 2)){
        printf("Key 2 masih ada\n");
    }else{
        printf("Key 2 sudah tidak ada\n");
    }
}