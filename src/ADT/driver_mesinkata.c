#include "mesinkata.c"
#include "mesinkar.c"
#include "stdlib.h"
#include "stdio.h"

int main(){
    printf("Masukkan kata yang diakhiri dengan titik\n");
    STARTWORD();
    while (!EndWord){
        int i = 0;
        
        while(i < currentWord.Length){
            printf("%c", currentWord.TabWord[i]);
            i++;
        }
        printf(" ");

        ADVWORD();
    }
    printf("\nprogram berhenti\n");

    char *filename = "drivertest.txt";
    STARTREADGAME(filename);
    char * input = (char *) malloc(100 * sizeof(char));
    KataToString(currentWord, input);
    while(!EndWord){
        printf("%s\n", input);
        ADVREADGAME();
        KataToString(currentWord, input);
    }
    
    
    char *COMPARE = "KARAKTER SATU";
    if(stringcompare(COMPARE, "KARAKTER SATU") == 1){
            printf("fungsi stringcompare berhasil dijalankan\n");
    }else{
            printf("masukan input yang tepat\n");
    }
    char concatkata1[10] = "SATU";
    char concatkata2[] = " DUA";
    printf("Kata 1 sebelum di concat: %s\n", concatkata1);
    printf("Kata 2 sebelum di concat: %s\n", concatkata2);
    concat(concatkata1, concatkata2);
    printf("Kata setelah di concat : %s\n", concatkata1);
    if(stringcompare(concatkata1, "SATU DUA") == 1){
            printf("fungsi concat berhasil dijalankan\n");
    }

    return 0;
}