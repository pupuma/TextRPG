#include "TitleScene.h"

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "SceneManager.h"


TitleScene::TitleScene()
{
	
}

TitleScene::~TitleScene()
{

}

void TitleScene::Init(int _index)
{
}

void TitleScene::Update()
{
	int iPlayerSelect = 0;
	bool isStart = false;
	while (false == isStart)
	{
		std::cout << "======================================" << std::endl;
		std::cout << "1. 새로하기 : " << std::endl;
		std::cout << "2. 이어하기 : " << std::endl;
		std::cout << "3. 끝내기 : " << std::endl;
		std::cout << "======================================" << std::endl;

		std::cout << "(1 ~ 3) 선택해 주세요 :  ";
		std::cin >> iPlayerSelect;

		switch (iPlayerSelect)
		{
		case 1:
			SceneManager::GetInstance()->ChangeScene(eScene::SCENE_CREATECHACTER, 0);
			isStart = true;
			break;
		case 2:
			isStart = true;
			break;
		case 3:
			break;
		default:
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 ! " << std::endl;
			_getch();
			break;
		}
		
		system("cls");
	}
}

void TitleScene::GotoXY(int x, int y)
{
	COORD pos = { x ,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}