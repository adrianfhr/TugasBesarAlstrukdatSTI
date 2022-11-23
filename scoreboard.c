#include <stdio.h>
#include "map.h"

void SCOREBOARD (){
    // inputan nama dan skor berasal dari game nya masing"?
    // buat file konfigurasi baru (?)
    // skor diurutkan berdasarkan tertinggi

    Map TOWEROFHANOISCORE; //tempat menyimpan scoreboard game TOWER OF HANOI
    CreateEmptyMap(&TOWEROFHANOISCORE);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME TOWER OF HANOI ****\n");
    if (IsEmptyMap(TOWEROFHANOISCORE)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = TOWEROFHANOISCORE->Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",TOWEROFHANOISCORE.Elements[i].Key,TOWEROFHANOISCORE.Elements[i].Value);
        }
    }

    Map DINERDASHSCORE; //tempat menyimpan scoreboard game Diner DASH
    CreateEmptyMap(&DINERDASHSCORE);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME DINER DASH ****\n");
    if (IsEmptyMap(DINERDASHSCORE)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = DINERDASHSCORE->Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",DINERDASHSCORE.Elements[i].Key,DINERDASHSCORE.Elements[i].Value);
        }
    }

    Map SNAKEONMETEORSCORE; //tempat menyimpan scoreboard game SNAKE ON METEOR
    CreateEmptyMap(&SNAKEONMETEORSCORE);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME SNAKE ON METEOR ****\n");
    if (IsEmptyMap(SNAKEONMETEORSCORE)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = SNAKEONMETEORSCORE->Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",SNAKEONMETEORSCORE.Elements[i].Key,SNAKEONMETEORSCORE.Elements[i].Value);
        }
    }


    Map RNGSCORE; //tempat menyimpan scoreboard game RNG
    CreateEmptyMap(&RNGSCORE);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME RNG ****\n");
    if (IsEmptyMap(RNGSCORE)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = RNGSCORE->Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",RNGSCORE.Elements[i].Key,RNGSCORE.Elements[i].Value);
        }
    }

    Map HANGMANSCORE; //tempat menyimpan scoreboard game HANGMAN
    CreateEmptyMap(&HANGMANSCORE);
    // keytype: nama orang
    // ElType: skor game
    printf("**** SCOREBOARD GAME HANGMAN ****\n");
    if (IsEmptyMap(HANGMANSCORE)){
        printf("| NAMA          | SKOR          |\n");
        printf("------- SCOREBOARD KOSONG -------\n");
    }
    else{ //masih print sesuai urutan map belum berdasarkan skor tertinggi
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        int count;
        count = HANGMANSCORE->Count
        int i;
        for (i=0;i<count;i++){
            printf("|%c             | %d             |\n",HANGMANSCORE.Elements[i].Key,HANGMANSCORE.Elements[i].Value);
        }
    }

//bagian ini harusnya di masing-masing game kan?
    char nama;
    printf("Nama: ");
    scanf("%c",&nama);
    if (!(IsMemberMap(TOWEROFHANOISCORE, nama))){ // jika nama belum terpakai maka nama valid
        InsertMap (*TOWEROFHANOISCORE, nama, skor); // memasukan nama dan skor baru pada map
    }
    else{
        printf("Nama sudah terpakai di scoreboard.");
    }

}