#include "command.h"
#include "../ADT/arraydin.h"
#include "../ADT/mesinkata.h"
#include "../ADT/queue.h"

FILE *file = NULL;
ArrayDin ListGame;

void STARTBNMO(){
    printf("Welcome to BNMO!\n");
    char *file = "..\\data\\default.txt";
    STARTREADGAME(file);
    ListGame = MakeArrayDin();
    int jumlahgame = currentWord.TabWord[0] - 48;
    ADVREADGAME();
    for(int i = 0; i < jumlahgame; i++)
    {
        char *game = (char*) malloc(currentWord.Length * sizeof(ElType));
        KataToString(currentWord, game);
        InsertKataLast(&ListGame, game);
        ADVREADGAME();
    }
    for(int i = 0; i < Length(ListGame); i++)
    {
        printf("%s\n", ListGame.A[i]);
    }
  
    scanf("TESSS : %d", jumlahgame);
}

void LOADBNMO(){}

void SAVE(){}

void CREATEGAME(){}

void LISTGAME(){}

void DELETEGAME(){}

void QUEUEGAME(){}

void PLAYGAME(){}

void SKIPGAME(){}

void QUIT(){}

void HELP(){}

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}