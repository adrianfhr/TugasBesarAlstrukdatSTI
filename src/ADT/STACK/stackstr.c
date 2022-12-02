#include <stdio.h>
#include "stackstr.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackstr(Stackstr *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0.. CAPACITY */
/* Ciri stack kosong : TOP bernilai NilStack */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackstr(Stackstr S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == NilStack;
}

boolean IsFullStackstr(Stackstr S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == CAPACITY - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackstr(Stackstr *S, ElType X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmptyStackstr(*S))
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
    {
        if (!IsFullStackstr(*S))
        {
            Top(*S)++;
            InfoTop(*S) = X;
        }
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackstr(Stackstr *S, ElType *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */
{
    *X = InfoTop(*S);
    if (Top(*S) == 0)
    {
        Top(*S) = NilStack;
    }
    else
    {
        Top(*S)--;
    }
}

boolean IsSameStackstr(Stackstr S1, Stackstr S2){
    boolean Sama = true;
    int i;
    if (lengthStackstr(S1) == lengthStackstr(S2))
    {
        for (i = 0; i < Top(S1); i++)
        {
            if (S1.T[i] != S2.T[i])
            {
                return false;
            }  
        }
    }
    else
    {
        return false;
    }
    return Sama;
}

int lengthStackstr(Stackstr S){
    Stackstr stemp;
    ElType temp;
    int length = 0;
    CreateEmptyStackstr(&stemp);
    while (!IsEmptyStackstr(S))
    {
        PopStackstr(&S, &temp);
        PushStackstr(&stemp, temp);
        length++;
    }
    return length;
}

void printStackstr(Stackstr S){
    Stackstr stemp;
    ElType temp;
    CreateEmptyStackstr(&stemp);
    while (!IsEmptyStackstr(S))
    {
        PopStackstr(&S, &temp);
        PushStackstr(&stemp, temp);
    }
    int index = 1;
    while (!IsEmptyStackstr(stemp))
    {
        PopStackstr(&stemp, &temp);
        printf("%d. %s \n",index, temp);
        index++;
    }
    printf("\n");
}

Stackstr ReverseStackstr(Stackstr S){
    Stackstr stemp;
    ElType temp;
    CreateEmptyStackstr(&stemp);
    while (!IsEmptyStackstr(S))
    {
        PopStackstr(&S, &temp);
        PushStackstr(&stemp, temp);
    }
    return stemp;
}

void DeleteStackElmt(Stackstr *S, ElType X){
    Stackstr stemp;
    ElType temp;
    CreateEmptyStackstr(&stemp);
    while (!IsEmptyStackstr(*S))
    {
        PopStackstr(S, &temp);
        if(!stringcompare(temp, X))
        {
            PushStackstr(&stemp, temp);
        }
    }
    while (!IsEmptyStackstr(stemp))
    {
        PopStackstr(&stemp, &temp);
        PushStackstr(S, temp);
    }
}