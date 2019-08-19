#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void Initboard(char board[][3], int row, int col)//初始化
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}
void Showboard(char board[][3], int row, int col)//打印棋盘
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i< row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}
void PlayMove(char board[][3], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入1~3的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("憨憨！此位置电脑下了！\n");
			}
		}
		else
		{
			printf("憨憨！坐标输错了！\n");
		}

	}
}
static int IsFull(char board[][3], int row, int col)//static修饰只能在game.c中使用。判断棋盘下满否。
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char IsWin(char board[][3], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//行
		if (board[i][0] == board[i][1]&& board[i][1] == board[i][2]
			&& board[i][0] != ' ')
		{
			return board[i][0];
		}
		//列
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]
			&& board[0][i] != ' ')
		{
			return board[0][i];
		}

		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]
			&& board[0][0] != ' ')
		{
			return board[0][0];
		}

		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]
			&& board[0][0] != ' ')
		{
			return board[0][2];
		}

		//平局
		if (IsFull(board, row, col) == 1)
		{
			return 'Q';//棋盘下满，平局
		}
	}
	//棋盘未满，胜负未分
	return ' ';
}

void ComputerMove(char board[][3], int row, int col)
{
	printf("电脑移动\n");
	while (1)
	{
		int x = rand() % row + 1;//  [0-3)   [1-4)
		int y = rand() % col + 1;
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] ='O';
			break;
		}
	}
}
