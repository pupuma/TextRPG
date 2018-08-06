#include "StringQuit.h"

#include "SceneManager.h"

#include <conio.h>
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
	*isQuit = true;
	SceneManager::GetInstance()->ChangeScene(eScene::SCENE_VILLAGE,0);
}
