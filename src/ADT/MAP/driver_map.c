#include "map.c"
#include "stdio.h"

int main(){
    Map M;
    CreateEmptyMap(&M);
    if(IsEmptyMap)
    {
        printf("Map kosong\n");
    }
    else
    {
        printf("Map tidak kosong\n");
    }
    
    InsertMap(&M, 1, "Nama saya adrian");
    InsertMap(&M, 2, "Nama saya salman");
    InsertMap(&M, 3, "Nama saya yunis");
    if(IsEmptyMap(M)){
        printf("Map kosong\n");
    }else{
        printf("Map tidak kosong\n");
    }

    if(IsFullMap(M)){
        printf("Map penuh\n");
    }else{
        printf("Map tidak penuh\n");
    }

    printf("Value dengan key 1: %s\n", ValueMap(M, 1));
    printf("Value dengan key 2: %s\n", ValueMap(M, 2));
    printf("Value dengan key 3: %s\n", ValueMap(M, 3));

    DeleteMap(&M, 2);
    if(IsMemberMap(M, 2)){
        printf("Key 2 masih ada\n");
    }else{
        printf("Key 2 sudah tidak ada\n");
    }
}