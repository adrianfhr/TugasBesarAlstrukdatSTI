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
    
    InsertMap(&M, "Nama saya adrian", 1);
    InsertMap(&M, "Nama saya salman", 2);
    InsertMap(&M, "Nama saya yunis", 3);
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

    printf("Value dengan key 'Nama saya adrian': %d\n", ValueMap(M, "Nama saya adrian"));
    printf("Value dengan key 'Nama saya salman': %d\n", ValueMap(M, "Nama saya salman"));
    printf("Value dengan key 'Nama saya yunis': %d\n", ValueMap(M, "Nama saya yunis"));

    DeleteMap(&M, "Nama saya salman");
    if(IsMemberMap(M, "Nama saya salman")){
        printf("Key Nama saya salman masih ada\n");
    }else{
        printf("Key Nama saya salman sudah tidak ada\n");
    }
}