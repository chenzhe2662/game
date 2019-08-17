//#define _CRT_SECURE_NO_WARNINGS
//#include"game.h"
//void menu()
//{
//	printf("***********************************\n");
//	printf("************0、exit****************\n");
//	printf("************1、play****************\n");
//	printf("***********************************\n");
//
//}
//void game()
//{
//		char mine[ROWS][COLS] = { 0 };
//		char mineInfo[ROWS][COLS] = { 0 };
//		InitBoard(mine, ROWS, COLS, '0');
//		InitBoard(mineInfo, ROWS, COLS, '*');
//		ShowBoard(mineInfo, ROW, COL);
//
//	SetMine(mine, ROW, COL);
//
//		//ShowBoard(mine,ROW,COL);
//		FindMine(mine, mineInfo, ROW, COL);
//	}
//int main()
//{
//	int input;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请输入你的操作：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏退出\n");
//			break;
//		default:
//			printf("请输入正确的数字\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}