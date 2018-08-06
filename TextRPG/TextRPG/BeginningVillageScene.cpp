#include "BeginningVillageScene.h"

#include <conio.h>
#include <iostream>
#include <time.h>

#include "ParsingSystem.h"
#include "sParagraph.h"
#include "Item.h"
#include "GeneralStore.h"
#include "ArmsStore.h"
#include "DefensiveStore.h"
#include "GameSystem.h"
#include "Character.h"



BeginningVillageScene::BeginningVillageScene()
{
	iRand = 0;
	iBranch = 0;
	isQuit = false;
	parser = new ParsingSystem();
	_character = GameSystem::GetInstance()->GetCharacter();
	
}

BeginningVillageScene::~BeginningVillageScene()
{

}

void BeginningVillageScene::Init(int _index)
{
	system("cls");

}

void BeginningVillageScene::Update()
{
	srand((unsigned)time(NULL));
	
	iSelect = 0;
	while (1)
	{
		InitMap();

		std::cout << " ( 1 ~ 6 ) 선택해 주세요 : ";
		std::cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			InitVillage(iRand);
			break;
		case 2:
			InitStore();
			break;
		case 3:
			break;
		case 4:
			SceneManager::GetInstance()->ChangeScene(eScene::SCENE_DUNGEON, 0);
			break;
		case 5:
			_character->PlayerState();
			break;
		case 6:
			break;
		default:
			std::cout << "잘못된 값을 입력 했습니다. 다시 입력해 주세요 !!" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			system("cls");

			break;
		}

		if (1 <= iSelect || 6 >= iSelect)
		{
			break;
		}

	}

}

void BeginningVillageScene::InitMap()
{
	std::cout << "=======================================" << std::endl;
	std::cout << "1. 마을 " << std::endl;
	std::cout << "2. 상점 " << std::endl;
	std::cout << "3. 여관 " << std::endl;
	std::cout << "4. 던전 " << std::endl;
	std::cout << "5. 상태 " << std::endl;
	std::cout << "6. 종료 " << std::endl;
	std::cout << "=======================================" << std::endl;
}

void BeginningVillageScene::InitVillage(int iRandom)
{
	pargraphCount = 0;
	paragraphList = parser->CSVParsing("BeginningVillage.csv", &pargraphCount);
	SetSceneType(eScene::SCENE_CREATECHACTER);
	VillageUpdate(iRandom);
}

void BeginningVillageScene::VillageUpdate(int iRandom)
{
	while (false == isQuit)
	{
		iRandom = rand() % 10;

		if (iBranch < pargraphCount)
		{
			paragraphList[iBranch].Process(&iBranch, sceneType, &isQuit);

			if (3 == iBranch)
			{
				if (7 == iRandom)
				{
					iBranch = 4;
				}

			}

		}

	}

	system("cls");
	InitMap();
}

void BeginningVillageScene::InitStore()
{
	system("cls");

	Item* item = new Item();
	Store* store = 0;
	//

	//
	while (1)
	{
		std::cout << "1. 잡화상점 2. 무기 상점 3. 방어구 상점 " << std::endl;
		std::cout << "어느 상점으로 이동 하시겠습니까? " << std::endl;
		std::cin >> iSelect;

		if (1 == iSelect)
		{
			store = new GeneralStore();
			store->ItemInit();
			break;
		}
		else if (2 == iSelect)
		{
			store = new ArmsStore();
			store->ItemInit();
			break;
		}
		else if (3 == iSelect)
		{
			store = new DefensiveStore();
			store->ItemInit();
			break;
		}
		else
		{
			std::cout << "잘못된 값을 입력 했습니다. 다시 입력해 주세요 !" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
	}
	
	store->EnterStore(_character);
}
 