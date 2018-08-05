#pragma once

#include "Character.h"

#include <map>

enum eJobType
{
	WARRIOR =2,
	ARCHER,
	WIZARD,
};

class Player
	: public Character
{
private:
	int iLv;
	int iStr;
	int iDex;
	int iInt;
	int iGold;
	std::map<std::pair<int, int>, std::string> mInventory;

public:
	Player();
	~Player();
public:
	void Init(int _number);
	void WarriorInit();
	void ArcherInit();
	void WizardInit();
public:
	int GetGold() { return iGold; }
	void SetGold(int _gold) { iGold = _gold; }
};

