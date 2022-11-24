#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraydin.h"

/*
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin ArrDin;
    ArrDin.A = (ElType *) malloc(InitialSize * sizeof(ElType));
    ArrDin.Capacity = InitialSize;
    ArrDin.Neff = 0;
    return ArrDin;
}
ArrayMap MakeArrayMap(){
    ArrayMap ArrMap;
    ArrMap.A = (MapType *) malloc(InitialSize * sizeof(MapType));
    ArrMap.Capacity = InitialSize;
    ArrMap.Neff = 0;
    return ArrMap;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free((*array).A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return array.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return array.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return array.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return array.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    if ((*array).Neff == (*array).Capacity){
        (*array).A = (ElType *) realloc((*array).A, 2 * (*array).Capacity * sizeof(ElType));
        (*array).Capacity *= 2;
    }
    for (int j = (*array).Neff; j > i; j--){
        (*array).A[j] = (*array).A[j-1];
    }
    (*array).A[i] = el;
    (*array).Neff++;
}

void InsertKataLast(ArrayDin *array, char *el){
    if ((*array).Neff == (*array).Capacity){
        (*array).A = (ElType *) realloc((*array).A, 2 * (*array).Capacity * sizeof(ElType));
        (*array).Capacity *= 2;
    }
    (*array).A[(*array).Neff] = el;
    (*array).Neff++;
}

void InsertMapLast(ArrayMap *array, Map *el){
    if ((*array).Neff == (*array).Capacity){
        (*array).A = (MapType *) realloc((*array).A, 2 * (*array).Capacity * sizeof(MapType));
        (*array).Capacity *= 2;
    }
    (*array).A[(*array).Neff] = el;
    (*array).Neff++;
}

void InsertLast(ArrayDin *array, ElType el)
{
    InsertAt(array, el, array->Neff);
}

void InsertFirst(ArrayDin *array, ElType el)
{
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    for (int j = i; j < (*array).Neff; j++){
        (*array).A[j] = (*array).A[j+1];
    }
    (*array).Neff--;

}
void DeleteLast(ArrayDin *array)
{
    array->Neff--;
}

void DeleteFirst(ArrayDin *array)
{
    DeleteAt(array, 0);
}

void PrintArray(ArrayDin array){
    for (int i = 0; i < array.Neff; i++){
        printf("%d", array.A[i]);
    }
}

void ReverseArrayDin(ArrayDin *array)
{
    int i = array->Neff - 1;
    int count = 0;
    int temp;
    while (count < i)
    {
        temp = array->A[count];
        array->A[count] = array->A[i];  
        array->A[i] = temp;
        count++;
        i--;
    }
}

ArrayDin CopyArrayDin(ArrayDin array)
{
    ArrayDin ArrCopy;
    ArrCopy = MakeArrayDin();
    int i;
    for (i = 0; i < array.Neff; i++)
    {
        InsertLast(&ArrCopy, array.A[i]);
    }
    return ArrCopy;
}

IdxType SearchArrayDin(ArrayDin array, ElType el)
{
    int i;
    for (i = 0; i < array.Neff; i++)
    {
        if (array.A[i] == el)
        {
            return i;
        }
    }
    return -1;
}