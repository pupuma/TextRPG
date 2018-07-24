#pragma once
class Character
{
private:
	char chName[256];
public:
	Character();
	~Character();
public:
	void SetCharacterName(const char* _name);

};

