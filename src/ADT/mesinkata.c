#include<stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;


void IgnoreBlanks(){
    while(currentChar == BLANK){
        ADV();
    }
}
void IgnoreEnter(){
    while(currentChar == ENTER){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar == MARK ){
        EndWord = true;
    }else{
        EndWord = false;
        CopyWord();
        
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }else{
        CopyWord();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while(currentChar != MARK && currentChar != ENTER && currentChar != BLANK )
    {
     currentWord.TabWord[i] = currentChar;
     ADV();
     i++;   /* code */
    }
    if(i > NMax){
        currentWord.Length = NMax;
    }else{
        currentWord.Length = i;
    }
     
}

void STARTREADGAME (char *filename){
    STARTFILE(filename);
    IgnoreBlanks();
    if(currentChar == MARK ){
        EndWord = true;
    }else{
        EndWord = false;
        COPYGAME();
        IgnoreEnter();
    }
}

void ADVREADGAME(){
    IgnoreEnter();
    if(currentChar == MARK){
        EndWord = true;
    }else{
        EndWord = false;
        COPYGAME();
    }
}

void COPYGAME(){
    int i = 0;
    while(currentChar != MARK  && currentChar != ENTER )
    {
     currentWord.TabWord[i] = currentChar;
     ADV();
     i++;   /* code */
    }
    if(i > NMax){
        currentWord.Length = NMax;
    }else{
        currentWord.Length = i;
    }
}

void ADVLOADGAME(){
    IgnoreBlanks();
    if(currentChar == ENTER){
        EndWord = true;
    }else{
        COPYLOADGAME();
    }
}

void COPYLOADGAME(){
    int i = 0;
    while(currentChar != ENTER )
    {
     currentWord.TabWord[i] = currentChar;
     ADVFILE();
     i++;   /* code */
    }
    if(i > NMax){
        currentWord.Length = NMax;
    }else{
        currentWord.Length = i;
    }
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void KataToString (Word W, char *S) {
    for (int i = 0; i < W.Length; i++)
    {
        S[i] = W.TabWord[i];
    }
    S[W.Length] = '\0';
}

boolean stringcompare (char *S1, char *S2) {
    int i = 0;
    boolean found = true;
    while (S1[i] != '\0' && S2[i] != '\0' && found)
    {
        if (S1[i] != S2[i])
        {
            found = false;
        }
        i++;
    }
    if (S1[i] == '\0' && S2[i] == '\0')
    {
        found = true;
    }
    else
    {
        found = false;
    }

    return found;
}


void concat (char *S1, char *S2){
    int i = 0;
    while (S1[i] != '\0')
    {
        i++;
    }
    int j = 0;
    while (S2[j] != '\0')
    {
        S1[i] = S2[j];
        i++;
        j++;
    }
}
