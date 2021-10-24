#include <stdio.h>
#include <windows.h>
#include <conio.h>		
#include <stdlib.h>
#include <string.h>

#define max_XY 19
#define black 1
#define white 2
#define draw_Black printf("¡Û")
#define draw_White printf("¡Ü")


void drawInit();
void gotoxy(int x, int y);
void draw_Stone();
void delete_Stone(int x, int y);
void key_Down(int board[][20], int key, int *x, int *y);
void put_Stone(int board[][20], int x, int y);
void putting_Stone(int board[][20], int x, int y);
int win_Check(int board[][20]);
int color = 1;

int main(void)
{
	int board[20][20] = { 0 };
	int key = 0;
	int x = 9;
	int y = 9;
	drawInit();
	gotoxy(x, y);
	draw_Stone();
	while (key != 27)
	{
		key = _getch();
		delete_Stone(x, y);
		key_Down(board, key, &x, &y);
		putting_Stone(board, x, y);
		if (win_Check(board))
			break;
		gotoxy(x, y);
		draw_Stone();
	}
}

void drawInit()
{
	gotoxy(0, 0);
	for (int i = 0; i < max_XY; i++)
	{
		for (int j = 0; j < max_XY; j++)
		{
			gotoxy(j, i);
			if (i == 0)
			{
				if (j == 0)
				{
					printf("¦£");
				}
				else if (j == max_XY - 1)
				{
					printf("¦¤");
				}
				else {
					printf("¦¨");
				}
			}
			else if (j == 0)
			{
				if (i == max_XY - 1)
				{
					printf("¦¦");
				}
				else
				{
					printf("¦§");
				}
			}
			else if (j == max_XY - 1)
			{
				if (i == max_XY - 1)
				{
					printf("¦¥");
				}
				else
				{
					printf("¦©");
				}
			}
			else if (i == max_XY - 1)
			{
					printf("¦ª");
			}
			else
			{
				printf("¦«");
			}
		}
	}
}


void gotoxy(int x, int y) {
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void draw_Stone()
{
	if (color == 1)
	{
		draw_Black;
	}
	else
	{
		draw_White;
	}
}

void delete_Stone(int x, int y)
{
	gotoxy(x, y);
	if (x == 0 && y == 0)
		printf("¦£ ");
	else if (x == max_XY - 1 && y == 0)
		printf("¦¤ ");
	else if (x == 0 && y == max_XY - 1)
		printf("¦¦ ");
	else if (x == max_XY - 1 && y == max_XY - 1)
		printf("¦¥ ");
	else if (x == 0)
		printf("¦§ ");
	else if (y == 0)
		printf("¦¨ ");
	else if (x == max_XY - 1)
		printf("¦© ");
	else if (y == max_XY - 1)
		printf("¦ª ");
	else
		printf("¦« ");
}
void key_Down(int board[][20], int key, int *x, int *y)
{
	switch (key) {
	case (75):
		if (*x < 1)
			break;
		else
			*x -= 1;
		break;
	case (77):
		if (*x > max_XY - 2)
			break;
		else
			*x += 1;
		break;
	case (72):
		if (*y < 1)
			break;
		else
			*y -= 1;
		break;
	case (80):
		if (*y > max_XY - 2)
			break;
		else
			*y += 1;
		break;
	case 32:
		put_Stone(board, *x, *y);
		break;
	default:
		break;
	}
}

void put_Stone(int board[][20], int x, int y)
{
	if (board[y][x] == 0)
	{
		if (color == 1)
		{
			board[y][x] = 1;
			color = 2;
		}
		else if (color == 2)
		{
			board[y][x] = 2;
			color = 1;
		}
	}
}

void putting_Stone(int board[][20], int x, int y)
{
	for (x = 0; x < max_XY; x++)
	{
		for (y = 0; y < max_XY; y++)
		{
			if (board[y][x] == 1)
			{
				gotoxy(x, y);
				draw_Black;
			}
			else if (board[y][x] == 2)
			{
				gotoxy(x, y);
				draw_White;
			}
		}
	}
}

int win_Check(int board[][20])
{
	for (int i = 0; i < max_XY - 1; i++)
	{
		for (int j = 0; j < max_XY - 1; j++)
		{
			if (board[j][i - 2] == 1 && board[j][i - 1] == 1 && board[j][i] == 1 && board[j][i + 1] == 1 && board[j][i + 2] == 1)
			{
				gotoxy(0, 22);
				printf("Èæµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
			else if (board[j][i - 2] == 2 && board[j][i - 1] == 2 && board[j][i] == 2 && board[j][i + 1] == 2 && board[j][i + 2] == 2)
			{
				gotoxy(0, 22);
				printf("¹éµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
			else if (board[j - 2][i] == 1 && board[j - 1][i] == 1 && board[j][i] == 1 && board[j + 1][i] == 1 && board[j + 2][i] == 1)
			{
				gotoxy(0, 22);
				printf("Èæµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
			else if (board[j - 2][i] == 2 && board[j - 1][i] == 2 && board[j][i] == 2 && board[j + 1][i] == 2 && board[j + 2][i] == 2)
			{
				gotoxy(0, 22);
				printf("¹éµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
		}
	}
	for (int i = 2; i < max_XY - 1; i++)
	{
		for (int j = 2; j < max_XY - 1; j++)
		{
			if (board[j - 2][i - 2] == 1 && board[j - 1][i - 1] == 1 && board[j][i] == 1 && board[j + 1][i + 1] == 1 && board[j + 2][i + 2] == 1)
			{
				gotoxy(0, 22);
				printf("Èæµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
			else if (board[j - 2][i - 2] == 2 && board[j - 1][i - 1] == 2 && board[j][i] == 2 && board[j + 1][i + 1] == 2 && board[j + 2][i + 2] == 2)
			{
				gotoxy(0, 22);
				printf("¹éµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
			else if (board[j - 2][i + 2] == 1 && board[j - 1][i + 1] == 1 && board[j][i] == 1 && board[j + 1][i - 1] == 1 && board[j + 2][i - 2] == 1)
			{
				gotoxy(0, 22);
				printf("Èæµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
			else if (board[j - 2][i + 2] == 2 && board[j - 1][i + 1] == 2 && board[j][i] == 2 && board[j + 1][i - 1] == 2 && board[j + 2][i - 2] == 2)
			{
				gotoxy(0, 22);
				printf("¹éµ¹½Â¸®!!!");
				_getch();
				return 1;
			}
		}
	}
	return 0;
}
