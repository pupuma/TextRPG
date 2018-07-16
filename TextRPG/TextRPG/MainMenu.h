#pragma once

enum eKey
{
	LEFT = 75,
	UP = 72,
	DOWN = 80,
	RIGHT = 77,
	ENTER = 13,
};
class MainMenu
{
private:
	int MAP_X;
	int MAP_Y;
	int MAP_ADJ_X;
	int MAP_ADJ_Y;

	int iMovingCurser;
	//char sztitle[15];

public:
	MainMenu();
	~MainMenu();

public:
	void Render();
	void GotoXY(int  _x, int _y, const char* pszStr);
	void DrawMap();
	void Textcolor(int foreground, int background);


};