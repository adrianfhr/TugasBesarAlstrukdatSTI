//#include "towerofhanoi.h"
#include "../../ADT/STACK/stack.c"
#include "../../ADT/MESINKATA/mesinkata.c"
#include "../../ADT/MESINKATA/mesinkar.c"


boolean listcompare(char* S1, char* S2){
    boolean found = true;
    int m = 0;
    while(S1[m] != '\0' && S2[m] != '\0' && found)
    {
        if (S1[m] != S2[m])
        {
            found = false;
        }else{
            m++;
        }
    }
    return found;
}

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

int main()
{
    Stack S1, S2, S3, Sbaru, SMenang;
    ElType val;
    int score = 1;
    int countsteps = 0;
    boolean start=true;
    CreateEmptyStack(&S1);
    CreateEmptyStack(&S2);
    CreateEmptyStack(&S3);
    CreateEmptyStack(&SMenang);

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
    PushStack(&SMenang,9);
    PushStack(&SMenang,7);
    PushStack(&SMenang,5);
    PushStack(&SMenang,3);
    PushStack(&SMenang,1);

    while (start) 
    {
        PrintHanoi(S1, S2, S3);
        char tiangasal[5];
        char tiangtujuan[5];
        printf("Tiang asal: ");
             STARTWORD();
        KataToString(currentWord, tiangasal);
        printf("Tiang tujuan: ");
        STARTWORD();
        KataToString(currentWord, tiangtujuan);

        if ((listcompare(tiangasal, "a") || listcompare(tiangasal, "A")) && stringcompare(tiangasal,"t")){
            if (IsEmptyStack(S1)){
                printf("Input invalid\n");
            }
            else if ((listcompare(tiangtujuan, "b") || listcompare(tiangtujuan, "B")) && stringcompare(tiangtujuan,"t")){
                if (IsEmptyStack(S2)){
                    PopStack(&S1,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                    countsteps += 1;
                }
                else if (InfoTop(S2)<InfoTop(S1)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S1,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                    countsteps += 1;
                }
            }
            else if ((listcompare(tiangtujuan, "c") || listcompare(tiangtujuan, "C")) && stringcompare(tiangtujuan,"t")){
                if (IsEmptyStack(S3)){
                    PopStack(&S1,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                    countsteps += 1;
                }
                else if (InfoTop(S3)<InfoTop(S1)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S1,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                    countsteps += 1;
                }
            }
            else
            {
                printf("Input invalid\n");
            } 
        }
        else if ((listcompare(tiangasal, "b") || listcompare(tiangasal, "B")) && stringcompare(tiangasal,"t")){
            if (IsEmptyStack(S2)){
                printf("Input invalid\n");
            }
            else if ((listcompare(tiangtujuan, "a") || listcompare(tiangtujuan, "A")) && stringcompare(tiangtujuan,"t")){
                if (IsEmptyStack(S1)){
                    PopStack(&S2,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                    countsteps += 1;
                }
                else if (InfoTop(S1)<InfoTop(S2)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S2,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                    countsteps += 1;
                }
            }
            else if ((listcompare(tiangtujuan, "c") || listcompare(tiangtujuan, "C")) && stringcompare(tiangtujuan,"t")){
                if (IsEmptyStack(S3)){
                    PopStack(&S2,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                    countsteps += 1;
                }
                else if (InfoTop(S3)<InfoTop(S2)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S2,&val);
                    PushStack(&S3,val);
                    printf("\nMemindahkan piringan ke C...\n");
                    countsteps += 1;
                }
            }
            else
            {
                printf("Input invalid\n");
            } 
        }
        else if ((listcompare(tiangasal, "c") || listcompare(tiangasal, "C")) && stringcompare(tiangasal,"t")){
            if (IsEmptyStack(S3)){
                printf("Input invalid\n");
            }
            else if ((listcompare(tiangtujuan, "a") || listcompare(tiangtujuan, "A")) && stringcompare(tiangtujuan,"t")){
                if (IsEmptyStack(S1)){
                    PopStack(&S3,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                    countsteps += 1;
                }
                else if (InfoTop(S1)<InfoTop(S3)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S3,&val);
                    PushStack(&S1,val);
                    printf("\nMemindahkan piringan ke A...\n");
                    countsteps += 1;
                }
            }
            else if ((listcompare(tiangtujuan, "b") || listcompare(tiangtujuan, "B")) && stringcompare(tiangtujuan,"t")){
                if (IsEmptyStack(S2)){
                    PopStack(&S3,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                    countsteps += 1;
                }
                else if (InfoTop(S2)<InfoTop(S3)){
                    printf("Input invalid\n");
                }
                else{
                    PopStack(&S3,&val);
                    PushStack(&S2,val);
                    printf("\nMemindahkan piringan ke B...\n");
                    countsteps += 1;
                }
            }
            else
            {
                printf("Input invalid\n");
            }
        }
    printf("\n\n");
    if (IsSameStack(S3, SMenang))
    {
        start = false;
    }
    }
    printf("Selamat! Kamu berhasil!\n\n");
    printf("Jumlah langkahmu: %d\n", countsteps);
    if (countsteps <= 31)
    {
        score = 10;
    }
    if (countsteps == 32)
    {
        score = 9;
    }
    if (countsteps == 33)
    {
        score = 8;
    }
    if (countsteps == 34)
    {
        score = 7;
    }
    if (countsteps == 35)
    {
        score = 6;
    }
    if (countsteps == 36)
    {
        score = 5;
    }
    if (countsteps == 37)
    {
        score = 4;
    }
    if (countsteps == 38)
    {
        score = 3;
    }
    if (countsteps == 39)
    {
        score = 2;
    }
    if (countsteps >= 40)
    {
        score = 1;
    }

    printf("Skor yang kamu dapatkan: %d\n", score);
    return 0;
}
    

