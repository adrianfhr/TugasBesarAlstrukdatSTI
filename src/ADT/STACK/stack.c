#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas CAPACITY */
/* jadi indeksnya antara 0.. CAPACITY */
/* Ciri stack kosong : TOP bernilai NilStack */
{
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == NilStack;
}

boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return Top(S) == CAPACITY - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, ElType X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (IsEmpty(*S))
    {
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
    {
        if (!IsFull(*S))
        {
            Top(*S)++;
            InfoTop(*S) = X;
        }
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, ElType *X)
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