

#ifndef listlinier_H
#define listlinier_H

#include "../boolean.h"
#include "stdio.h"
#include "stdlib.h"

#define Nill NULL

typedef struct tElmtlist *addressl;
typedef struct
{
	int x;
	int y;
} Xtype;
typedef struct tElmtlist
{
    Xtype infol;
    addressl nextl;
} ElmtList;
typedef struct
{
    addressl First;
    addressl last;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nill && last(L) = Nill */
/* Setiap elemen dengan addressl P dapat diacu Infox(P) , Infoy(P) , Next(P) */
/* Elemen terakhir list : jika addresslnya Last, maka Next(Last)=Nil dan last(L) */
#define Infox(P) (P)->infol.x
#define Infoy(P) (P)->infol.y
#define Next(P) (P)->nextl
#define First(L) ((L).First)
#define last(L) ((L).last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylist(List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylist(List *L);
/* I.S. sembarang    \         */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressl Alokasilist(int X,int Y);
/* Mengirimkan addressl hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressl tidak nil, dan misalnya */
/* menghasilkan P, maka infos(P)=X, Infoy(P)=Y, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasilist(addressl *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressl P */
void InsertFirstlist(List *L, addressl P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressl P sebagai elemen pertama */
void InsertAfterlist(List *L, addressl P, addressl Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
void InsertLastlist(List *L, addressl P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void DelFirstlist(List *L, addressl *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelPlist(List *L, int X, int Y);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan infox(P)=X dan Infoy(P)=Y  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X dan Infoy(P)=Y, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLastlist(List *L, addressl *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfterlist(List *L, addressl *Pdel, addressl Prec);
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
int NbElmt(List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
#endif