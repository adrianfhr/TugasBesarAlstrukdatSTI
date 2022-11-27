#include <stdio.h>
#include "map.h"
#include "arraydinmap.h"

void SCOREBOARD () {
    arraymap scoreboardlist = Makearraymap();

//tempat menyimpan semua scoreboard game
    Map ALL;
    CreateEmptyMap(&ALL);


//tempat menyimpan scoreboard game RNG
    Map RNG; 
    CreateEmptyMap(&RNG);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME RNG ****\n");
    if (IsEmptyMap(RNG)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = RNG.Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",RNG.Elements[i].Key,RNG.Elements[i].Value);
        }
    }

//tempat menyimpan scoreboard game Diner DASH
    Map DINERDASH; 
    CreateEmptyMap(&DINERDASH);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME DINER DASH ****\n");
    if (IsEmptyMap(DINERDASH)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = DINERDASH.Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",DINERDASH.Elements[i].Key,DINERDASH.Elements[i].Value);
        }
    }

//tempat menyimpan scoreboard game HANGMAN
    Map HANGMAN;
    CreateEmptyMap(&HANGMAN);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME HANGMAN ****\n");
    if (IsEmptyMap(HANGMAN)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = HANGMAN.Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",HANGMAN.Elements[i].Key,HANGMAN.Elements[i].Value);
        }
    }

// tempat menyimpan scoreboard game TOWER OF HANOI
    Map TOWEROFHANOI; 
    CreateEmptyMap(&TOWEROFHANOI);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    if (IsEmptyMap(TOWEROFHANOI)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = TOWEROFHANOI.Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",TOWEROFHANOI.Elements[i].Key,TOWEROFHANOI.Elements[i].Value);
        }
    }

//tempat menyimpan scoreboard game SNAKE ON METEOR
    Map SNAKEONMETEOR; 
    CreateEmptyMap(&SNAKEONMETEOR);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME SNAKE ON METEOR ****\n");
    if (IsEmptyMap(SNAKEONMETEOR)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = SNAKEONMETEOR.Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",SNAKEONMETEOR.Elements[i].Key,SNAKEONMETEOR.Elements[i].Value);
        }
    }

//tempat menyimpan scoreboard game Kerang Ajaib
    Map kerangajaib; 
    CreateEmptyMap(&kerangajaib);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME KERANG AJAIB ****\n");
    if (IsEmptyMap(kerangajaib)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = kerangajaib.Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",kerangajaib.Elements[i].Key,kerangajaib.Elements[i].Value);
        }
    }

InsertLastarrmap(&scoreboardlist, ALL);
InsertLastarrmap(&scoreboardlist, RNG);
InsertLastarrmap(&scoreboardlist, DINERDASH);
InsertLastarrmap(&scoreboardlist, HANGMAN);
InsertLastarrmap(&scoreboardlist, TOWEROFHANOI);
InsertLastarrmap(&scoreboardlist, SNAKEONMETEOR);
InsertLastarrmap(&scoreboardlist, kerangajaib);

}

// 1. Cara buat ALL jadi map yang berisi semua map buat di reset semua
// 2. Cara output sesuai skor terbesar
// 3. Cara connect kalau ada create game jadi tambah map baru?
// 4. Cara buat array din map nya sesuai urutan file konfigurasi? Manual?