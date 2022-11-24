#include "stack.c"
#include <stdio.h>

int main(){
    Stack S;
    CreateEmptyStack(&S);
    if (IsEmptyStack(S))
    {
        printf("Stack kosong\n");
    }
    else{
        printf("Stack tidak kosong\n");
    }
    if (IsFullStack(S))
    {
        printf("Stack penuh\n");
    }
    else{
        printf("Stack tidak penuh\n");
    }
    ElType X;
    PushStack(&S, "nora");
    printf("%s\n", InfoTop(S));
    PopStack(&S, &X);
    printf("%s\n", X); 
}