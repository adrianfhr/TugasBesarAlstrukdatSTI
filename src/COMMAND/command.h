#include <stdio.h>
#include <stdlib.h>
#include "../ADT/ARRAYDIN/arraydin.h"
#include "../ADT/MAP/map.h"
#include "../ADT/ARRAYDINMAP/arraydinmap.h"
#include "../ADT/QUEUE/queue.h"
#include "../ADT/MESINKATA/mesinkata.h"
#include "../ADT/MESINKATA/mesinkar.h"
#include "../GAME/game.h"
#include "../ADT/STACK/stackstr.h"

#ifndef COMMAND_H
#define COMMAND_H

extern int command;
extern ArrayDin ListGame;
extern Queue GameQueue;
extern char *userplaygame;
extern arraymap scoreboardlist;
extern Stackstr HistoryGame;

void mainmenu();

void commandconfig();

void commandmenu();

void STARTBNMO();

void LOADBNMO();

void SAVE();

void CREATEGAME();

void LISTGAME();

void DELETEGAME();

void QUEUEGAME();

void PLAYGAME();

void SKIPGAME();

void QUIT();

void HELP();

void COMMANDLAIN();

void DisplayGame();

void WelcomeBNMO(FILE *w);

void gamecurrent();

void STARTSCOREBOARD();

void PRINTSCOREBOARD();

void SCOREBOARD();

void INSERTSCOREBOARD();

void RESETSCOREBOARD();

void HISTORY(int x);

void RESETHISTORY();
#endif