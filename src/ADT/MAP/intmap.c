#include "intmap.h"

/* *** Konstruktor/Kreator *** */
void CreateEmptyintMap(intMap *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah intMap M kosong berkapasitas MaxEl */
/* Ciri intMap kosong : count bernilai Nilint */
{
    M->Count = Nilint;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyintMap(intMap M)
/* Mengirim true jika intMap M kosong*/
/* Ciri intMap kosong : count bernilai Nilint */
{
    return M.Count == Nilint;
}

boolean IsFullintMap(intMap M)
/* Mengirim true jika intMap M penuh */
/* Ciri intMap penuh : count bernilai MaxEl */
{
    return M.Count == CAPACITY;
}

/* ********** Operator Dasar intMap ********* */
ElType ValueintMap(intMap M, keyinttype k)
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
    ElType VMap = M.Elements[idx].Value;
    return VMap;
}

void InsertintMap(intMap *M, keyinttype k, ElType v)
/* Menambahkan Elmt sebagai elemen intMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (IsMemberintMap(*M, k)) {
        return;
    }

    M->Elements[M->Count].Key = k;
    M->Elements[M->Count].Value = v;
    M->Count++;
}

void DeleteintMap(intMap *M, keyinttype k)
/* Menghapus Elmt dari intMap M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    boolean found = false;
    address idx = 0, iterator;

    if (!IsMemberintMap(*M, k)) {
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

boolean IsMemberintMap(intMap M, keyinttype k)
/* Mengembalikan true jika k adalah member dari M */
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

    return found;
}