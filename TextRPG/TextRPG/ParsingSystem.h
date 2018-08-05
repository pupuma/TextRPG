#pragma once

class sParagraph;
class Item;
class Store;

class ParsingSystem
{
public:
	ParsingSystem();
	~ParsingSystem();
public:
	sParagraph* CSVParsing(const char* fileName, int* paragraphCount);
	void ItemCSVParsing(const char* fileName, Item* _item, Store* _store);
};

