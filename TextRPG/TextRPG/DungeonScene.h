#pragma once

#include "Scene.h"

class Character;
class sParagraph;
class ParsingSystem;

class DungeonScene
	: public Scene
{
private:
	sParagraph * paragraphList;
	ParsingSystem* parser;
	int pargraphCount;
	int iBranch;
	bool isQuit;

	Character* _player;
public:
	DungeonScene();
	~DungeonScene();
public:
	void Init();
	void Update();
	void DungeonStart();
};

