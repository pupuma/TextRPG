#include "StringNext.h"
#include "SceneManager.h"

#include <conio.h>
#include <iostream>

StringNext::StringNext()
{
}


StringNext::~StringNext()
{
}

void StringNext::Process(int* nextBranch, eScene type, bool* isQuit)
{
	Print();

	while (1)
	{
		char chText = _getche();
		std::cout << std::endl;
		if ('y' == chText || 'Y' == chText)
		{
			switch (type)
			{
			case eScene::SCENE_CREATECHACTER:
				SceneManager::GetInstance()->ChangeScene(eScene::SCENE_VILLAGE, 0);
				*isQuit = true;
				break;
			}
			break;
		}
		else if ('n' == chText || 'N' == chText)
		{
			*nextBranch = 1;
			break;
		}
		else
		{
			std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� " << std::endl;
		}
	}
	
	
}
