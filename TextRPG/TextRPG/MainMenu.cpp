#include "MainMenu.h"

#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "DoubleBuffering.h"

MainMenu::MainMenu()
{
	MAP_X = 30;
	MAP_Y = 30;
	MAP_ADJ_X = 3;
	MAP_ADJ_Y = 2;
	//sztitle[15] = { "Hello World!!" };

	iMovingCurser = 0;
}

MainMenu::~MainMenu()
{

}

void MainMenu::Render()
{
	{
		//
		DoubleBuffering buffer;

		buffer.CreateBuffer();

		//
		int iKey = 0;
		int nDir = 1;
		int x = (MAP_X - 5);
		//system("cls");
		//buffer.BufferClear();
		while (true)
		{
			if (_kbhit())
			{
				//break;
			}
			//DrawMap();
			//x += 3 * nDir;
			//if ((x <= 3) || (x > (MAP_X - 5)))
			//{
			//	nDir *= -1;
			//	continue;
			//}
			//GotoXY(x, (MAP_ADJ_Y + 5), sztitle);
			//GotoXY(6, 6, "Test");
			//UpdateMove(7, 7, "Move");
			buffer.BufferClear();
			//buffer.BufferWrite(3, 3, "Test");
			DrawMap();

			
			/*
			�ʱ�ȭ -> ��ó�� �����ϱ⸸ ���� ���� -> ����Ű�� 0 1 2 �� ���� ����
			x -- �ϰ�� 0 1��� 0 2�� ��� 1 2
				
			*/
			buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ", eConsoleColor::WHITE, eConsoleColor::RED);
			buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ");
			buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� ");

		

			if (0 == iMovingCurser)
			{
				buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ", eConsoleColor::WHITE, eConsoleColor::BLUE);
				//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ", eConsoleColor::WHITE, eConsoleColor::RED);
				buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ");
				buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� ");
			}
			else if (1 == iMovingCurser)
			{
				buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� " );
				//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ", eConsoleColor::WHITE, eConsoleColor::RED);
				buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ",eConsoleColor::WHITE, eConsoleColor::BLUE);
				buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� ");
			}
			else if (2 == iMovingCurser)
			{
				buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ");
				//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ", eConsoleColor::WHITE, eConsoleColor::RED);
				buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� �� ");
				buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " �� �� �� ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			}
			
			
			
			buffer.Flipping();

			iKey = _getch();

			switch (iKey)
			{
			case eKey::LEFT:
				iMovingCurser--;
				break;
			case eKey::RIGHT:
				iMovingCurser++;
				break;
			case eKey::ENTER:
				break;
			}

			if (0 > iMovingCurser)
			{
				iMovingCurser = 0;
			}
			
			if (2 < iMovingCurser)
			{
				iMovingCurser = 2;
			}
			//Sleep(33);
			system("cls");
		}
		buffer.Release();


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
	DoubleBuffering buffer;

	int i = 0;
	for (i = 0; i < MAP_X; i++)
	{
		//GotoXY(MAP_ADJ_X + i, MAP_ADJ_Y, "��");
		buffer.BufferWrite(MAP_ADJ_X + i, MAP_ADJ_Y, "��");
	}

	for (i = (MAP_ADJ_Y + 1); i < (MAP_ADJ_Y + MAP_Y - 1); i++)
	{
		//GotoXY(MAP_ADJ_X, i, "��");
		buffer.BufferWrite(MAP_ADJ_X, i, "��");
		//GotoXY((MAP_ADJ_X + MAP_X - 1), i, "��");
		buffer.BufferWrite((MAP_ADJ_X + MAP_X - 1), i, "��");
	}

	for (i = 0; i < MAP_X; i++)
	{
		//GotoXY((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "��");.


		buffer.BufferWrite((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "��");
	}

}


void MainMenu::Textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}