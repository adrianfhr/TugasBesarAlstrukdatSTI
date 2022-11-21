#include "mesinkar.c"

int main(){
    printf("Masukkan kata\n");
    START();
    while (IsEOP()){
        printf("%c", GetCC());
        ADV();
    }

    printf("program berhenti\n");


    return 0;
}