#include "StringQuit.h"

#include <conio.h>

#include "SceneManager.h"

StringQuit::StringQuit()
{
}


StringQuit::~StringQuit()
{
}

void StringQuit::Process(int * nextBranch, eScene type, bool * isQuit)
{
	Print();
	_getch();

	if (type == eScene::SCENE_CREATECHACTER)
	{
		*isQuit = true;
		SceneManager::GetInstance()->Release();
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_VILLAGE);
	}
	else if (type == eScene::SCENE_DUNGEON)
	{
		*isQuit = true;
		SceneManager::GetInstance()->Release();
		SceneManager::GetInstance()->ChangeScene(eScene::SCENE_VILLAGE);

	}
	

}
