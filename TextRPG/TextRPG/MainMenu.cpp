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

	iKey = 0;
	nDir = 1;
	x = (MAP_X - 5);
	buffer = new DoubleBuffering();
	buffer->CreateBuffer();

}

MainMenu::~MainMenu()
{

}
void MainMenu::Clear()
{
	buffer->BufferClear();
}
void MainMenu::Update()
{
	//buffer->BufferClear();
	//buffer->Flipping();
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
}
void MainMenu::Render()
{
	{
		//
		//DoubleBuffering buffer;


		DrawMap();
		switch (iMovingCurser)
		{
		case 0:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
			break;
		case 1:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
			break;
		case 2:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			break;
		default:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");

			break;
		}

		

		//
		//int iKey = 0;
		//int nDir = 1;
		//int x = (MAP_X - 5);
		//system("cls");
		//buffer.BufferClear();


	//	while (true)
	//	{
	//		//if (_kbhit())
	//		//{
	//			//break;
	//		//}
	//		//DrawMap();
	//		//x += 3 * nDir;
	//		//if ((x <= 3) || (x > (MAP_X - 5)))
	//		//{
	//		//	nDir *= -1;
	//		//	continue;
	//		//}
	//		//GotoXY(x, (MAP_ADJ_Y + 5), sztitle);
	//		//GotoXY(6, 6, "Test");
	//		//UpdateMove(7, 7, "Move");
	//		//buffer->BufferClear();
	//		//buffer.BufferWrite(3, 3, "Test");
	//		DrawMap();

	//		
	//		/*
	//		초기화 -> 맨처음 새로하기만 음영 조절 -> 반향키가 0 1 2 로 범위 설정
	//		x -- 일경우 0 1경우 0 2일 경우 1 2
	//			
	//		*/
	//		//buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//		//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::RED);
	//		//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
	//		//buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");

	//	
	//		switch (iMovingCurser)
	//		{
	//		case 0:
	//			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
	//			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
	//			break;
	//		case 1:
	//			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
	//			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
	//			break;
	//		case 2:
	//			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
	//			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
	//			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//			break;
	//		default:
	//			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
	//			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");

	//			break;
	//		}
	//		//if (0 == iMovingCurser)
	//		//{
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//		//	//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::RED);
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
	//		//}
	//		//else if (1 == iMovingCurser)
	//		//{
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 " );
	//		//	//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::RED);
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ",eConsoleColor::WHITE, eConsoleColor::BLUE);
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
	//		//}
	//		//else if (2 == iMovingCurser)
	//		//{
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
	//		//	//buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::RED);
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
	//		//	buffer.BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
	//		//}
	//		
	//		
	//		
	//		//buffer->Flipping();

	//		iKey = _getch();

	//		switch (iKey)
	//		{
	//		case eKey::LEFT:
	//			iMovingCurser--;
	//			break;
	//		case eKey::RIGHT:
	//			iMovingCurser++;
	//			break;
	//		case eKey::ENTER:
	//			break;
	//		}

	//		if (0 > iMovingCurser)
	//		{
	//			iMovingCurser = 0;
	//		}
	//		
	//		if (2 < iMovingCurser)
	//		{
	//			iMovingCurser = 2;
	//		}
	//		//Sleep(33);
	//		system("cls");
	//	}
	//	buffer->Release();


	//}
	}
}
void MainMenu::Flipping()
{
	buffer->Flipping();
}
void MainMenu::Release()
{
	buffer->Release();
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
	//DoubleBuffering buffer;

	int i = 0;
	for (i = 0; i < MAP_X; i++)
	{
		//GotoXY(MAP_ADJ_X + i, MAP_ADJ_Y, "■");
		buffer->BufferWrite(MAP_ADJ_X + i, MAP_ADJ_Y, "■");
	}

	for (i = (MAP_ADJ_Y + 1); i < (MAP_ADJ_Y + MAP_Y - 1); i++)
	{
		//GotoXY(MAP_ADJ_X, i, "■");
		buffer->BufferWrite(MAP_ADJ_X, i, "■");
		//GotoXY((MAP_ADJ_X + MAP_X - 1), i, "■");
		buffer->BufferWrite((MAP_ADJ_X + MAP_X - 1), i, "■");
	}

	for (i = 0; i < MAP_X; i++)
	{
		//GotoXY((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "■");.


		buffer->BufferWrite((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "■");
	}

}


void MainMenu::Textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}