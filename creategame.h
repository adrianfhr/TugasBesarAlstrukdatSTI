// CREATEGAME merupakan command yang digunakan untuk menambahkan game baru pada daftar game. 
// Spesifikasi game yang dibuat dapat dilihat pada section Spesifikasi Game

#ifndef CREATEGAME_H
#define CREATEGAME_H

#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

void CreateGame (ArrayDin *ListGame, ElType gamebaru);
// Proses: menambahkan game baru pada daftar game
// I.S. daftar game tidak mungkin kosong
// F.S. game baru ditambahkan ke dalam daftar game

#endif