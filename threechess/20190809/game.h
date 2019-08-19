#ifndef __GAME_H__
#define __GAME_H__
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Initboard(char board[][3], int row, int col);
void Showboard(char board[][3], int row, int col);
void PlayMove(char board[][3], int row, int col);
char IsWin(char board[][3], int row, int col);
void ComputerMove(char board[][3], int row, int col);

#endif
