#include "Character.h"
#include <iostream>


Character::Character()
{
}


Character::~Character()
{
}

void Character::SetCharacterName(const char* _name)
{
	strcpy_s(chName, sizeof(chName), _name);
}
