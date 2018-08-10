#include "StringRandom.h"

#include <time.h>
#include <conio.h>
#include <iostream>

#include "Monster.h"
#include "GameSystem.h"
StringRandom::StringRandom()
{
	_monster = new Monster();
	_player = GameSystem::GetInstance()->GetCharacter();
}


StringRandom::~StringRandom()
{
}

void StringRandom::Process(int* nextBranch, eScene type, bool * isQuit)
{
	srand((unsigned)time(NULL));
	int iRand = rand() % 10;
	Print();
	_getch();
	MonsterEvent(iRand,_player, nextBranch, isQuit);

}

void StringRandom::MonsterEvent(int iRand, Character* _player,int* nextBranch, bool* isQuit)
{
	_monster->Init(iRand,_player);

	//srand((unsigned)time(NULL));
	//iRand = rand() % 10;
	// 몬스터를 만나다. 
	GameSystem::GetInstance()->CollisionEvent(_player, _monster,iRand, nextBranch, isQuit);
	

}
