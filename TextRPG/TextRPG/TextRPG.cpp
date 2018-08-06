// TextRPG.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <windows.h>

#include "Scene.h"
#include "TitleScene.h"
#include "BeginningVillageScene.h"
#include "PlayerGenerationScene.h"
#include "GameSystem.h"
#include "SceneManager.h"


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
		SetCursorType(CURSOR_TYPE::NOCURSOR);
	}

	{
		
		int iNextIndex = -1;
		int iIndex = 0;
		GameSystem::GetInstance()->CharacterCreate(eCharacterType::PLAYER);
		GameSystem::GetInstance()->InitItemInfo();
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_DUNGEON, 0);

		while (1)
		{
			SceneManager::GetInstance()->Update();
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
