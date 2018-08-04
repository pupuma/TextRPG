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
		std::cout << "1. �����ϱ� : " << std::endl;
		std::cout << "2. �̾��ϱ� : " << std::endl;
		std::cout << "3. ������ : " << std::endl;
		std::cout << "======================================" << std::endl;

		std::cout << "(1 ~ 3) ������ �ּ��� :  ";
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
			std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� ! " << std::endl;
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