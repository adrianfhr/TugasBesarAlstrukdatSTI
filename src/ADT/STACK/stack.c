#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0.. CAPACITY */
/* Ciri stack kosong : TOP bernilai NilStack */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == NilStack;
}

boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == CAPACITY - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack *S, ElTypestack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
    {
        if (!IsFullStack(*S))
        {
            Top(*S)++;
            InfoTop(*S) = X;
        }
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack *S, ElTypestack *X)
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

boolean IsSameStack(Stack S1, Stack S2){
    boolean Sama = true;
    int i;
    if (lengthStack(S1) == lengthStack(S2))
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

int lengthStack(Stack S){
    Stack stemp;
    ElTypestack temp;
    int length = 0;
    CreateEmptyStack(&stemp);
    while (!IsEmptyStack(S))
    {
        PopStack(&S, &temp);
        PushStack(&stemp, temp);
        length++;
    }
    while (!IsEmptyStack(stemp))
    {
        PopStack(&stemp, &temp);
        PushStack(&S, temp);
    }
    return length;
}

