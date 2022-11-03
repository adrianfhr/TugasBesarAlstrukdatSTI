#include "command.h"
#include "ADT/array.c"
#include "ADT/mesinkata.c"

FILE *file = NULL;

void START(){
    file = "..//player//default.txt";
    STARTWORD();
    for(int i = 0; i < currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }

}

void LOADBNMO();

void SAVE();

void CREATEGAME(){
    ArrayDin *ListGame; 
    ElType gamebaru;
    InsertAt(ListGame, gamebaru, ListGame->Neff);
}

void LISTGAME(){
    for(int i = 0; i < Length(ListGame); i++)
        {
            printf("%s\n", ListGame.A[i]);
        }
}

void DELETEGAME();

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP(){
    printf("1. START        <Menjalankan BNMO> \n");
    printf("2. LOAD         <Membaca savefile> \n");
    printf("3. SAVE         <Menyimpan state game pemain saat ini ke dalam file> \n");
    printf("4. CREATEGAME   <Menambah game baru pada daftar game> \n");
    printf("5. LISTGAME     <Menampilkan daftar game> \n");
    printf("6. DELETEGAME   <Menghapus suatu game dari daftar game> \n");
    printf("7. QUEUEGAME    <Mendaftarkan permainan kedalam daftar antrian game> \n");
    printf("8. PLAYGAME     <Memainkan sebuah permainan> \n");
    printf("9. SKIPGAME     <Melewatkan permainan> \n");
    printf("10. QUIT        <Keluar dari program> \n");
    printf("11. HELP        <Bantuan command-command> \n");
}

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}