#pragma once

class DoubleBuffering;

enum eKey
{
	LEFT = 75,
	UP = 72,
	DOWN = 80,
	RIGHT = 77,
	ENTER = 13,
};

class TitleScene
{
private:
	int MAP_X;
	int MAP_Y;
	int MAP_ADJ_X;
	int MAP_ADJ_Y;

	int iMovingCurser;

	int iKey;
	int nDir;
	int x;
	//char sztitle[15];
	DoubleBuffering* buffer;

public:
	TitleScene();
	~TitleScene();

public:
	void Clear();
	void Update();
	void Render();
	void Flipping();
	void Release();
public:
	void DrawMap();
public:

};