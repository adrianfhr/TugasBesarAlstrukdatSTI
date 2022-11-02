#include "command.h"
#include "mesinkata.c"
#include "arraydin.c"

ArrayDin ListGame ;
void STARTBNMO(){
    system("cls");
    printf("Welcome to BNMO!\n");
    char *file = "default.txt";
    STARTWORD(file);
    ListGame = MakeArrayDin();
    ListGame.Neff = currentWord.TabWord[0] - 48;
    for(int i = 0; i <= ListGame.Neff; i++){
        int j = 0;
        printf("INI SATU : %s\n", currentWord.TabWord);
        ADVWORD();
        printf("INI DUA : %s\n", currentWord.TabWord);
        while(currentWord.TabWord[j] != '\n'){
            ListGame.A[i] = currentWord.TabWord;
            j++;
        }
    }
    
    for(int i = 0; i <= ListGame.Neff; i++){
        printf("INI GAME %s\n", ListGame.A[i]);
    }

}

void LOAD();

void SAVE();

void CREATEGAME();

void LISTGAME();

void DELETEGAME();

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP();

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}