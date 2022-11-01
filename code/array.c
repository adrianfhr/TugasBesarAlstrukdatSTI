#include <stdio.h>
#include "array.h"

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T){
	T->Neff = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T){
	return T.Neff;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbEl (TabInt T){
	return IdxMax-IdxMin+1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
	return T.TI[IdxMin];
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (TabInt T){
	return T.Neff;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i){
	return T.TI[i];
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout){
	Tout->Neff = Tin.Neff;
	for (int i = 0; i <= Tin.Neff; i++)
	{
		Tout->TI[i] = Tin.TI[i];
	}
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetEl (TabInt *T, IdxType i, ElType v){
	T->TI[i] = v;
	if (i == GetLastIdx(*T) + 1)
    {
        T->Neff ++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeff (TabInt *T, IdxType N){
	T->Neff = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
	return(i >= IdxMin && i <= IdxMax);
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
	return( i >= 1 && i <= T.Neff);
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
	return(T.Neff == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
	return(T.Neff == IdxMax);
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T){
	if(T.Neff == 0){
		printf("Tabel kosong\n");
	}else{
		for (int i = 1; i <= T.Neff; i++)
		{
			printf("%d:",i);
			printf("%d\n",T.TI[i]);
		}
		
	}
}
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2){
	TabInt T3;
	MakeEmpty(&T3);
	if(T1.Neff == T2.Neff){
		for (int i = 1; i <= T1.Neff; i++)
		{
			T3.TI[i] = T1.TI[i] + T2.TI[i];
		}
		T3.Neff = T1.Neff;
	}else{
		printf("Tabel tidak sama\n");
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
TabInt MinusTab (TabInt T1, TabInt T2){
	TabInt T3;
	MakeEmpty(&T3);
	if(T1.Neff == T2.Neff){
		for (int i = 1; i <= T1.Neff; i++)
		{
			T3.TI[i] = T1.TI[i] - T2.TI[i];
		}
		T3.Neff = T1.Neff;
	}else{
		printf("Tabel tidak sama\n");
	}
	return T3;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T){
	int temp = 0;
	for (int i = 1; i <= T.Neff; i++)
	{
		if(temp < T.TI[i]){
			temp = T.TI[i];
		}
	}
	return temp;	
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */

ElType ValMin (TabInt T){
	int temp = T.TI[1];
	for (int i = 1; i <= T.Neff; i++)
	{
		if(temp > T.TI[i]){
			temp = T.TI[i];
		}

	}
	return temp;	
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
{
    for (int i= (GetFirstIdx(T)+1); i <= (GetLastIdx(T)); i++)
    {
        if (T.TI[i] == ValMax(T))
        {
            return i;
        }
    }
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */

IdxType IdxMinTab (TabInt T)
{
    for (int i=(GetFirstIdx(T)+1);i <= (GetLastIdx(T)); i++)
    {
        if (T.TI[i] == ValMin(T))
        {
            return i;
        }
    }
}
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */