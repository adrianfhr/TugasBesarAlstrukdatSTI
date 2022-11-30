#include <stdio.h>
#include "stack.h"

void HISTORY(Stack *HISTORY, int n){
    system("cls");
    if(isEmpty(*HISTORY)){
        printf("Kamu belum memiliki history game\n");
    }
    else
    {
        printf("Berikut adalah daftar Game yang telah dimainkan: \n");
        for(int i = HISTORY->idxTop; i >= 0; i--){
            printf("%d. %s\n", i+1, HISTORY->buffer[i]);
        }
    }
}