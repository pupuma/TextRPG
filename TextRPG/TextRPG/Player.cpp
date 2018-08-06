#include "Player.h"
#include <iostream>

#include "GameSystem.h"

Player::Player()
{
	iGold = 1000;
	iInvenSize = 0;
	iStatePoint = 10;
	jobType = eJobType::NONE;
	iExp = GetLv() * 1000 + GetStr() + GetDex() + GetInt();

	eq = new sEquipment();
}


Player::~Player()
{
}

void Player::SetName(std::string _name)
{
	sPlayerName = _name;
}

void Player::Init(int _number)
{
	switch ((eJobType)_number)
	{
	case eJobType::WARRIOR:
		WarriorInit(eJobType::WARRIOR);
		break;
	case eJobType::ARCHER:
		ArcherInit(eJobType::ARCHER);
		break;
	case eJobType::WIZARD:
		WizardInit(eJobType::WIZARD);
		break;
	}
}

void Player::WarriorInit(eJobType type)
{
	jobType = type;
	iLv = 1;
	iStr = 10;
	iDex = 5;
	iInt = 5;
}

void Player::ArcherInit(eJobType type)
{
	jobType = type;
	iLv = 1;
	iStr = 5;
	iDex = 10;
	iInt = 5;
}

void Player::WizardInit(eJobType type)
{

	jobType = type;
	iLv = 1;
	iStr = 5;
	iDex = 5;
	iInt = 10;
}

void Player::AddInventory(std::list<Item>::iterator& it)
{
	if (iInvenSize > 30)
	{
		std::cout << " 가방의 크기를 초과 했습니다! " << std::endl;
		return;
	}
	else
	{
		std::pair<std::string,int> pKey;
		pKey.first = it->sItemName;
		pKey.second = it->iPrice /2;
		vInventory.push_back(pKey);
		iInvenSize++;
	}
	
}

void Player::InventoryView()
{
	//std::list<std::string>::iterator it;
	std::list<std::pair<std::string,int>>::iterator it;
	int i = 1;
	std::cout << "======번호==아이템명====가격=======" << std::endl;
	for (it = vInventory.begin(); it != vInventory.end(); it++,i++)
	{
		std::cout << i << "\t" << it->first << "\t" << it->second << std::endl;
	}
	system("pause");
}

void Player::InventoryInfoView(int _iSelect, sEquipment* _eq)
{
	{
		GameSystem::GetInstance()->FindinventoryInfoView(&vInventory, _iSelect, _eq);
	}
}


int Player::GetInventorySize()
{
	return vInventory.size();
}

int Player::DeleteInventoryItem(int iPlayerSelect)
{
	if (0 == vInventory.size())
	{
		std::cout << " 아무것도 없습니다! " << std::endl;
		return 0;
	}
	std::list<std::pair<std::string, int>>::iterator it;
	int iGold;
	int iIndex = 1;
	for (it = vInventory.begin(); it != vInventory.end(); it++,iIndex++)
	{
		if (iPlayerSelect == iIndex)
		{
			iGold = it->second;
			vInventory.pop_back();
		}
		if (0 == vInventory.size())
		{
			break;
		}
		
	}
	InventoryView();

	return iGold;
}

int Player::DeleteInventoryItem(std::string _name)
{
	if (0 == vInventory.size())
	{
		std::cout << " 아무것도 없습니다! " << std::endl;
		return 0;
	}
	std::list<std::pair<std::string, int>>::iterator it;
	int iGold;
	int iIndex = 1;
	for (it = vInventory.begin(); it != vInventory.end(); it++, iIndex++)
	{
		if (it->first == _name )
		{
			vInventory.pop_back();
		}
		if (0 == vInventory.size())
		{
			break;
		}

	}
	//InventoryView();

	return 0;
}

void Player::PlayerState()
{
	system("cls");

	std::cout << "=======================================" << std::endl;
	
	// 캐릭터 정보
	int iSelect;
	bool isQuit = false;
	while (false == isQuit)
	{
		std::cout << "1. 캐릭터 정보 / 2. 캐릭터 장비 / 3. 캐릭터 가방 / 4. 돌아가기" << std::endl;
		std::cout << "숫자를 입력해 주세요 : ";
		std::cin >> iSelect;
		
		switch (iSelect)
		{
		case 1:
			CharacterInfo();
			break;
		case 2:
			CharacterEquipment(eq);
			break;
		case 3:
			CharacterInventory(eq);
			break;
		case 4:
			system("cls");
			isQuit = true;
			break;
		default:
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
}

void Player::CharacterInfo()
{
	system("cls");

	Update();
	std::cout << "=======================================" << std::endl;
	std::cout << "PlayerName : " << sPlayerName <<std::endl;
	//std::cout << "       JOB : " << GetjobType() << std::endl;
	switch (GetjobType())
	{
	case eJobType::WARRIOR:
		std::cout << "       JOB : " << " 전 사 " << std::endl;
		break;
	case eJobType::ARCHER:
		std::cout << "       JOB : " << " 궁 수 " << std::endl;
		break;
	case eJobType::WIZARD:
		std::cout << "       JOB : " << " 마 법 사 " << std::endl;
		break;
	}
	std::cout << "        Lv : " << GetLv() << std::endl;
	std::cout << "        HP : " << GetHp() << std::endl;
	std::cout << "        MP : " << GetMp() << std::endl;
	std::cout << "    ATTACK : " << GetAttackPoint() << std::endl;
	std::cout << "   DEFENSE : " << GetDefensePoint() << std::endl;
	std::cout << "       STR : " << GetStr() << std::endl;
	std::cout << "       DEX : " << GetDex() << std::endl;
	std::cout << "       INT : " << GetInt() << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << "StatePoint : " << GetStatePoint()<<std::endl;
	std::cout << "=======================================" << std::endl;
	
	system("pause");
	
	if (0 == GetStatePoint())
	{
		return;
	}
	else
	{
		char chText;
		while (1)
		{

			std::cout << "스텟포인트가 " << GetStatePoint() << " 있습니다.. 스텟을 찍겠습니까?? ( y / n )" << std::endl;
			std::cin >> chText;

			if ('y' == chText || 'Y' == chText)
			{
				StateUp();
			}
			else if ('n' == chText || 'N' == chText)
			{
				break;
			}

			if (0 == GetStatePoint())
			{
				std::cout << "포인트가 없습니다!" << std::endl;
				break;
			}
		}
	}

	system("cls");

}

void Player::CharacterEquipment(sEquipment* _eq)
{
	// 장비창
	system("cls");
	std::cout << "----방어구----" << std::endl;
	std::cout << " 머    리 : " << " [ "<<_eq->sHeadGear << " ] " << std::endl;
	std::cout << " 상    의 : " << " [ " << _eq->sChestGear << " ] " << std::endl;
	std::cout << " 하    의 : " << " [ " << _eq->sPantsGear << " ] " << std::endl;
	std::cout << " 신   발  : " << " [ " <<_eq->sShoesGear << " ] " << std::endl;
	std::cout << "----무  기----" << std::endl;
	std::cout << " 오 른 손 : " << " [ " << _eq->sRighthandGear << " ] " << std::endl;
	std::cout << " 왼    손 : " << " [ " << _eq->sLeftHandGear << " ] " << std::endl;
	system("pause");
	system("cls");
}

void Player::CharacterInventory(sEquipment* _eq)
{
	// 인벤토리 창 
	system("cls");

	if (0 == GetInventorySize())
	{
		std::cout << "아무 것도 없습니다.." << std::endl;
		system("pause");
		system("cls");
		return;
	}
	int iSelect;
	bool _isQuit;
	

	while (1)
	{
		std::cout << "=======================================" << std::endl;
		std::cout << "1. 소모품 , 2. 무기 , 3. 장비 : , 4. 나가기 " << std::endl;
		std::cout << "=======================================" << std::endl;

		std::cout << "어느 가방으로 이동 하시겠습니까?";
		std::cin >> iSelect;

		if (1 == iSelect)
		{
			InventoryInfoView(iSelect, _eq);
		}
		else if (2 == iSelect)
		{
			InventoryInfoView(iSelect, _eq);
		}
		else if (3 == iSelect)
		{
			InventoryInfoView(iSelect, _eq);
		}
		else if (4 == iSelect)
		{
			break;
		}
		else if (std::cin.fail())
		{
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else
		{
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
	}

	system("cls");

}

void Player::StateUp()
{
	//
	system("cls");

	int iSelect;
	int iPointUp;

	int iStrPoint;
	int iDexPoint;
	int iIntPoint;
	int iPoint;

	while (1)
	{
		std::cout <<"현재 스텟포인트 ! : "<< GetStatePoint()<< std::endl;
		std::cout << "1. 힘 / 2. 민첩 / 3. 지능 " << std::endl;
		std::cout << "어느곳에 포인트를 올리겠습니까? :" ;
		std::cin >> iSelect;

		
		if(1 == iSelect)
		{
			std::cout << "몇 포인트를 올리겠습니까? :";
			std::cin >> iPointUp;

			if (GetStatePoint() < iPointUp || std::cin.fail())
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			else
			{
				iStrPoint = GetStr();
				iStrPoint = iStrPoint + iPointUp;
				SetStr(iStrPoint);
				iPoint = GetStatePoint() - iPointUp;
				SetStatePoint(iPoint);
			}
			
		}
		else if (2 == iSelect)
		{
			std::cout << "몇 포인트를 올리겠습니까? :";
			std::cin >> iPointUp;

			
			if (GetStatePoint() < iPointUp || std::cin.fail())
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			else
			{
				iDexPoint = GetDex();
				iDexPoint = iDexPoint + iPointUp;
				SetDex(iDexPoint);
				iPoint = GetStatePoint() - iPointUp;
				SetStatePoint(iPoint);
			}
		}
		else if (3 == iSelect)
		{
			std::cout << "몇 포인트를 올리겠습니까? :";
			std::cin >> iPointUp;

			if (GetStatePoint() < iPointUp || std::cin.fail())
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			else
			{
				iIntPoint = GetInt();
				iIntPoint = iIntPoint + iPointUp;
				SetInt(iIntPoint);
				iPoint = GetStatePoint() - iPointUp;
				SetStatePoint(iPoint);
			}
		}
		else
		{
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		// 스텟 초기화 
		if (0 == GetStatePoint())
		{
			break;
		}
	}
}

void Player::CharacterWear(sEquipment* _eq,std::string sName, int _iSelect)
{

	int iHandSelect;
	if (2 == _iSelect)
	{
		while (1)
		{
			std::cout << "1. 오른손 / 2. 왼손 " << std::endl;
			std::cin >> iHandSelect;

			if (1 == iHandSelect)
			{

				if (false == _eq->IsRighthandGear)
				{
					_eq->sRighthandGear = sName;
					_eq->IsRighthandGear = true;
					break;
				}
			}
			else if (2 == iHandSelect)
			{
				if (false == _eq->IsLeftHandGear)
				{
					_eq->sLeftHandGear = sName;
					_eq->IsRighthandGear = true;
					break;
				}
			}
			else if (std::cin.fail())
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			else
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}
		
	}
	else if (3 == _iSelect)
	{
		if (false == _eq->IsHeadGear)
		{
			_eq->sHeadGear = sName;
			_eq->IsHeadGear = true;

		}
		else if (false == _eq->IsChestGear)
		{
			_eq->sChestGear = sName;
			_eq->IsChestGear = true;
		}
		else if (false == _eq->IsPantsGear)
		{
			_eq->sPantsGear = sName;
			_eq->IsPantsGear = true;
		}
		else if (false == _eq->IsShoesGear)
		{
			_eq->sShoesGear = sName;
			_eq->IsShoesGear = true;
		}
	}
	
}

void Player::ChangeWear(sEquipment* _eq, std::string sName, int _iSelect)
{
	int iHandSelect;


	if (2 == _iSelect)
	{
		while (1)
		{
			std::cout << "1. 오른손 / 2. 왼손 " << std::endl;
			std::cin >> iHandSelect;

			if (1 == iHandSelect)
			{
				if (true == _eq->IsRighthandGear)
				{
					DeleteInventoryItem(_eq->sRighthandGear);

					_eq->sRighthandGear = sName;
					_eq->IsRighthandGear = true;
					break;
				}
			}
			else if (2 == iHandSelect)
			{
				if (true == _eq->IsLeftHandGear)
				{
					DeleteInventoryItem(_eq->sLeftHandGear);

					_eq->sLeftHandGear = sName;
					_eq->IsRighthandGear = true;
					break;
				}
			}
			else if (std::cin.fail())
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			else
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}

	}
	else if (3 == _iSelect)
	{
		if (true == _eq->IsHeadGear)
		{
			DeleteInventoryItem(_eq->sHeadGear);

			_eq->sHeadGear = sName;
			_eq->IsHeadGear = true;

		}
		else if (true == _eq->IsChestGear)
		{
			DeleteInventoryItem(_eq->sChestGear);

			eq->sChestGear = sName;
			eq->IsChestGear = true;
		}
		else if (true == _eq->IsPantsGear)
		{
			DeleteInventoryItem(_eq->sPantsGear);

			_eq->sPantsGear = sName;
			_eq->IsPantsGear = true;
		}
		else if (true == _eq->IsShoesGear)
		{
			DeleteInventoryItem(_eq->sShoesGear);

			_eq->sShoesGear = sName;
			_eq->IsShoesGear = true;
		}
	}
}

void Player::ChangeWearState(int iAttackPointInfo, int iDefensiveInfo, int iStrInfo, int iDexInfo, int iIntInfo)
{
	SetAttackPoint(GetAttackPoint() + iAttackPointInfo);
	SetDefensePoint(GetDefensePoint() + iDefensiveInfo);
	SetStr(GetStr() + iStrInfo);
	SetDex(GetDex() + iDexInfo);
	SetInt(GetInt() + iIntInfo);

}

void Player::Update()
{
	switch (GetjobType())
	{
	case eJobType::WARRIOR:
		WarriorStateUpdate();
		break;
	case eJobType::ARCHER:
		ArcherStateUpdate();
		break;
	case eJobType::WIZARD:
		WizardStateUpdate();
		break;
	}
	
}

void Player::WarriorStateUpdate()
{
	int iAttack = GetAttackPoint() + GetStr() * GetLv();
	int iHp = GetHp() + GetStr() + 10;
	int iMp = GetMp() + GetInt();
	SetAttackPoint(iAttack);
	SetHp(iHp);
	SetMp(iMp);

}

void Player::ArcherStateUpdate()
{
	int iAttack = GetAttackPoint() + (GetDex()/2) * GetLv();
	int iDef = GetDefensePoint() + ((GetDex() / 5) + 2);
	int iHp = GetHp() + GetStr() + 3;
	int iMp = GetMp() + GetInt();
	SetAttackPoint(iAttack);
	SetDefensePoint(iDef);
	SetHp(iHp);
	SetMp(iMp);
}

void Player::WizardStateUpdate()
{
	int iAttack = GetAttackPoint() + (GetInt()/3) * GetLv();
	int iHp = GetHp() + GetStr() + 3;
	int iMp = GetMp() + GetInt() +10;
	SetAttackPoint(iAttack);
	SetHp(iHp);
	SetMp(iMp);
}
