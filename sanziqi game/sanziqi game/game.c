#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//棋盘初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//棋盘都赋 空格 初始化
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		 int j = 0;
		 for (j = 0; j < col; j++)
		 {
			 printf(" %c ", board[i][j]);//1.打印每一行的数据
			 if (j < col - 1)
				 printf("|");
		 }
		 printf("\n");
		 //2.打印分割行
		 if (i < row - 1)
		 {
			 for (j = 0; j < col; j++)
			 {
				 printf("---");
				 if (j < col - 1)
					 printf("|");
			 }
			 printf("\n");
		 }
	}
}

void PlayerMove(char board[ROW][COL],int row,int col)//玩家走棋
{
	int x = 0;
	int y = 0;
	printf("请玩家下棋:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>\n");
		scanf("%d%d", &x,&y);
		//判断x,y坐标的合法性 不能超过棋盘的行列
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//x-1,y-1是因为数组的下标是从零开始的,从程序开发的角度，这样写才能够让计算机精准定位
			//' '表示这一位置上没有元素  --  也就是没有没有棋子
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标被占用，请重新选择落棋点\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int X = 0;
	int Y = 0;
	printf("电脑下棋:>\n");
	while (1)
	{
		X = rand() % row;//取模的结果不会大于被取模的数  如果x=3 则取模的结果<3 这里是对随机数生成的范围进行限制，不能超过棋盘的大小
		Y = rand() % col;//随机数函数    生成随机数
		if (board[X][Y] == ' ')
		{
			board[X][Y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] ==' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;//满了

}



char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')//横三行相等的情况
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')//竖三列相等的情况
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//左对角线相等的情况
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')//右对角线相等的情况
		return board[2][0];
	//判断是否平局
	//返回1表示棋盘满了
	//返回0表示棋盘没满
	if (1 == IsFull(board, ROW, COL))//1==Isfull 表示棋盘满了
	{
		return 'Q';//平局
	}
	return 'C';//继续
}