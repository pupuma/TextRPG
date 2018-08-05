#pragma once
#include "Store.h"

class DefensiveStore
	:public Store
{
public:
	DefensiveStore();
	~DefensiveStore();
public:
	std::list<Item> defenseItemList;

public:
	void ItemInit();
	void LeaveStore();
	void ItemInput(Item* item);

};

