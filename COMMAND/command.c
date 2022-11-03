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

void LOAD();

void SAVE();

void CREATEGAME(ArrayDin *ListGame, ElType gamebaru){
    InsertAt(ListGame, gamebaru, ListGame->Neff);
}

void LISTGAME();

void DELETEGAME();

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP(){
    printf("Command yang tersedia: /n");
    printf("1. START/n");
    printf("2. LOAD/n");
    printf("3. SAVE/n");
    printf("4. CREATEGAME/n");
    printf("5. LISTGAME/n");
    printf("6. DELETEGAME/n");
    printf("7. QUEUEGAME/n");
    printf("8. PLAYGAME/n");
    printf("9. SKIPGAME/n");
    printf("10. QUIT/n");
    printf("11. HELP/n");
}

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}