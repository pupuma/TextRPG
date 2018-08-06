#include "GameSystem.h"

#include "ParsingSystem.h"
#include "Player.h"

#include <iostream>

GameSystem* GameSystem::_instance = 0;



GameSystem::GameSystem()
{
}


GameSystem::~GameSystem()
{
}

GameSystem* GameSystem::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new GameSystem();
	}
	return _instance;
}

void GameSystem::CharacterCreate(eCharacterType type)
{
	switch (type)
	{
	case eCharacterType::PLAYER:
		_character = new Player();
		break;
	}
}

void GameSystem::PlayerInit(int _number)
{
	_character->Init(_number);
}

void GameSystem::SetPlayerName(std::string _name)
{
	_character->SetName(_name);
}

void GameSystem::InitItemInfo()
{
	_parser = new ParsingSystem();

	_parser->ItemTableCSVParsing("RecoveryItemTable.csv", &vRecveryInfo);
	_parser->ItemTableCSVParsing("ArmsItemTable.csv", &vArmsInfo);
	_parser->ItemTableCSVParsing("DefensiveItemTable.csv", &vDefensiveInfo);

}


void GameSystem::FindinventoryInfoView(std::list<std::pair<std::string, int>>* vInventory, int _iSelect, sEquipment* _eq)
{
	std::list<std::pair<std::string, int>>::iterator it;
	std::vector<sData>::iterator iter;

	int i = 1;
	bool isWear = false;
	std::cout << "======��ȣ=====�����۸�====����=====����====" << std::endl;

	switch (_iSelect)
	{
	case 1:
		for (it = vInventory->begin(); it != vInventory->end(); it++, i++)
		{
			// vRecveryInfo
			for (iter = vRecveryInfo.begin(); iter != vRecveryInfo.end(); iter++)
			{
				if (it->first == iter->sNameInfo)
				{
					std::cout << " [ " << i << " ] " << " [ " << it->first << " ] " << " [ " << isWear << " ] " <<
						" [ " << iter->iHpInfo << " ] " << " [ " << iter->iMpInfo << " ] " <<
						" [ " << iter->iLevelUpInfo << " ] " << " [ " << iter->sTextInfo << " ] " << std::endl;
				}
			}
		}
		break;
	case 2:
		for (it = vInventory->begin(); it != vInventory->end(); it++, i++)
		{

			// vArmsInfo
			for (iter = vArmsInfo.begin(); iter != vArmsInfo.end(); iter++)
			{
				if (it->first == iter->sNameInfo)
				{
					if (it->first == iter->sNameInfo)
					{
						std::cout << " [ " << i << " ] " << " [ " << it->first << " ] " << " [ " << isWear << " ] " <<
							" [ " << iter->iAttackPointInfo << " ] " << " [ " << iter->iDefensiveInfo << " ] " <<
							" [ " << iter->iLevelUpInfo << " ] " << " [ " << iter->sTextInfo << " ] " << std::endl;
					}
				}
			}

		}
		break;
	case 3:
		for (it = vInventory->begin(); it != vInventory->end(); it++, i++)
		{
			// vDefensiveInfo
			for (iter = vDefensiveInfo.begin(); iter != vDefensiveInfo.end(); iter++)
			{
				if (it->first == iter->sNameInfo)
				{
					if (it->first == iter->sNameInfo)
					{
						std::cout << " [ " << i << " ] " << " [ " << it->first << " ] " << " [ " << isWear << " ] " <<
							" [ " << iter->iStrInfo << " ] " << " [ " << iter->iDexInfo << " ] " <<
							" [ " << iter->iIntInfo << " ] " << " [ " << iter->sTextInfo << " ] " << std::endl;
					}
				}
			}
		}
		break;
	}

	std::string sName;
	char chText;
	bool _isQuit = false;
	if (2 == _iSelect)
	{
		while (false == _isQuit)
		{
			std::cout << "��� �����Ͻðڽ��ϱ�? ( y / n) : ";
			std::cin >> chText;
			if ('y' == chText || 'Y' == chText)
			{
				std::cout << "--------------------------------" << std::endl;
				std::cout << "�κ� �丮 �� �ִ� ������ �Է��� �ּ��� : ";
				std::cin >> sName;
				for (it = vInventory->begin(); it != vInventory->end(); it++)
				{
					for (iter = vArmsInfo.begin(); iter != vArmsInfo.end(); iter++)
					{
						if (it->first == iter->sNameInfo)
						{
							if (sName == it->first)
							{
								if (true == isWear)
								{
									_character->ChangeWear(_eq,sName, _iSelect);
									_character->ChangeWearState(iter->iAttackPointInfo, iter->iDefensiveInfo, iter->iStrInfo, iter->iDexInfo, iter->iIntInfo);
									break;
								}
								else
								{
									isWear = true;
									_character->CharacterWear(_eq, sName, _iSelect);
									_character->ChangeWearState(iter->iAttackPointInfo, iter->iDefensiveInfo, iter->iStrInfo, iter->iDexInfo, iter->iIntInfo);
									break;
								}

							}
						}
					}
				}
				_isQuit = true;

			}
			else if ('n' == chText || 'N' == chText)
			{
				_isQuit = true;
				break;
			}
			else
			{
				std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}
	}
	else if (3 == _iSelect)
	{
		while (false == _isQuit)
		{
			std::cout << "��� �����Ͻðڽ��ϱ�? ( y / n) : ";
			std::cin >> chText;
			if ('y' == chText || 'Y' == chText)
			{
				std::cout << "--------------------------------" << std::endl;
				std::cout << "�κ� �丮 �� �ִ� ������ �Է��� �ּ��� : ";
				std::cin >> sName;
				for (it = vInventory->begin(); it != vInventory->end(); it++)
				{
					for (iter = vDefensiveInfo.begin(); iter != vDefensiveInfo.end(); iter++)
					{
						if (it->first == iter->sNameInfo)
						{
							if (sName == it->first)
							{
								if (true == isWear)
								{
									_character->ChangeWear(_eq, sName, _iSelect);
									_character->ChangeWearState(iter->iAttackPointInfo, iter->iDefensiveInfo, iter->iStrInfo, iter->iDexInfo, iter->iIntInfo);
									break;
								}
								else
								{
									isWear = true;
									_character->CharacterWear(_eq, sName, _iSelect);
									_character->ChangeWearState(iter->iAttackPointInfo, iter->iDefensiveInfo, iter->iStrInfo, iter->iDexInfo, iter->iIntInfo);
									break;
								}

							}
						}
					}
				}
			}
			else if ('n' == chText || 'N' == chText)
			{
				_isQuit = true;
				break;
			}
			else
			{
				std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}
	}
	system("cls");
}

void GameSystem::Battle(Character * _player, Character* _monster, int _rand, int* nextBranch, bool* isQuit)
{
	if (0 == _rand)
	{
		std::cout << "�ƹ��� ������ �ʾҴ�. ! �����ߴ�.." << std::endl;
		return;
	}
	
	std::cout << _monster->GetName() << " �� �������ϴ�! ";

	char chText;
	while (1)
	{
		std::cout << _monster->GetName() << " �� ������ �Ͻðڽ��ϱ�? " << std::endl;
		std::cin >> chText;
		if ('Y ' == chText || 'Y' == chText)
		{
			std::cout << "������ ���۵Ǿ����ϴ�!" << std::endl;
			if (_monster->GetAttackPoint() > _player->GetAttackPoint())
			{
				
			}
			else
			{

			}
		}
		else if ('n' == chText || 'N' == chText)
		{
			*nextBranch = 10;
			break;
		}
	
	}

}
