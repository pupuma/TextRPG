#include "Item.h"
#include "Store.h"
#include <iostream>


Item::Item()
{
	_store = new Store();
}


Item::~Item()
{
}

void Item::SetItemMap(int _index, int _iTemCode, eItemType _type, std::string _name, int _price)
{
	iItemCode = _iTemCode;
	eType = _type;
	sItemName = _name;
	iPrice = _price;

	//std::pair<int, int> pPrimaryKey;
	//std::pair<std::pair<int, int>, Item> pItem;

	//pPrimaryKey.first = _index;
	//pPrimaryKey.second = iItemCode;



	//pItem.first = pPrimaryKey;
	//pItem.second = *this;

	//mItem.insert(pItem);
}


void Item::ItemListPrint()
{
	/*std::list<Item>::iterator it;
	int i = 0;

	
	for (it = itemList.begin(); it != itemList.end(); it++, i++)
	{
		std::cout << i + 1 << ". " << "[아이템 이름] :: " << it->sItemName << "      " << "[ 아이템 가격 ] ::"
			<< it->iPrice << std::endl;
	}
	*/
}
void Item::ItemListClear()
{

	/*store.recoveryItemList.clear();
	store.weaponItemList.clear();
	store.defenseItemList.clear();*/

}


