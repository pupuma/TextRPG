#pragma once

class Character;

enum eCharacterType
{
	PLAYER,
};
class GameSystem
{
private:
	Character* _character;
private:
	GameSystem();
	~GameSystem();
private:
	static GameSystem* _instance;
public:
	static GameSystem* GetInstance();
public:
	void CharacterCreate(eCharacterType type);
	Character* GetCharacter() { return _character; }
	void PlayerInit(int _number);
};

