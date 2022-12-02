#include "map.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == Nil;
}

boolean IsFullMap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.Count == CAPACITY;
}

/* ********** Operator Dasar Map ********* */
keytype ValueMap(Map M, ElType k)
/* Mengembalikan nilai value dengan key k dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    while (!found && idx < M.Count) {
        if (M.Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }
    keytype VMap = M.Elements[idx].Value;
    return VMap;
}

void InsertMap(Map *M, ElType k, keytype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMemberMap(*M, k)) {
        return;
    }

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Value = v;
    M->Count++;
}

void DeleteMap(Map *M, ElType k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    if (!IsMemberMap(*M, k)) {
        return;
    }

    while (!found && (idx < M->Count)) {
        if (M->Elements[idx].Key == k) {
            found = true;
        }
        else {
            idx++;
        }
    }

    for (iterator = (idx + 1); iterator < M->Count; iterator++) {
        M->Elements[iterator - 1].Key = M->Elements[iterator].Key;
        M->Elements[iterator - 1].Value = M->Elements[iterator].Value;
    }

    M->Count--;
}

boolean IsMemberMap(Map M, ElType k)
/* Mengembalikan true jika k adalah member dari M */
{
    boolean found = false;
    address idx = 0;

    while (!found && idx < M.Count) {
        if (stringcompare(M.Elements[idx].Key, k)){
            found = true;
        }
        else {
            idx++;
        }
    }

    return found;
}


void InsertAtMap(Map *M, ElType k, keytype v, address i){
    if (IsMemberMap(*M, k)) {
        return;
    }

    if (i < 0 || i > M->Count) {
        return;
    }

    address iterator;
    for (iterator = M->Count; iterator > i; iterator--) {
        M->Elements[iterator].Key = M->Elements[iterator - 1].Key;
        M->Elements[iterator].Value = M->Elements[iterator - 1].Value;
    }

    M->Elements[i].Key = k;
    M->Elements[i].Value = v;
    M->Count++;
}

void UpdateMap(Map *M, ElType k, keytype v){
    if (IsMemberMap(*M, k)) {
        boolean found = false;
        address idx = 0;

        while (!found && idx < M->Count) {
            if (M->Elements[idx].Key == k) {
                found = true;
            }
            else {
                idx++;
            }
        }

        M->Elements[idx].Value = v;
    }
}