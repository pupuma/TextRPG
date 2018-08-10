#pragma once

#include "Character.h"

class Monster
	: public Character
{
private:
	std::string sMonsterName;
	int iExp;
public:
	Monster();
	~Monster();
public:
	void SetName(std::string _name);
	std::string GetName() { return sMonsterName; }
	void Init(int _number);
	void Init(int _number, Character* _player);
	int GetGold();
	void SetGold(int _gold);
	void Update();
public:
	int GetHp() { return iHp; }
	void SetHp(int _hp) { iHp = _hp; }

	int GetAttackPoint() { return iAttackPoint; }
	void SetAttackPoint(int _point) { iAttackPoint = _point; }

	int GetDefensePoint() { return iDefensePoint; }
	void SetDefensePoint(int _point) { iDefensePoint = _point; }

	int GetExp() { return iExp; }
	void SetExp(int _exp) { iExp = _exp; }
};

