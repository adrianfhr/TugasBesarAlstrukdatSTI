#include"arraydin.c"
#include<stdio.h>

int main(){
    ArrayDin array;
    array=MakeArrayDin();
    ArrayMap map;
    map=MakeArrayMap();
    if (IsEmpty(array)){
        printf("panjang = %d\n",Length(array));
        printf("kapasitas = %d\n",GetCapacity(array));
        InsertAt(&array,"t",5);
        printf("panjang = %d\n",Length(array));
        if (IsEmpty(array)){
            DeleteAt(&array,5);
            DeallocateArrayDin(&array);
        }
    }else{
        printf("array tidak kosong\n");
    }
    return 0;
}