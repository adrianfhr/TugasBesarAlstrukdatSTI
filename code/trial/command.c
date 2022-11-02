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
    int jumlahgame = currentWord.TabWord[0] - 48;
    ADVWORD();
    for(int i = 0; i < jumlahgame; i++)
    {
        char *game = (char*) malloc(currentWord.Length * sizeof(ElType));
        KataToString(currentWord, game);
        InsertKataLast(&ListGame, game);
        ADVWORD();
    }

    for(int i = 0; i < ListGame.Neff; i++)
    {
        printf("Game %d : %s\n",i, ListGame.A[i]);
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

