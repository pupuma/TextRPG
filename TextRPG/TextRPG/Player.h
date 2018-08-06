#pragma once

#include "Character.h"


enum eJobType
{
	NONE,
	WARRIOR = 2,
	ARCHER,
	WIZARD,
};


class Player
	: public Character
{
private:
	std::string sPlayerName;
	eJobType jobType;
	int iLv;
	int iStr;
	int iDex;
	int iInt;
	int iGold;
	int iStatePoint;
	int iInvenSize;
	int iExp;
	sEquipment* eq;

public:
	Player();
	~Player();
public:
	void SetName(std::string _name);
	void Init(int _number);
	void WarriorInit(eJobType type);
	void ArcherInit(eJobType type);
	void WizardInit(eJobType type);
public:
	int GetGold() { return iGold; }
	void SetGold(int _gold) { iGold = _gold; }
	void AddInventory(std::list<Item>::iterator& it);
	void InventoryView();
	void InventoryInfoView(int _iSelect, sEquipment* _eq);

	int GetInventorySize();
	int DeleteInventoryItem(int iPlayerSelect);
	int DeleteInventoryItem(std::string _name);

public:
	void PlayerState();
	void CharacterInfo();
	void CharacterEquipment(sEquipment* _eq);
	void CharacterInventory(sEquipment* _eq);
	void StateUp();
	
public:
	eJobType GetjobType() { return jobType; }
	int GetHp() { return iHp; }
	int GetMp() { return iMp; }
	int GetAttackPoint() { return iAttackPoint; }
	int GetDefensePoint() { return iDefensePoint; }
	int GetLv() { return iLv; }
	int GetStr() { return iStr; }
	int GetDex() { return iDex; }
	int GetInt() { return iInt; }
	int GetStatePoint() { return iStatePoint; }

	void SetHp(int _hp) { iHp = _hp; }
	void SetMp(int _mp) { iMp = _mp; }
	void SetAttackPoint(int _point) { iAttackPoint = _point; }
	void SetDefensePoint(int _point) { iDefensePoint = _point; }
	void SetLv(int _lv) { iLv = _lv; }
	void SetStr(int _str) { iStr = _str; }
	void SetDex(int _dex) { iDex = _dex; }
	void SetInt(int _int) { iInt =_int; }
	void SetStatePoint(int _point) { iStatePoint = _point; }
public:
	void CharacterWear(sEquipment* _eq, std::string sName ,int _iSelect);
	void ChangeWear(sEquipment* _eq, std::string sName, int _iSelect);
	void ChangeWearState( int iAttackPointInfo, int iDefensiveInfo, int iStrInfo, int iDexInfo, int iIntInfo);
public:
	void Update();
	void WarriorStateUpdate();
	void ArcherStateUpdate();
	void WizardStateUpdate();
};

