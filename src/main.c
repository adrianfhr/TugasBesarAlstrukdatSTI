#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/mesinkata.h"
#include "ADT/arraydin.h"
#include "COMMAND/command.h"


int main(){
    int command = 0;
    while(command == 0)
    {
        printf("Welcome to BNMO!\n");
        printf("================\n");
        printf("Choose your command:\n");
        printf("1. START\n");
        printf("2. LOAD\n");
        printf("Example Command: START\n");
        printf(">> ");
        STARTWORD();
        char *userCommand = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, userCommand);
        if(strcmp(userCommand, "START") == 0)
        {
            STARTBNMO();
            command = 1;
        }
        else if(strcmp(userCommand, "LOAD") == 0)
        {
            LOADBNMO();
            command = 1;
        }
        else
        {
            COMMANDLAIN();
        }
    }

    if(command == 1){
        system("cls");
        printf("START GAME!\n");
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        STARTBNMO();
        
    for(int i = 0; i < Length(ListGame); i++)
        {
            printf("%s\n", ListGame.A[i]);
        }
  
    }
    
    scanf("%d", &command);
    
     return 0;
}
