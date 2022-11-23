#include <stdio.h>
#include "map.h"
#include "arraydin.h"
// perlu buat list scoreboard pke arraydin ga?

void RESETSCOREBOARD (){

    printf("DAFTAR SCOREBOARD:\n"); //output daftar scoreboard yg tersedia
    printf ("0. ALL\n");
    printf ("1. RNG\n");
    printf ("2. Diner DASH\n");
    printf ("3. HANGMAN\n");
    printf ("4. TOWER OF HANOI\n");
    printf ("5. SNAKE ON METEOR\n");
    // kerang ajaib tidak ada scoreboard (?)

    int x; 
    printf ("SCOREBOARD YANG INGIN DIHAPUS: "); // input scoreboard yg ingin dihapus
    scanf ("%d\n",&x);

    char game; //tempat menyimpan nama game untuk menghapus key pada map board
    char temp; //tempat menyimpan nama game untuk print konfirmasi
    if (x == 0){
        game == "ALL";
        temp == "ALL";
    }
    else if (x == 1){
        game == "RNG";
        temp == "RNG";
    }
    else if (x == 2){
        game == "DINERDASH";
        temp == "DINER DASH";
    }
    else if (x == 3){
        game == "HANGMAN";
        temp == "HANGMAN";
    }
    else if (x == 4){
        game == "TOWEROFHANOI";
        temp == "TOWER OF HANOI";
    }
    else if (x == 5){
        game == "SNAKEONMETEOR";
        temp == "SNAKE ON METEOR";
    }

    char y;
    printf ("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %c (YA/TIDAK)? ",temp);
    scanf ("%c\n",&y);

    if (y == "YA"){
        if (game == "ALL"){ // menghapus semua element pada map board
            DeleteMap (*BOARD, RNG);
            DeleteMap (*BOARD, DinerDASH);
            DeleteMap (*BOARD, HANGMAN);
            DeleteMap (*BOARD, TOWEROFHANOI);
            DeleteMap (*BOARD, SNAKEONMETEOR);
            printf("Scoreboard berhasil di-reset.");
        }
        else{ //menghapus elemen pada map board sesuai nama game yang ingin direset
            DeleteMap (*BOARD, game);
            printf("Scoreboard berhasil di-reset.");
        }
        
    }
    else{ //tidak jadi reset scoreboard
        printf("Scoreboard tidak berhasil di-reset.");
    }
}

//GABISA:
// kalau deletemap tuh key nya tetap ada kan? cuma elemen nya jadi kosong?
// perlu buat listscoreboard ga atau manual kayak diatas aja?
// kerang ajaib tidak perlu masuk ke dalam daftar scoreboard kan?
