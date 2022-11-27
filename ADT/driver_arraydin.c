#include"arraydinmap.c"
#include"../MAP/map.c"
#include<stdio.h>
int main(){
    arraymap arr = Makearraymap();
    TypeMap m;
    CreateEmptyMap(&m);
    if(IsEmptyarrmap(arr)){
        printf("ARRMap kosong\n");
    }
    else{
        printf("ARRMap tidak kosong\n");
    }

    InsertLastarrmap(&arr, m);

    if(IsEmptyarrmap(arr)){
        printf("ARRMap kosong\n");
    }
    else{
        printf("ARRMap tidak kosong\n");
    }

    if(IsEmptyMap(arr.A[0])){
        printf("Map kosong\n");
    }
    else{
        printf("Map tidak kosong\n");
    }

    InsertMap(&arr.A[0], 1, "A");
    InsertMap(&arr.A[0], 2, "B");
    InsertMap(&arr.A[0], 3, "C");

    if(IsEmptyMap(arr.A[0])){
        printf("Map kosong\n");
    }
    else{
        printf("Map tidak kosong\n");
    }
    
    for(int i=0; i<arr.A[0].Count; i++){
        printf("KEY (%d) ISI : %s\n", arr.A[0].Elements[i].Key, arr.A[0].Elements[i].Value);
    }
    

    return 0;
}   