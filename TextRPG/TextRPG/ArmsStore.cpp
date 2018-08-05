#include "ArmsStore.h"
#include "ParsingSystem.h"
#include "Item.h"
#include "Character.h"
#include <iomanip>
#include <iostream>
#include <conio.h>
ArmsStore::ArmsStore()
{
	parser = new ParsingSystem();
	_item = new Item();
	m_StoreType = eStoreType::AMS;

}


ArmsStore::~ArmsStore()
{
}

void ArmsStore::ItemInit()
{
	parser->ItemCSVParsing("ItemList.csv", _item, this);
}

void ArmsStore::LeaveStore()
{
}

void ArmsStore::ItemInput(Item* item)
{
	weaponItemList.push_back(*item);
}
void ArmsStore::ItemPrint(int* iItemIndex)
{

	std::cout << "=��ȣ=======�������̸�=========����=======" << std::endl;
	int i = *iItemIndex;

	for (it = weaponItemList.begin(); it != weaponItemList.end(); it++, i++)
	{
		std::cout << std::setw(6) << i << "     " << std::setw(6) << it->sItemName << "\t\t" << std::setw(4) << it->iPrice << std::endl;
	}

	std::cout << "=======================================" << std::endl;

	*iItemIndex = i;
}
void ArmsStore::EnterStore(Character* _character)
{
	system("cls");

	bool isQuit = false;
	int iSelectNumber = 0;

	while (false == isQuit)
	{
		int iItemIndex = 1;

		ItemPrint(&iItemIndex);
		std::cout << "���� �÷��̾� ��� : " <<_character->GetGold() << std::endl;
		std::cout << "1. ���� / 2 �Ǹ� / 3 ������ :  ";
		std::cin >> iSelectNumber;

		if (1 == iSelectNumber)
		{
			PurchaseStore(_character, &isQuit, iItemIndex);
		}
		else if (2 == iSelectNumber)
		{

		}
		else if( 3 == iSelectNumber)
		{
			isQuit = true;
		}
		else
		{
			std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
	}
	system("cls");

}

void ArmsStore::PurchaseStore(Character* _character, bool* _isQuit,int iItemIndex)
{
	int iSelectNumber = 0;
	bool isQuit = false;
	while (false == isQuit)
	{
		std::cout << "��� �������� �����ϰڽ��ϱ�?? " << std::endl;
		std::cout << "��ȣ ? ";
		std::cin >> iSelectNumber;
		
		if (0 > iSelectNumber || iItemIndex < iSelectNumber)
		{
			std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}

		int i = 1;
		
		for (it = weaponItemList.begin(); it != weaponItemList.end(); it++,i++)
		{
			if (iSelectNumber == i)
			{
				if (_character->GetGold() >= it->iPrice)
				{
					std::cout << "�����߽��ϴ�.!" << std::endl;
					int iGold = _character->GetGold();
					iGold = iGold - it->iPrice;
					_character->SetGold(iGold);
					_getch();
					break;
				}
				else if (_character->GetGold() < it->iPrice)
				{
					std::cout << "��尡 �����մϴ�..." << std::endl;
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
			std::cout << "��� �����Ͻðڽ��ϱ�? ( y / n ) : ";
			std::cin >> chText;

			if ('y' == chText || 'Y' == chText)
			{
				std::cout << "��� ���� �մϴ� ! " << std::endl;
				std::cout << "���� ���� �ݾ��� " << _character->GetGold() << "�Դϴ�. ";
				break;
			}
			else if ('n' == chText || 'N' == chText)
			{
				isQuit = true;
				break;
			}
			else
			{
				std::cout << "�߸��� ���� �Է��߽��ϴ�. �ٽ� �Է��� �ּ��� " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				continue;

			}
		}
		
	}
	
	system("cls");

	
}
