#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("******************************\n");
	printf("**********1����ʼ��Ϸ*********\n");
	printf("**********0���˳�*************\n");
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
		printf("ƽ�֣�\n");
	}
	else if (r == 'X')
	{
		printf("��������Ӯ�ˣ���\n");
	}
	else if (r == 'O')
	{
		printf("���Σ������ˣ�!\n");
	}
}


int main()
{   
	int in = 0;
	do{
		menu();
		srand((unsigned int)time(NULL));
		printf("�����������");
		scanf("%d", &in);
		switch (in)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ������\n");
			break;
		default:
			printf("��������������ˣ�\n");
			break;
		}
	} while (in);
	return 0;
}