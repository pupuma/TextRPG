#pragma once
//#include <map>
#include <list>
#include <string>

#include "Item.h"


struct sEquipment
{
	// 방어구
	std::string sHeadGear;
	std::string sChestGear;
	std::string sPantsGear;
	std::string sShoesGear;

	//
	bool IsHeadGear = false;
	bool IsChestGear = false;
	bool IsPantsGear = false;
	bool IsShoesGear = false;

	// 오른손 왼손
	std::string sRighthandGear;
	std::string sLeftHandGear;

	//
	bool IsRighthandGear = false;
	bool IsLeftHandGear = false;
};


class Character
{
protected:
	int iHp;
	int iMp;
	int iAttackPoint;
	int iDefensePoint;
	int iGold;
protected:
	//std::pair<int, int> pKey;
	//std::map<std::pair<int, int>, std::string> mInventory;
	//std::list<std::string> vInventory;
	std::list<std::pair< std::string,int>>vInventory;
public:
	Character();
	~Character();
public:
	virtual void SetName(std::string _name);
	virtual std::string GetName() { return 0; }
	virtual void Init(int _number) = 0;
	virtual void Init(int _number, Character* _charater);
	virtual int GetGold() = 0;
	virtual void SetGold(int _gold) = 0;
	virtual void AddInventory(std::list<Item>::iterator& it);
	virtual void InventoryView();

	virtual int GetInventorySize();
	virtual int DeleteInventoryItem(int iPlayerSelect);
public:
	virtual void PlayerState();
public:
	virtual int GetHp() { return iHp; }
	virtual int GetMp() { return iMp; }
	virtual int GetAttackPoint() { return iAttackPoint; }
	virtual int GetDefensePoint() { return iDefensePoint; }
	
	virtual int GetLv() { return 0; }
	virtual int GetStr() { return 0; }
	virtual int GetDex() { return 0; }
	virtual int GetInt() { return 0; }
	virtual int GetStatePoint() { return 0; }

	virtual void  SetAttackPoint(int _point) { iAttackPoint=_point; }
	virtual void  SetDefensePoint(int _point) { iDefensePoint= _point; }
	virtual void SetStr(int _str) {  }
	virtual void SetDex(int _dex) {  }
	virtual void SetInt(int _int) {  }
	virtual void SetStatePoint(int _point) { }
public:
	virtual void CharacterWear(sEquipment* _eq, std::string sName, int _iSelect);
	virtual void ChangeWear(sEquipment* _eq, std::string sName,int _iSelect);
	virtual void ChangeWearState(int iAttackPointInfo, int iDefensiveInfo, int iStrInfo, int iDexInfo, int iIntInfo);
	virtual void Update() = 0;

};

