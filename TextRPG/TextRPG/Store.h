#pragma once

#include "ParsingSystem.h"
#include <map>
#include <list>
#include <iomanip>
#include <iostream>
#include <conio.h>

class Character;

enum eStoreType
{
	POTION,
	AMS,
	DEFENSIVE,
	DEFAULT,
};

class Store
{
protected:
	ParsingSystem* parser;
	Item* _item;
	eStoreType m_StoreType;
protected:

public:
	Store();
	~Store();

public:
	virtual void ItemInit();
	virtual void EnterStore(Character* _character);
	virtual void LeaveStore();
	virtual void ItemInput(Item* item);
public:
	eStoreType GetStoreType() { return m_StoreType; }


};

