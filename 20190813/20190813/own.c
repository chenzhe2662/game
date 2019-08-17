#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("***************************************\n");
	printf("************1、开始游戏****************\n");
	printf("************2、退出游戏****************\n");
	printf("***************************************\n");

}
void InitBoard(char board[][COLS], int rows, int cols, char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void ShowBoard(char board[][COLS], int row, int col)
{
	int i, j;
	printf("====================\n");
	for (i = 0; i <=row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
		for (i = 1; i <= row; i++)
		{
			printf("%d ", i);
			for (j = 1; j <=col; j++)
			{
				printf("%c ", board[i][j]);
			}
			printf("\n");
	}
		printf("====================\n");
}
void SetMine(char mine[][COLS], int row, int col)
{
	int x, y;
	int count=0;
	while (count < MINE_NUM)
	{
		 x = rand() % row + 1;
		 y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
static int GetMineCount(char mine[][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] +
		mine[x][y + 1] + mine[x + 1][y + 1] + mine[x + 1][y] +
		mine[x + 1][y - 1] + mine[x][y - 1] - 8 * '0';
}
void FindMine(char mine[][ROWS], char mineInfo[][ROWS], int row, int col)
{
	int count = 0;
	int x, y;
	while (count < row*col - MINE_NUM)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了！\n");
				ShowBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int ret = GetMineCount(mine, x, y);
				mineInfo[x][y] = ret + '0';
				ShowBoard(mineInfo, ROW, COL);
				count++;
			}
		}
		else
		{
			printf("你的坐标输入有误！\n");
		}
	}
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char mineInfo[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(mineInfo, ROWS, COLS, '*');
	ShowBoard(mineInfo, ROW, COL);
	SetMine(mine, ROW, COL);
	//ShowBoard(mine, ROW, COL);
	FindMine(mine, mineInfo, ROW, COL);
}

int main()
{
	int in;
	srand((unsigned int)time(0));
	do{
		menu();
		printf("请输入你的操作：");
		scanf("%d", &in);
		switch(in)
		{
		case 1:
			game();
			break;
		case 2:
			printf("游戏结束！\n");
			break;
		default:
			printf("你的操作有误，请重新输入！\n");
			break;
		}
	} while (in);
	return 0;
}