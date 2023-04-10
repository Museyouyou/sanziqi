#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)//���̳�ʼ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//���̶��� �ո� ��ʼ��
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
			 printf(" %c ", board[i][j]);//1.��ӡÿһ�е�����
			 if (j < col - 1)
				 printf("|");
		 }
		 printf("\n");
		 //2.��ӡ�ָ���
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

void PlayerMove(char board[ROW][COL],int row,int col)//�������
{
	int x = 0;
	int y = 0;
	printf("���������:>\n");
	while (1)
	{
		printf("������Ҫ�µ�����:>\n");
		scanf("%d%d", &x,&y);
		//�ж�x,y����ĺϷ��� ���ܳ������̵�����
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')//x-1,y-1����Ϊ������±��Ǵ��㿪ʼ��,�ӳ��򿪷��ĽǶȣ�����д���ܹ��ü������׼��λ
			//' '��ʾ��һλ����û��Ԫ��  --  Ҳ����û��û������
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ�ã�������ѡ�������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int X = 0;
	int Y = 0;
	printf("��������:>\n");
	while (1)
	{
		X = rand() % row;//ȡģ�Ľ��������ڱ�ȡģ����  ���x=3 ��ȡģ�Ľ��<3 �����Ƕ���������ɵķ�Χ�������ƣ����ܳ������̵Ĵ�С
		Y = rand() % col;//���������    ���������
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
				return 0;//����û��
			}
		}
	}
	return 1;//����

}



char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')//��������ȵ����
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')//��������ȵ����
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')//��Խ�����ȵ����
		return board[0][0];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')//�ҶԽ�����ȵ����
		return board[2][0];
	//�ж��Ƿ�ƽ��
	//����1��ʾ��������
	//����0��ʾ����û��
	if (1 == IsFull(board, ROW, COL))//1==Isfull ��ʾ��������
	{
		return 'Q';//ƽ��
	}
	return 'C';//����
}