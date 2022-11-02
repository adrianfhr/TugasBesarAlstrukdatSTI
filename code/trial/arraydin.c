#include <stdio.h>
#include <stdlib.h>
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

void PrintArray(ArrayDin array){
    for (int i = 0; i < array.Neff; i++){
        printf("%d", array.A[i]);
    }
}