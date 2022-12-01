#include "towerofhanoi.h"
#include "../../ADT/STACK/stack.h"
#include "../../ADT/MESINKATA/mesinkata.h"
#include "../../ADT/MESINKATA/mesinkar.h"


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
    ElTypestack val;
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

int towerofhanoimain(){
    Stack S1, S2, S3, SMenang;
    ElTypestack val;
    int score ;
    int countsteps = 0;
    int i = 1;
    int jumlah, akhir;
    char a;
    char input[5];
    boolean start=true;
    boolean valid=false;
    CreateEmptyStack(&S1);
    CreateEmptyStack(&S2);
    CreateEmptyStack(&S3);
    CreateEmptyStack(&SMenang);

    while(!valid){
    printf("Pilih jumlah piringan :\n");
    printf("Max : 5 || Min : 2\n");
    printf("Jumlah : ");
    STARTWORD();
    KataToString(currentWord, input);
    if(stringcompare(input,"4")){
    a=input[0];
    sscanf(&a,"%d",&jumlah);
    }
    if(jumlah>=2 && jumlah<=5){
    for(i=jumlah;i>0;i--){
        PushStack(&S1,(i*2)-1);
        PushStack(&SMenang,(i*2)-1);
    }
    valid=true;
    }
    }
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
        else
        {
            printf("Input invalid\n");
        }
    printf("\n\n");
    if (IsSameStack(S3, SMenang))
    {
        start = false;
    }
    }
    PrintHanoi(S1, S2, S3);
    printf("Selamat! Kamu berhasil!\n\n");
    printf("Jumlah langkahmu: %d\n", countsteps);
    score = jumlah*2;
    jumlah=jumlah*6+1;
    if(jumlah>countsteps){

    }else{
        akhir=countsteps-jumlah;
        for(i=0;i<akhir;i+=1){
            score-=1;
        }
    }
    if (score<=0)
    {
        score=1;
    }
    printf("Skor yang kamu dapatkan: %d\n", score);
    return score;
}
    

