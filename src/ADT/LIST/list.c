
#include "list.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptylist(List L)
/* Mengirim true jika list kosong */
{
    return First(L) == Nill;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptylist(List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L) = Nill;
    last(*L) = Nill;
}

/****************** Manajemen Memori ******************/
addressl Alokasilist(int X,int Y)
/* Mengirimkan addressl hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressl tidak nil, dan misalnya */
/* menghasilkan P, maka infos(P)=X, Infoy(P)=Y, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressl P = (addressl)malloc(1 * sizeof(ElmtList));
    if (P != Nill)
    {
        Infox(P) = X;
        Infoy(P) = Y;
        Next(P) = Nill;
        return P;
    }
    {
        return Nill;
    }
}

void Dealokasilist(addressl *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressl P */
{
    free(*P);
}
void InsertFirstlist(List *L, addressl P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressl P sebagai elemen pertama */
{
if(IsEmptylist(*L)){
    Next(P) = First(*L);
    First(*L) = P;
    last(*L) = P;
}else{
    Next(P) = First(*L);
    First(*L) = P;
}
}

void InsertAfterlist(List *L, addressl P, addressl Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
    if(Next(P)==Nill){
        last(*L)=P;
    }
}

void InsertLastlist(List *L, addressl P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressl Last;

    if (IsEmptylist(*L))
    {
        InsertFirstlist(L, P);
    }
    else
    {
        Last = last(*L);
        InsertAfterlist(L, P, Last);
    }
}

void DelFirstlist(List *L, addressl *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    if(First(*L)==last(*L)){
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nill;
    last(*L)=Nill;
    }else{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nill;
    }
}
void DelPlist(List *L, int X, int Y)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan infox(P)=X dan Infoy(P)=Y  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X dan Infoy(P)=Y, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressl Prec;
    addressl P;
    boolean bFound = false;

    if (!IsEmptylist(*L))
    {
        if (X == Infox(First(*L)) && Y == Infoy(First(*L)))
        {
            DelFirstlist(L, &P);
            Dealokasilist(&P);
        }
        else
        {
            P = First(*L);
            while (!bFound && P != Nill)
            {
                if (Infox(P) == X && Infoy(P) == Y)
                {
                    bFound = true;
                }
                else
                {
                    Prec = P;
                    P = Next(P);
                }
            }

            if (bFound)
            {
                DelAfterlist(L, &P, Prec);
                Dealokasilist(&P);
            }
        }
    }
}

void DelLastlist(List *L, addressl *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    addressl Last = last(*L);
    addressl PrecLast = First(*L);

    if(First(*L)==last(*L)){
        DelFirstlist(L,P);
    }else{
    while (Next(PrecLast) != Last)
    {
        PrecLast = Next(PrecLast);
    }
    *P = Last;
    Next(PrecLast)=Nill;
    last(*L)=PrecLast;
    }
}

void DelAfterlist(List *L, addressl *Pdel, addressl Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nill;
    if(last(*L)==*Pdel){
        last(*L)=Prec;
    }
}
int NbElmt(List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;
    addressl a;

    if (!IsEmptylist(L))
    {
        a = First(L);
        while (a != Nill)
        {
            cnt++;
            a = Next(a);
        }
    }

    return cnt;
}