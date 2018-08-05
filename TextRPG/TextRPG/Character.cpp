#include "Character.h"
#include <iostream>


Character::Character()
{
	iHp = 100;
	iMp = 100;
	iAttackPoint = 30;
}


Character::~Character()
{

}

//void Character::SetCharacterName(const char* _name)
//{
//	strcpy_s(chName, sizeof(chName), _name);
//}
