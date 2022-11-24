#include <stdio.h>
#include "map.h"
#include "arraydin.h"

void RESETSCOREBOARD (){
// daftar scoreboard pakai array din
    printf("DAFTAR SCOREBOARD:\n"); 
    printf ("0. ALL\n"); //array
    printf ("1. RNG\n");
    printf ("2. Diner DASH\n");
    printf ("3. HANGMAN\n");
    printf ("4. TOWER OF HANOI\n");
    printf ("5. SNAKE ON METEOR\n");
    // kerang ajaib tidak ada scoreboard

    int x; 
    printf ("SCOREBOARD YANG INGIN DIHAPUS: "); // input scoreboard yg ingin dihapus
    scanf ("%d\n",&x);
    
    char temp; //tempat menyimpan nama game untuk print konfirmasi
    if (x == 0){
        temp == "ALL";
    }
    else if (x == 1){
        temp == "RNG";
    }
    else if (x == 2){
        temp == "DINER DASH";
    }
    else if (x == 3){
        temp == "HANGMAN";
    }
    else if (x == 4){
        temp == "TOWER OF HANOI";
    }
    else if (x == 5){
        temp == "SNAKE ON METEOR";
    }

    char y;
    printf ("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %c (YA/TIDAK)? ",temp);
    scanf ("%c\n",&y);
    if (y == "YA")
    {
        if (x == 0){
            // array [i].Count = Nil, kosonginnya di cari dari arraynya dlu
            RNGSCORE->Count = Nil; //bener ga cara ngosongin map nya gini?
            DINERDASHSCORE->Count = Nil;
            HANGMANSCORE->Count = Nil;
            TOWEROFHANOISCORE->Count = Nil;
            SNAKEONMETEORSCORE->Count = Nil;
            printf("Scoreboard berhasil di-reset.");
        }
        else if (x == 1){
            RNGSCORE->Count = Nil;
            printf("Scoreboard berhasil di-reset.");
        }
        else if (x == 2){
            DINERDASHSCORE->Count = Nil;
            printf("Scoreboard berhasil di-reset.");
        }
        else if (x == 3){
            HANGMANSCORE->Count = Nil;
            printf("Scoreboard berhasil di-reset.");
        }
        else if (x == 4){
            TOWEROFHANOISCORE->Count = Nil;
            printf("Scoreboard berhasil di-reset.");
        }
        else if (x == 5){
            SNAKEONMETEORSCORE->Count = Nil;
            printf("Scoreboard berhasil di-reset.");
        }
    }
    else{ //tidak jadi reset scoreboard
        printf("Scoreboard tidak berhasil di-reset.");
    }
}