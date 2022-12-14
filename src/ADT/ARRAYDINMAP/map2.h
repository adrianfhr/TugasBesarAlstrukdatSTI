#ifndef map_H
#define map_H
#include <stdio.h>
#include "../boolean.h"
#include "../ARRAYDIN/arraydin.h"
#include "../QUEUE/queue.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
#define Nil 0

// typedef int bool;
typedef int keytype;
typedef int address;

typedef struct
{
	ElType Key;
	keytype Value;
} infotype;

typedef struct
{
	infotype Elements[CAPACITY];
	address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
keytype ValueMap(Map M, ElType k);
/* Mengembalikan nilai value dengan key k dari M */

void InsertMap(Map *M, ElType k, keytype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, ElType k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, ElType k);
/* Mengembalikan true jika k adalah member dari M */

void InsertAtMap(Map *M, ElType k, keytype v, address i);

void UpdateMap(Map *M, ElType k, keytype v);

#endif