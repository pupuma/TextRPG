#include "GameSystem.h"

#include "Player.h"

GameSystem* GameSystem::_instance = 0;


GameSystem::GameSystem()
{
}


GameSystem::~GameSystem()
{
}

GameSystem* GameSystem::GetInstance()
{
	if (0 == _instance)
	{
		_instance = new GameSystem();
	}
	return _instance;
}

void GameSystem::CharacterCreate(eCharacterType type)
{
	switch (type)
	{
	case eCharacterType::PLAYER:
		_character = new Player();
		break;
	}
}

void GameSystem::PlayerInit(int _number)
{
	_character->Init(_number);
}
