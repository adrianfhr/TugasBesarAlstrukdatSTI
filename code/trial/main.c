#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.c"

int main(){
    int command = 0;
    char menu[10];
    while(command == 0)
    {
        printf("Welcome to BNMO!\n");
        printf("================\n");
        printf("Choose your command:\n");
        printf("1. START\n");
        printf("2. LOAD\n");
        printf("Example Command: START\n");
        printf(">> ");
        scanf("%s", &menu);
        
        if(strcmp(menu, "START") == 0)
        {
            system("cls");
            command = 1;
        }
        else if(strcmp(menu, "LOAD") == 0)
        {
            system("cls");
            command = 2;
        }
        else
        {
            printf("Invalid command\n\n");
        }
    } 

    if(command == 1){
        printf("START GAME!\n");
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
        STARTBNMO();
        
    }
    
    
     return 0;
}
