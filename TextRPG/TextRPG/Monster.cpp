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
		sMonsterName = "���";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp());
		SetAttackPoint(50);
		SetDefensePoint(20);
		break;
	case 2:
		sMonsterName = "������";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp());
		SetAttackPoint(20);
		SetDefensePoint(20);
		break;
	case 3:
		sMonsterName = "��ũ";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp() *2);
		SetAttackPoint(150);
		SetDefensePoint(50);
		break;
	case 4:
		sMonsterName = "�ü� ���";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + (GetHp()/2));
		SetAttackPoint(70);
		SetDefensePoint(30);
		break;
	case 5:
		sMonsterName = "�̳�Ÿ�츣��";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp() + 1000);
		SetAttackPoint(300);
		SetDefensePoint(200);
		break;
	case 6:
		sMonsterName = " ��";
		SetName(sMonsterName);
		SetHp(50);
		SetAttackPoint(5);
		SetDefensePoint(5);
		break;
	case 7:
		sMonsterName = "����";
		SetName(sMonsterName);

		SetHp(50);
		SetAttackPoint(50);
		SetDefensePoint(0);
		break;
	case 8:
		sMonsterName = "����";
		SetName(sMonsterName);
		SetHp(_player->GetHp() + GetHp() * _player->GetLv());
		SetAttackPoint(20 + _player->GetStr() + _player->GetDex());
		SetDefensePoint(20 + _player->GetDex());
		break;
	case 9:
		sMonsterName = "����";
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
