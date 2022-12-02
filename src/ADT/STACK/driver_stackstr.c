#include "stackstr.c"
#include "../MESINKATA/mesinkata.c"
#include "../MESINKATA/mesinkar.c"


int main(){
    Stackstr S;
    CreateEmptyStackstr(&S);
    PushStackstr(&S, "Hello APA APA AP");
    PushStackstr(&S, "World");
    PushStackstr(&S, "!");
    printf("Length of stack: %d \n", lengthStackstr(S));
    printf("stack: %s\n", S.T[0]);
    printStackstr(S);
    Stackstr S2 = ReverseStackstr(S);
    printStackstr(S2);
    DeleteStackElmt(&S, "World");
    DeleteStackElmt(&S2, "Hello APA APA AP");
    printStackstr(S);
    printStackstr(S2);
    return 0;
}