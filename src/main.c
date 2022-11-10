#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/mesinkata.h"
#include "ADT/arraydin.h"
#include "COMMAND/command.h"
#include "GAME/game.h"



int main(){
    while(command != 0)
    {
        FILE *Welcome;
        char *welcomeText = "..\\data\\welcome.txt";
        Welcome = fopen(welcomeText, "r");
        WelcomeBNMO(Welcome);
        mainmenu();
        STARTWORD();
        char *userCommand = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, userCommand);
        if(stringcompare(userCommand, "START") == 1)
        {
            STARTBNMO();
            while(command != 0)
            {
                commandconfig();
            }
        }
        
        else if(stringcompare(userCommand, "LOAD") == 1)
        {

            LOADBNMO();
            if(currentChar != MARK){
               while(command != 0)
                {
                commandconfig();    
                } 
            }
        }
        else
        {
            COMMANDLAIN();
        }
    }
  
     return 0;
}
