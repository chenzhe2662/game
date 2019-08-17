#ifndef  __GAME_H__
#define __GAME_H__
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define COLS 11
#define ROWS 11
#define MINE_NUM 10

void InitBoard(char board[][COLS], int rows, int cols, char set);
void ShowBoard(char board[][COLS], int row, int col);
void SetMine(char mine[][COLS], int row, int col);
void FindMine(char mine[][ROWS], char mineInfo[][ROWS], int row, int col);

#endif//__GAME_H__