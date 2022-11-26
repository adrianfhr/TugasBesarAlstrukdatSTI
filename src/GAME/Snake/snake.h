#ifndef SNAKE
#define SNAKE
#include <stdio.h>
#include <time.h>
#include "../ADT/boolean.h"
#include "../ADT/MAP/map.h"
#include "../ADT/LIST/list.h"
#include "../ADT/MESINKATA/mesinkata.h"

int Number(int rng);
boolean listcompare(ElType S1, ElType S2);
void arenagame(int Fruit, int Meteor,List *snake);
void snakestart(int *fruit,List *l);
int snakegame ();
#endif