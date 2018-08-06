#include "Monster.h"



Monster::Monster()
{
	iHp = 100;
	iAttackPoint = 10;
	iDefensePoint = 10;
	iGold = 100;
	iExp = 10;
}


Monster::~Monster()
{
}

void Monster::SetName(std::string _name)
{
	sMonsterName = _name;
}

void Monster::Init(int _number)
{
}

void Monster::MonsterInit(int _number, Character * _player)
{
	switch (_number)
	{
	case 1:
		sMonsterName = "고블린";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp());
		SetAttackPoint(50);
		SetDefensePoint(20);
		break;
	case 2:
		sMonsterName = "슬라임";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp());
		SetAttackPoint(20);
		SetDefensePoint(20);
		break;
	case 3:
		sMonsterName = "오크";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp() *2);
		SetAttackPoint(150);
		SetDefensePoint(50);
		break;
	case 4:
		sMonsterName = "궁수 고블린";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + (GetHp()/2));
		SetAttackPoint(70);
		SetDefensePoint(30);
		break;
	case 5:
		sMonsterName = "미노타우르스";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp() + 1000);
		SetAttackPoint(300);
		SetDefensePoint(200);
		break;
	case 6:
		sMonsterName = " 쥐";
		SetName(sMonsterName);
		SetHp(50);
		SetAttackPoint(5);
		SetDefensePoint(5);
		break;
	case 7:
		sMonsterName = "좀비";
		SetName(sMonsterName);

		SetHp(50);
		SetAttackPoint(50);
		SetDefensePoint(0);
		break;
	case 8:
		sMonsterName = "도적";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp() * _player->GetLv());
		SetAttackPoint(20 + _player->GetStr() + _player->GetDex());
		SetDefensePoint(20 + _player->GetDex());
		break;
	case 9:
		sMonsterName = "마왕";
		SetHp(_player->GetHp() + (GetHp() + 1000 * _player->GetLv()));
		SetAttackPoint(500 + _player->GetStr() + _player->GetDex());
		SetDefensePoint(500 + _player->GetDex());
		break;
	default:
		break;
	}
}

int Monster::GetGold()
{
	return 0;
}

void Monster::SetGold(int _gold)
{
}

void Monster::Update()
{
}
