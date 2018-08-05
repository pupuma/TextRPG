#include "Player.h"



Player::Player()
{
	iGold = 1000;
}


Player::~Player()
{
}

void Player::Init(int _number)
{
	switch ((eJobType)_number)
	{
	case eJobType::WARRIOR:
		WarriorInit();
		break;
	case eJobType::ARCHER:
		ArcherInit();
		break;
	case eJobType::WIZARD:
		WizardInit();
		break;
	}
}

void Player::WarriorInit()
{
	iLv = 1;
	iStr = 10;
	iDex = 5;
	iInt = 5;
}

void Player::ArcherInit()
{
	iLv = 1;
	iStr = 5;
	iDex = 10;
	iInt = 5;
}

void Player::WizardInit()
{
	iLv = 1;
	iStr = 5;
	iDex = 5;
	iInt = 10;
}
