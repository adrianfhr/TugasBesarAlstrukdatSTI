#include "map.h"
#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

// Boolean
#define boolean unsigned char
#define true 1
#define false 0

#define InitialSize 100

typedef int IdxType;
typedef char* ElType;
typedef Map MapType;
typedef struct {
    MapType *A;
    int Capacity;
    int Neff;
} ArrayMap;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} ArrayDin;

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin();
ArrayMap MakeArrayMap();

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array);

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array);

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array);

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i);

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array);

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i);

void InsertKataLast(ArrayDin *array, char* el);

void InsertLast(ArrayDin *array, ElType el);

void InsertFirst(ArrayDin *array, ElType el);
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i);

void DeleteLast(ArrayDin *array);

void DeleteFirst(ArrayDin *array);

void PrintArray(ArrayDin array);

void ReverseArrayDin(ArrayDin *array);

ArrayDin CopyArrayDin(ArrayDin array);

IdxType SearchArrayDin(ArrayDin array, ElType el);
#endif