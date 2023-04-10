#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"
//测试三子棋游戏
void menu()
{
	printf("***************************\n");
	printf("*****1.play   0.exit*******\n");
	printf("***************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//定义一个二维数组 也就是棋盘
	//数组—存放走出的棋盘信息 数组里的内容全部是空格
	InitBoard(board, ROW, COL);//初始化棋盘
	DisplayBoard(board, ROW, COL);//打印棋盘
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断玩家是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);//打印棋盘
		//判断电脑是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')//不继续 不是玩家赢   就是电脑赢
		{
			break;
		}
	}

	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//随机数生成
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);//如果输入值为0  则判定为假 不执行 退出游戏
}
int main()
{
	test();
	return 0;
}