#pragma once
#include "Store.h"


class GeneralStore
	: public Store
{
public:
	GeneralStore();
	~GeneralStore();
public:
	std::list<Item> recoveryItemList;
public:
	void ItemInit();
	void LeaveStore();
	void ItemInput(Item* item);

};

