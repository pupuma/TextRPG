#include "MainMenu.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>


MainMenu::MainMenu()
{
	MAP_X = 30;
	MAP_Y = 30;
	MAP_ADJ_X = 3;
	MAP_ADJ_Y = 2;
	//sztitle[15] = { "Hello World!!" };
}

MainMenu::~MainMenu()
{

}

void MainMenu::Render()
{
	int nDir = 1;
	int x = (MAP_X - 5);
	system("cls");
	while (true)
	{
		if (_kbhit())
		{
			//break;
		}
		DrawMap();
		//x += 3 * nDir;
		//if ((x <= 3) || (x > (MAP_X - 5)))
		//{
		//	nDir *= -1;
		//	continue;
		//}
		//GotoXY(x, (MAP_ADJ_Y + 5), sztitle);
		GotoXY(6,6, "Test");
		//UpdateMove(7, 7, "Move");

		Sleep(33);
		system("cls");
	}
}

void MainMenu::GotoXY(int  _x, int _y, const char* pszStr)
{
	COORD pos;
	pos.X = _x * 2;
	pos.Y = _y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);


	printf("%s", pszStr);
}

void MainMenu::DrawMap()
{
	int i = 0;
	for (i = 0; i < MAP_X; i++)
	{
		GotoXY(MAP_ADJ_X + i, MAP_ADJ_Y, "бс");
	}
	for (i = (MAP_ADJ_Y + 1); i < (MAP_ADJ_Y + MAP_Y - 1); i++)
	{
		GotoXY(MAP_ADJ_X, i, "бс");
		GotoXY((MAP_ADJ_X + MAP_X - 1), i, "бс");
	}
	for (i = 0; i < MAP_X; i++)
	{
		GotoXY((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "бс");
	}
}


