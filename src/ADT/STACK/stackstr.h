/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stacktstr_H
#define stacktstr_H

#include "../boolean.h"
#include "../ARRAYDIN/arraydin.h"
#include "../MESINKATA/mesinkata.h"

#define CAPACITY 100

#define NilStack -1
/* NilStack adalah stack dengan elemen kosong . */

typedef int address; 
/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  ElType T[CAPACITY]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stackstr;
/* Definisi stack S kosong : S.TOP = NilStack */
/* Elemen yang dipakai menyimpan NilStackai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStackstr(Stackstr *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Stackstr S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri Stackstr kosong : TOP berNilStackstrai NilStackstr */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStackstr(Stackstr S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStackstr(Stackstr S);
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStackstr(Stackstr * S, ElType X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStackstr(Stackstr * S, ElType* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */

boolean IsSameStackstr(Stackstr S1, Stackstr S2);

int lengthStackstr(Stackstr S);

void printStackstr(Stackstr S);

Stackstr ReverseStackstr(Stackstr S);

void DeleteStackElmt(Stackstr *S, ElType X);

#endif