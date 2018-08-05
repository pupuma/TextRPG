#include "GeneralStore.h"
#include "Item.h"


GeneralStore::GeneralStore()
{
	parser = new ParsingSystem();
	_item = new Item();
	m_StoreType = eStoreType::POTION;

}


GeneralStore::~GeneralStore()
{
}


void GeneralStore::ItemInit()
{
	//ParsingSystem parsing;
	//.parsing.ItemCSVParsing("ItemList.csv", _item);
	parser->ItemCSVParsing("ItemList.csv", _item, this);
}

void GeneralStore::LeaveStore()
{
	_item->ItemListClear();
}

void GeneralStore::ItemInput(Item* item)
{
}
