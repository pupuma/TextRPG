#pragma once

class DoubleBuffering;
class Character;

class PlayerGenerationScene
{
private:
	bool isGamePlayerName;
	char chText[256];

private:
	DoubleBuffering* buffer;
	Character* player;
public:
	PlayerGenerationScene();
	~PlayerGenerationScene();
public:
	void Clear();
	void Update();
	void Render();
	void Flipping();
	void Release();
};

