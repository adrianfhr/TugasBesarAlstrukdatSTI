/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#include <stdio.h>
#include "mesinkar.h"
char currentChar;
boolean EOP;


static FILE *pita;
static int retval;

/* State Mesin */
void START(){
    pita = stdin;
    ADV();
}

/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void STARTFILE(char *filename){
      pita = fopen(filename, "r");
    if (pita == NULL) {
         printf("File tidak ditemukan.\n");
    } else {
         ADV();
    }
}

void ADV(){
   retval = fscanf(pita,"%c",&currentChar);
   EOP = (currentChar == MARK);
   if (EOP){
      fclose(pita);
   }
}

void ADVFILE(){
   retval = fscanf(pita,"%c",&currentChar);
   EOP = (currentChar == '?');
   if (EOP){
      fclose(pita);
   }
}
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

char GetCC(){
   return currentChar;
}
/* Mengirimkan currentChar */

boolean IsEOP(){
   EOP = (currentChar == MARK);
   return EOP;
}
/* Mengirimkan true jika currentChar = MARK */

