#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/mesinkata.h"
#include "ADT/arraydin.h"
#include "COMMAND/command.h"



int main(){
    
    while(command != 0)
    {
        mainmenu();
        STARTWORD();
        char *userCommand = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, userCommand);
        if(strcmp(userCommand, "START") == 0)
        {
            STARTBNMO();
            while(command != 0)
            {
                commandconfig();
            }
            

        }
        else if(strcmp(userCommand, "LOAD") == 0)
        {
            
            LOADBNMO();
            while(command != 0)
            {
                commandconfig();
            }
            
        }
        else
        {
            COMMANDLAIN();
        }
    }
  
     return 0;
}
