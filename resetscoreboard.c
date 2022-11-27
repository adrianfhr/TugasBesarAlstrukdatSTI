#include <stdio.h>
#include "map.h"
#include "arraydinmap.h"

void RESETSCOREBOARD (){

    printf("DAFTAR SCOREBOARD:\n"); 
    for (int i = 0; i<Lengtharrmap(scoreboardlist);i++){
        printf("%d. %s\n",i ,scoreboardlist.A[i]);
    }

    int reset;
    printf ("SCOREBOARD YANG INGIN DIHAPUS: "); 
    scanf("%d\n",&reset);
    char confirm;
    printf ("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ",scoreboardlist.A[reset]);
    scanf ("%c\n",&confirm);
    if (reset < Lengtharrmap(scoreboardlist) && confirm == "YA"){
        arr.A[reset] = Nil; 
        printf("Scoreboard berhasil di-reset.");
    }
    else{ //tidak jadi reset scoreboard
        printf("Scoreboard tidak berhasil di-reset.");
    }
   
}

// 1. bener ga cara reset nya?