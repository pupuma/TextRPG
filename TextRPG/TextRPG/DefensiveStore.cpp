#include "DefensiveStore.h"

#include "Item.h"

DefensiveStore::DefensiveStore()
{
	parser = new ParsingSystem();
	_item = new Item();
	m_StoreType = eStoreType::DEFENSIVE;

}


DefensiveStore::~DefensiveStore()
{
}

void DefensiveStore::ItemInit()
{
	parser->ItemCSVParsing("ItemList.csv", _item, this);
}



void DefensiveStore::LeaveStore()
{
	_item->ItemListClear();
}

void DefensiveStore::ItemInput(Item* item)
{
	
}
