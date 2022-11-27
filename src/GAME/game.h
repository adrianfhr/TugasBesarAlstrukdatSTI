

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ADT/boolean.h"
#include "../ADT/MESINKATA/mesinkata.h"
#include "hangman/hangman.h"
#include "snake/snake.h"

void RNG();
/*BNMO tidak selalu menikmati game yang sudah pasti outcome-nya. Karena itu, ia suka dengan game yang melibatkan RNG (Random number generator).  Berikut adalah spesifikasi game ini:
Setiap permainan dimulai dengan program sudah menentukan sebuah angka acak X.
Di setiap giliran, pemain diberi kesempatan menebak angka X. Game akan memberi tahu apakah tebakan pemain dibandingkan terhadap X lebih besar atau lebih kecil.
Permainan selesai jika pemain menebak angka X dengan benar.
Skor untuk game ini tergantung dengan seberapa cepat pemain menebak X. Formula skor dibebaskan.
Batasan X dan maksimal giliran dibebaskan.
Catatan:
Gunakan fungsi pembangkit angka acak bawaan bahasa c.
Secara default, pembangkit angka acak bawaan bahasa c menghasilkan pseudo random number yang artinya angka yang dihasilkan memiliki pola dan tidak benar-benar acak. Cari tahu bagaimana membangkitkan angka acak dengan benar-benar acak.
*/

void DinerDash();
/*Indra dan Doni juga suka permainan yang menegangkan. Oleh karena itu, ia ingin ada sebuah game Diner Dash dalam BNMO. Secara singkat, Diner Dash merupakan permainan mengantar makanan namun terurut berdasarkan prioritasnya. Berikut adalah spesifikasi game ini:
Terdapat 2 command yang dapat dilakukan pada game, yaitu COOK dan SERVE
COOK merupakan command yang bertujuan untuk memasak makanan
SERVE merupakan command yang bertujuan untuk menyajikan makanan kepada pelanggan.
Permainan akan dimulai dengan 3 pelanggan. Setiap pelanggan hanya dapat memesan satu makanan. Untuk setiap makanan, terdapat informasi tentang ID makanan yang dihasilkan secara increment (M01, M02, M03, dst), durasi memasak, harga makanan, serta ketahanan makanan. Semua informasi tersebut akan didapatkan secara random dengan menggunakan random number generator. Durasi dan ketahanan makanan akan berkisar diantara 1-5. Sedangkan, harga makanan akan berkisar diantara 10000 - 50000.
Kapasitas dari pemain adalah memasak 5 makanan dalam waktu yang sama. Pelanggan yang dilayani adalah pelanggan yang duluan memasuki antrian.
Permainan selesai apabila antrian melebihi 7 pelanggan atau jumlah pelanggan yang sudah dilayani mencapai 15 pelanggan.
Pada setiap putaran, akan terdapat 1 pelanggan baru. 
Pada setiap putaran, seluruh durasi dari makanan yang sedang dimasak akan berkurang 1. Ketika durasi makanan mencapai 0, maka makanan sudah dapat di SERVE.
Ketika makanan sudah di SERVE, maka makanan dapat diantar kepada pelanggan dan pelanggan dapat meninggalkan antrian. Setelah pelanggan meninggalkan antrian, maka pemain akan menerima uang
SERVE hanya dapat digunakan untuk pesanan yang berada di paling depan.
Skor akhir dari pemain adalah total uang yang diterima oleh pemain.
*/

void GameTambahan();

void kerangajaib();

void Hangman();

void Snake();

#endif