#include <stdio.h>
#include "rng.h"
#include "code/mesinkata.c"
#include "code/arraydin.c"
int main(void)
{
        STARTWORD();
        char *userCommand = (char*) malloc (currentWord.Length+1);
        KataToString(currentWord, userCommand);
        printf("%s",userCommand);
        return 0;
}
