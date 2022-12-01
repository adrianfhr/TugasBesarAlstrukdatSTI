#ifndef hangman_h
#define hangman_h

#include "../../ADT/boolean.h"
#include "../../ADT/ARRAYDIN/arraydin.h"
#include "../../ADT/MESINKATA/mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

extern ArrayDin ListKataHangman, ListJawabUser, ListSoal, hangman;
extern boolean exithangman, win;
extern int commandhangman, skorhangman;

void hangmanart(ArrayDin* hangman);

boolean hangmancompare(ElType S1, ElType S2);

void STARTHANGMAN();

void SoalHangman(int *alreadypicked, int* alreadypickedcount);

void CekAnswer(ElType x, int* kesempatan);

void JawabUser(ElType jawab);

void CekWin(ElType jawab, boolean *win);

void addkatahangman(ArrayDin *ListKataHangman, char *kata);

boolean alreadyhangman(ElType x);

boolean CekKapital(ElType x);

int HangmanMain();

#endif