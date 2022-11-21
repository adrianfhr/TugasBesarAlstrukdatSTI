#ifndef DINER
#define DINER
#include <stdio.h>
#include <time.h>
#include "../ADT/ARRAYDIN/arraydin.h"
#include "../ADT/MESINKATA/mesinkata.h"
#include "../ADT/MESINKATA/mesinkar.h"

typedef int IdxType;
typedef struct {
    int Capacity[100];
} Array;

void TOP();

void Saldo(int s);

void Middle();

void Bottom();

void Menu(int m, int d, int k, int h);

void Cook(int m, int d);

void Serve(int m, int k);

void berhasil(int status, int m, int c);

int Number(int b);

void turun(Array *cooking,Array *serving);

void Beginning(Array *durasi,Array *ketahanan,Array *harga);

#endif
