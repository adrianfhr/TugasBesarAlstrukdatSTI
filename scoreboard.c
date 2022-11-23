#include <stdio.h>
#include "map.h"

void SCOREBOARD (){
    // cara buat tiap game memiliki masing"  map?
    // inputan nama dan skor berasal dari game nya masing"?
    // skor diurutkan berdasarkan tertinggi

    Map BOARD; //tempat menyimpan scoreboard game
    CreateEmptyMap(&BOARD);
    keytype game; //nama game sebagai key
    ElType SKORGAME; //map skorgame sebagai element

    Map SKORGAME; //tempat menyimpan nama dan skor dari masing masing game
    CreateEmptyMap(&SKORGAME); // membuat map kosong
    keytype nama; //nama sebagai key
    ElType skor; // skor sebagai element
    
    if (!(IsMemberMap(SKORGAME, nama))){ // jika nama belum terpakai maka nama valid
        InsertMap (*SKORGAME, nama, skor); // memasukan nama dan skor baru pada map SKORGAME
    }

    for (int i = 0; i<Length(ListGame); i++){ //output urutan scoreboard berdasarkan ListGame
        printf("**** SCOREBOARD GAME %s ****\n", ListGame.A[i]);
        printf("| NAMA          | SKOR          |\n");
        printf("|---------------|---------------|\n");
        printf("|               |               |\n");
        printf("\n");
    }
}