#ifndef SNAKE
#define SNAKE
#include <stdio.h>
#include <time.h>
#include "../../ADT/boolean.h"
#include "../../ADT/MAP/intmap.h"
#include "../../ADT/LIST/list.h"
#include "../../ADT/MESINKATA/mesinkata.h"

int Numbersnake(int rng);
boolean listcomparesnake(ElType S1, ElType S2);
void arenagame(int Fruit, int Meteor, List *snake, int obstacle);
void snakestart(int *fruit, List *l, int  *obstacle);
int snakegame ();

#endif