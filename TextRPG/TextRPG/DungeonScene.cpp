#include "DungeonScene.h"

#include <iostream>
#include <conio.h>

#include "GameSystem.h"
#include "SceneManager.h"
#include "ParsingSystem.h"
#include "sParagraph.h"

DungeonScene::DungeonScene()
{
	_player = GameSystem::GetInstance()->GetCharacter();
}


DungeonScene::~DungeonScene()
{
	parser = new ParsingSystem();
	iBranch = 0;
	isQuit = false;
}

void DungeonScene::Init(int _index)
{
	system("cls");
	pargraphCount = 0;
	SetSceneType(eScene::SCENE_DUNGEON);

	paragraphList = parser->CSVParsing("DungeonScene.csv", &pargraphCount);

	std::cout << "<<던전에 입장하였습니다.>>" << std::endl;
	std::cout << "플레이어 레벨에 비례해서 적이 나타납니다." << std::endl;
	_getch();
}

void DungeonScene::Update()
{
	char chText;

	while (1)
	{
		std::cout << "던전 안으로 들어가시겠습니까? ( y / n )" ;
		std::cin >> chText;

		if ('y' == chText || 'Y' == chText)
		{
			DungeonStart();
		}
		else if ('n ' == chText || 'N' == chText)
		{
			SceneManager::GetInstance()->ChangeScene(eScene::SCENE_VILLAGE, 0);
		}
		else if (std::cin.fail())
		{
			std::cout << "잘못된 값을 입력 했습니다. 다시 입력해 주세요 !" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else
		{
			std::cout << "잘못된 값을 입력 했습니다. 다시 입력해 주세요 !" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
	}
}

void DungeonScene::DungeonStart()
{
	while (false == isQuit)
	{
		if (iBranch < pargraphCount)
		{
			paragraphList[iBranch].Process(&iBranch, sceneType, &isQuit);
		}
	}
}
