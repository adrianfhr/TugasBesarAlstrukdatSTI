#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean.h"
#include "../ARRAYDIN/arraydin.h"
#include "../QUEUE/queue.h"

/* MODUL intMap
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nilint 0

// typedef int bool;
typedef int keyinttype;
typedef int address;

typedef struct
{
	keyinttype Key;
	ElType Value;
} infotype;

typedef struct
{
	infotype Elements[CAPACITY];
	address Count;
} intMap;

/* Definisi intMap M kosong : M.Count = Nil */
/* M.Count = jumlah element intMap */
/* M.Elements = tempat penyimpanan element intMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyintMap(intMap *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah intMap M kosong berkapasitas MaxEl */
/* Ciri intMap kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyintMap(intMap M);
/* Mengirim true jika intMap M kosong*/
/* Ciri intMap kosong : count bernilai Nil */

boolean IsFullintMap(intMap M);
/* Mengirim true jika intMap M penuh */
/* Ciri intMap penuh : count bernilai MaxEl */

/* ********** Operator Dasar intMap ********* */
ElType ValueintMap(intMap M, keyinttype k);
/* Mengembalikan nilai value dengan key k dari M */

void InsertintMap(intMap *M, keyinttype k, ElType v);
/* Menambahkan Elmt sebagai elemen intMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteintMap(intMap *M, keyinttype k);
/* Menghapus Elmt dari intMap M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberintMap(intMap M, keyinttype k);
/* Mengembalikan true jika k adalah member dari M */

#endif