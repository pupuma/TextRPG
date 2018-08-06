#include "DefensiveStore.h"
#include "Character.h"
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


void DefensiveStore::ItemInput(Item* item)
{
	defenseItemList.push_back(*item);
}
void DefensiveStore::ItemPrint(int* iItemIndex)
{

	std::cout << "=번호=======아이템이름=========가격=======" << std::endl;
	int i = *iItemIndex;

	for (it = defenseItemList.begin(); it != defenseItemList.end(); it++, i++)
	{
		std::cout << std::setw(6) << i << "     " << std::setw(6) << it->sItemName << "\t\t" << std::setw(4) << it->iPrice << std::endl;
	}

	std::cout << "=======================================" << std::endl;

	*iItemIndex = i;
}
void DefensiveStore::ItemSale(Character *_character, bool * _isQuit)
{
	system("cls");
	_character->InventoryView();

	while (1)
	{
		if (0 == _character->GetInventorySize())
		{
			std::cout << "판매 할 수 있는 아이템이 없습니다..." << std::endl;
			system("cls");
			break;
		}
		else
		{
			SelectSaleItem(_character);
			break;
		}
	}
}
void DefensiveStore::SelectSaleItem(Character* _character)
{
	bool isQuit = false;
	int iPlayerSelect = 0;
	int iSaleGold = 0;
	int iPlayerGold = _character->GetGold();
	char chText;
	while (false == isQuit)
	{
		std::cout << "어느 아이템을 판매하겠습니까?? " << std::endl;
		std::cout << "번호 ? ";
		std::cin >> iPlayerSelect;

		if (0 == _character->GetInventorySize())
		{
			std::cout << "인벤토리에 아무것도 없습니다..." << std::endl;
			isQuit = true;
			system("cls");
			break;
		}


		if (0 == iPlayerSelect || iPlayerSelect > _character->GetInventorySize())
		{
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else
		{
			std::cout << "판매 했습니다.!" << std::endl;
			iSaleGold = _character->DeleteInventoryItem(iPlayerSelect);
			iPlayerGold = iPlayerGold + iSaleGold;
			_character->SetGold(iPlayerGold);
		}

		while (1)
		{
			std::cout << "계속 하시겠습니까? ( y / n ) :";
			std::cin >> chText;

			if ('y' == chText || 'Y' == chText)
			{
				break;
			}
			else if ('n' == chText || 'N' == chText)
			{
				isQuit = true;
				break;
			}
			else
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}


	}
}

void DefensiveStore::EnterStore(Character* _character)
{
	system("cls");

	bool isQuit = false;
	int iSelectNumber = 0;

	while (false == isQuit)
	{
		int iItemIndex = 1;

		ItemPrint(&iItemIndex);
		std::cout << "현재 플레이어 골드 : " << _character->GetGold() << std::endl;
		std::cout << "1. 구매 / 2 판매 / 3 나가기 :  ";
		std::cin >> iSelectNumber;

		if (1 == iSelectNumber)
		{
			PurchaseStore(_character, &isQuit, iItemIndex);
		}
		else if (2 == iSelectNumber)
		{
			ItemSale(_character, &isQuit);
		}
		else if (3 == iSelectNumber)
		{
			isQuit = true;
		}
		else
		{
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
	}
	system("cls");

}

void DefensiveStore::PurchaseStore(Character* _character, bool* _isQuit, int iItemIndex)
{
	int iSelectNumber = 0;
	bool isQuit = false;
	while (false == isQuit)
	{
		std::cout << "어느 아이템을 구매하겠습니까?? " << std::endl;
		std::cout << "번호 ? ";
		std::cin >> iSelectNumber;

		if (0 > iSelectNumber || iItemIndex < iSelectNumber)
		{
			std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}

		int i = 1;

		for (it = defenseItemList.begin(); it != defenseItemList.end(); it++, i++)
		{
			if (iSelectNumber == i)
			{
				if (_character->GetGold() >= it->iPrice)
				{
					std::cout << "구매했습니다.!" << std::endl;
					int iGold = _character->GetGold();
					iGold = iGold - it->iPrice;
					_character->SetGold(iGold);
					_character->AddInventory(it);
					_getch();
					break;
				}
				else if (_character->GetGold() < it->iPrice)
				{
					std::cout << "골드가 부족합니다..." << std::endl;
					_getch();
					break;
				}

				if (0 >= _character->GetGold())
				{
					int iGold = _character->GetGold();
					iGold = 0;
					_character->SetGold(iGold);
				}
			}
		}
		char chText;

		while (1)
		{
			std::cout << "계속 구매하시겠습니까? ( y / n ) : ";
			std::cin >> chText;

			if ('y' == chText || 'Y' == chText)
			{
				std::cout << "계속 구매 합니다 ! " << std::endl;
				std::cout << "현재 남은 금액은 " << _character->GetGold() << "입니다. ";
				break;
			}
			else if ('n' == chText || 'N' == chText)
			{
				isQuit = true;
				break;
			}
			else
			{
				std::cout << "잘못된 값을 입력했습니다. 다시 입력해 주세요 " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
		}

	}
	system("cls");


}
