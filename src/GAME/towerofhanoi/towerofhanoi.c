//#include "towerofhanoi.h"
#include "../../ADT/STACK/stack.c"

void Tower(Stack *S){
    ElType val;
    Stack stemp;
    CreateEmptyStack(&stemp);
    while (!IsEmptyStack(*S)){
        PopStack(S,&val);
        PushStack(&stemp, val);
        if (val==9){
            printf("*********\n");
        }
        else if (val == 7){
            printf(" ******* \n");
        }
        else if (val == 5){
            printf("  *****  \n");
        }
        else if (val == 3){
            printf("   ***   \n");
        }
        else if (val == 1){
            printf("    *    \n");
        }
        else{
            printf("    |    \n");
        }
    }
    while (!IsEmptyStack(stemp)){
        PopStack(&stemp,&val);
        PushStack(S,val);
    }
}

void BintangHanoi(Stack *S, int i){
    if (i <= Top(*S)){
        if (S->T[i] == 9)
        {
            printf("*********", S->T[i]);
        }
        else if (S->T[i] == 7)
        {
            printf(" ******* ", S->T[i]);
        }
        else if (S->T[i] == 5)
        {
            printf("  *****  ", S->T[i]);
        }
        else if (S->T[i] == 3)
        {
            printf("   ***   ", S->T[i]);
        }
        else if (S->T[i] == 1)
        {
            printf("    *    ", S->T[i]);
        }
    }
    else
    {
        printf("    |    ");
    }
}

void PrintHanoi(Stack S1, Stack S2, Stack S3){
    int i;
    for (i = 4; i >= 0; i--)
    {
        BintangHanoi(&S1, i);
        printf("                ");
        BintangHanoi(&S2, i);
        printf("                ");
        BintangHanoi(&S3, i);
        printf("\n");
    }
    printf(" ------- ");
    printf("              ");
    printf("     ---   ");
    printf("              ");
    printf("     ---   ");
    printf("              ");
    printf("\n");
    printf("    A    ");
    printf("              ");
    printf("      B    ");
    printf("              ");
    printf("      C    ");
    printf("              ");
    printf("\n");
} 

int main(){
    Stack S1, S2, S3, Sbaru;
    ElType val;
    boolean start=true;
    CreateEmptyStack(&S1);
    CreateEmptyStack(&S2);
    CreateEmptyStack(&S3);

    PushStack(&S1,9);
    PushStack(&S1,7);
    PushStack(&S1,5);
    PushStack(&S1,3);
    PushStack(&S1,1);
    PushStack(&Sbaru,9);
    PushStack(&Sbaru,7);
    PushStack(&Sbaru,5);
    PushStack(&Sbaru,3);
    PushStack(&Sbaru,1);

    while (start) {
        PrintHanoi(S1, S2, S3);
        char tiangasal[5];
        char tiangtujuan[5];
        printf("Tiang asal: ");
        scanf("%s",tiangasal);
        printf("Tiang tujuan: ");
        scanf("%s",tiangtujuan);

        if (tiangasal[0]=='A'){
            if (IsEmptyStack(S1)){
                printf("Input invalid\n");
            }
            else if (tiangtujuan[0]=='B'){
                if (IsEmptyStack(S2)){
                    PopStack(&S1,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                }
                else if (InfoTop(S2)<InfoTop(S1)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S1,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                }
            }
            else if (tiangtujuan[0]=='C'){
                if (IsEmptyStack(S3)){
                    PopStack(&S1,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                }
                else if (InfoTop(S3)<InfoTop(S1)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S1,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                }
            }
            else
            {
                printf("Input invalid\n");
            } 
        }
        else if (tiangasal[0]=='B'){
            if (IsEmptyStack(S2)){
                printf("Input invalid\n");
            }
            else if (tiangtujuan[0]=='A'){
                if (IsEmptyStack(S1)){
                    PopStack(&S2,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                }
                else if (InfoTop(S1)<InfoTop(S2)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S2,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                }
            }
            else if (tiangtujuan[0]=='C'){
                if (IsEmptyStack(S3)){
                    PopStack(&S2,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                }
                else if (InfoTop(S3)<InfoTop(S2)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S2,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                }
            }
            else
            {
                printf("Input invalid\n");
            } 
        }
        else if (tiangasal[0]=='C'){
            if (IsEmptyStack(S3)){
                printf("Input invalid\n");
            }
            else if (tiangtujuan[0]=='A'){
                if (IsEmptyStack(S1)){
                    PopStack(&S3,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                }
                else if (InfoTop(S1)<InfoTop(S3)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S3,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                }
            }
            else if (tiangtujuan[0]=='B'){
                if (IsEmptyStack(S2)){
                    PopStack(&S3,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                }
                else if (InfoTop(S2)<InfoTop(S3)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S3,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                }
            }
            else
            {
                printf("Input invalid\n");
            }
            if (IsSameStack(S3, Sbaru))
            {
                start = false;
                printf("Selamat! Kamu berhasil!\n");
            }
        } 
    printf("\n\n");
    }
    return 0;
}
    

