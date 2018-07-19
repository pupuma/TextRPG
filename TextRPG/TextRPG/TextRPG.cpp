// TextRPG.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <windows.h>
#include "MainGame.h"
#include "MainMenu.h"



const int COMMAND = 256;

typedef enum
{
	NOCURSOR,
	SOLIDCURSOR,
	NORMALCURSOR,

}CURSOR_TYPE;

void ConsoleWindowSize(int _cols, int _lines);
void SetCursorType(CURSOR_TYPE _c);



int main()
{
	{
		// 콘솔창 크기 지정
		Console* con = new Console;

		ConsoleWindowSize(con->CON_WIDTH,con->CON_HIGHT);
		SetCursorType(CURSOR_TYPE::NOCURSOR);
		delete con;
	}
	{
		// 메인 메뉴 설정 
		MainMenu* mainMenu = new MainMenu();

		while (1)
		{
			
			mainMenu->Clear();
			mainMenu->Render();

			mainMenu->Flipping();
			mainMenu->Update();

		}

		mainMenu->Release();
		{
			//int nDir = 1;
			//int x = (MAP_X - 5);
			//system("cls");
			//while (true)
			//{
			//	if (_kbhit())
			//	{
			//		break;
			//	}
			//	DrawMap();
			//	//x += 3 * nDir;
			//	//if ((x <= 3) || (x > (MAP_X - 5)))
			//	//{
			//	//	nDir *= -1;
			//	//	continue;
			//	//}
			//	//GotoXY(x, (MAP_ADJ_Y + 5), sztitle);
			//	Sleep(33);
			//	system("cls");
			//}
		}
		
	}
	_getch();

    return 0;
}

void ConsoleWindowSize(int _cols, int _lines)
{
	char chCommand[COMMAND] = { 0, };
	int iLines = _lines;
	int iCols = _cols;

	sprintf_s(chCommand, "Mode con:cols=%d  lines=%d", iCols, iLines);
	system(chCommand);
}


void SetCursorType(CURSOR_TYPE _c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (_c)
	{
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = FALSE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}
