#define _CRT_SECURE_NO_WARNINGS 
#define ROW 3
#define COL 3

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//函数的声明
void InitBoard(char board[ROW][COL],int row,int col);//棋盘初始化函数的声明
void DisplayBoard(char board[ROW][COL],int row,int col);//打印棋盘函数的声明
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL],int row,int col);
char Iswin(char board[ROW][COL], int row, int col);
//能告诉我们四种游戏的状态
//玩家赢  “*”电脑赢 “#”平局  “Q”继续 “C”
//char Iswin(char board[ROW][COL], int row, int col);;