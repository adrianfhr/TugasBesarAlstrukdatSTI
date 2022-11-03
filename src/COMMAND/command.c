#include "command.h"
#include "string.h"
#include "../ADT/arraydin.h"
#include "../ADT/mesinkata.h"
#include "../ADT/queue.h"

FILE *file = NULL;
ArrayDin ListGame;
int command = 9999;

void mainmenu(){
        printf("Welcome to BNMO!\n");
        printf("================\n");
        printf("Choose your command:\n");
        printf("1. START\n");
        printf("2. LOAD\n");
        printf("Example Command: START\n");
        printf(">> ");
}

void commandmenu(){
        printf("\n");
        printf("Welcome to BNMO!\n");
        printf("Choose your command:\n");
        printf("1. CREATE\n");
        printf("2. LISTGAME\n");
        printf("3. DELETE\n");
        printf("4. QUEUE\n");
        printf("5. PLAY\n");
        printf("6. SKIP\n");
        printf("7. SAVE\n");
        printf("8. QUIT\n");
        printf("9. HELP\n");
        printf("Example Command: CREATE\n");
        printf(">> ");
}

void commandconfig(){
        commandmenu();
                STARTWORD();
                char *userCommand = (char*) malloc (currentWord.Length+1);
                KataToString(currentWord, userCommand);
                if(strcmp(userCommand, "CREATE") == 0)
                {
                    CREATEGAME();
                }
                else if(strcmp(userCommand, "LISTGAME") == 0)
                {
                    LISTGAME();
                }
                else if(strcmp(userCommand, "DELETE") == 0)
                {
                    DELETEGAME();
                }
                else if(strcmp(userCommand, "QUEUE") == 0)
                {
                    QUEUEGAME();
                }
                else if(strcmp(userCommand, "PLAY") == 0)
                {
                    PLAYGAME();
                }
                else if(strcmp(userCommand, "SKIP") == 0)
                {
                    SKIPGAME();
                }
                else if(strcmp(userCommand, "SAVE") == 0)
                {
                    SAVE();
                }
                else if(strcmp(userCommand, "QUIT") == 0)
                {
                    QUIT();
                }
                else if(strcmp(userCommand, "HELP") == 0)
                {
                    HELP();
                }
                else
                {
                    COMMANDLAIN();
                }
}

void STARTBNMO(){
    system("cls");
    printf("START GAME!\n");
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
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
}

void LOADBNMO(){ 
    ADVLOADGAME();
    char *file = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, file);
    char filename[] = "..\\data\\";
    strcat(filename, file);
    system("cls");
    printf("LOAD GAME!\n");
    STARTREADGAME(filename);
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
}

void SAVE(){
}

void CREATEGAME(){
    system("cls");
    printf("CREATE GAME!\n");
    printf("Masukkan nama game: ");
    STARTWORD();
    char *game = (char*) malloc (currentWord.Length+1);
    KataToString(currentWord, game);
    InsertKataLast(&ListGame, game);
}

void LISTGAME(){
    system("cls");
    printf("LIST GAME!\n");
    printf("Daftar game yang tersedia:\n");
    for(int i = 0; i < Length(ListGame); i++)
    {
        printf("%d. %s\n", i+1, ListGame.A[i]);
    }
}

void DELETEGAME(){}

void QUEUEGAME(){}

void PLAYGAME(){

}

void SKIPGAME(){

}

void QUIT(){
    system("cls");
    printf("QUIT GAME!\n");
    printf("Terima kasih telah bermain BNMO!\n");
    command = 0;
}

void HELP(){
    system("cls");
    printf("HELP GAME!\n");
    printf("Daftar perintah yang tersedia:\n");
    printf("1. START\n");
    printf("2. LOAD\n");
    printf("3. SAVE\n");
    printf("4. CREATE\n");
    printf("5. LIST\n");
    printf("6. DELETE\n");
    printf("7. QUEUE\n");
    printf("8. PLAY\n");
    printf("9. SKIP\n");
    printf("10. QUIT\n");
    printf("11. HELP\n");
}

void COMMANDLAIN()
{
    printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
}