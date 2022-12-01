#include <stdio.h>
#include "map.h"
#include "arraydinmap.h"

void RESETSCOREBOARD(){

    printf("\nDAFTAR SCOREBOARD:\n"); 
    printf("0. ALL\n");
    for(int i = 0; i < Length(ListGame); i++){
        printf("%d. %s\n", i+1, ListGame.A[i]);
    }

    printf("Masukkan nomor game yang ingin direset: ");
    STARTWORD();
    char*reset = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, reset);
    int resetgame = atoi(reset);
    if(resetgame == 0){
        printf("\n\nAPAKAH ANDA YAKIN INGIN MERESET SEMUA SCOREBOARD? (YA/TIDAK)\n");
    }else if(resetgame > 0 && resetgame <= Length(ListGame)){
        printf("\n\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD GAME %s ? (YA/TIDAK)\n", ListGame.A[resetgame-1]);
    }else{
        printf("Nomor game tidak valid\n");
    }

    if(resetgame >= 0 && resetgame <= Length(ListGame)){
        STARTWORD();
        char *answer = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, answer);
        if(stringcompare(answer, "YA")){
            if(resetgame == 0){
                for(int i = 0; i < Lengtharrmap(scoreboardlist); i++){
                    scoreboardlist.A[i].Count = 0;
                }
            }else if(resetgame > 0 && resetgame <= Lengtharrmap(scoreboardlist)){
                scoreboardlist.A[resetgame-1].Count = 0;
            }
        }else if(stringcompare(answer, "TIDAK")){
            printf("Reset scoreboard dibatalkan\n");
        }else{
            printf("Input tidak valid\n");
        }
    }
}