#include "Character.h"
#include <iostream>


Character::Character()
{
	iHp = 100;
	iMp = 100;
	iAttackPoint = 30;
	iDefensePoint = 10;
	
}


Character::~Character()
{

}

void Character::SetName(std::string _name)
{
}

void Character::Init(int _number, Character * _charater)
{
}

void Character::AddInventory(std::list<Item>::iterator& it)
{
}

//void Character::SetCharacterName(const char* _name)
//{
//	strcpy_s(chName, sizeof(chName), _name);
//}

void Character::InventoryView()
{

}

int Character::GetInventorySize()
{
	return 0;
}

int Character::DeleteInventoryItem(int iPlayerSelect)
{
	return 0;
}

void Character::PlayerState()
{
}

void Character::CharacterWear(sEquipment* _eq, std::string sName, int _iSelect)
{
}

void Character::ChangeWear(sEquipment* _eq, std::string sName, int _iSelect)
{
}

void Character::ChangeWearState( int iAttackPointInfo, int iDefensiveInfo, int iStrInfo, int iDexInfo, int iIntInfo)
{
	
}

void Character::Update()
{
}
