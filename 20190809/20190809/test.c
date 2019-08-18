#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("**********1、开始游戏*********\n");
	printf("**********0、退出*************\n");
	printf("******************************\n");
}
void game() 
{
	char r;
	char board[3][3] = { 0 };
	Initboard(board, 3, 3);
	Showboard(board, 3, 3);
	while (1)
	{
		PlayMove(board, 3, 3);
		 r=IsWin(board, 3, 3);
		 if (r != ' ')
		 {
			 break;
		 }
		 Showboard(board, 3, 3);
		ComputerMove(board, 3, 3);
		r = IsWin(board, 3, 3);
		if (r != ' ')
		{
			break;
		}
		Showboard(board, 3, 3);
		}
	if (r == 'Q')
	{
		printf("平局！\n");
	}
	else if (r == 'X')
	{
		printf("哈哈！我赢了！！\n");
	}
	else if (r == 'O')
	{
		printf("尴尬，我输了！!\n");
	}
}


int main()
{   
	int in = 0;
	do{
		menu();
		srand((unsigned int)time(NULL));
		printf("请输入操作：");
		scanf("%d", &in);
		switch (in)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束：\n");
			break;
		default:
			printf("憨憨！你输入错了！\n");
			break;
		}
	} while (in);
	return 0;
}