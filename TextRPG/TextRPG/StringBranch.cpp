#include "StringBranch.h"
#include <conio.h>
#include <iostream>

#include "GameSystem.h"
#include "Character.h"
StringBranch::StringBranch()
{
}


StringBranch::~StringBranch()
{
}

void StringBranch::Process(int* nextBranch, eScene type, bool * isQuit)
{
	Print();

	int selectBranch = 0;
	while (true)
	{
		std::cout << "������ ��ȣ�� ? : ";

		std::cin >> selectBranch;
		if (type == eScene::SCENE_CREATECHACTER)
		{
			if (2 == selectBranch)
			{
				*nextBranch = selectBranch;
				GameSystem::GetInstance()->PlayerInit(selectBranch);
				break;
			}
			else if (3 == selectBranch)
			{
				*nextBranch = selectBranch;
				GameSystem::GetInstance()->PlayerInit(selectBranch);
				break;
			}
			else if (4 == selectBranch)
			{
				*nextBranch = selectBranch;
				GameSystem::GetInstance()->PlayerInit(selectBranch);

				break;
			}
			else
			{
				std::cout << "�߸��� ������ �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� !!" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			//
		}
		else if (type == eScene::SCENE_VILLAGE)
		{
			if (2 == selectBranch)
			{
				*nextBranch = selectBranch;
				break;
			}
			else if (3 == selectBranch)
			{
				*nextBranch = selectBranch;
				break;
			}
			else
			{
				std::cout << "�߸��� ������ �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� !!" << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}
	}

	std::cin.clear();
	std::cin.ignore();
}
