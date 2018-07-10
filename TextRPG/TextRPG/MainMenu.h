#pragma once


class MainMenu
{
private:
	int MAP_X;
	int MAP_Y;
	int MAP_ADJ_X;
	int MAP_ADJ_Y;


	//char sztitle[15];

public:
	MainMenu();
	~MainMenu();

public:
	void Render();
	void GotoXY(int  _x, int _y, const char* pszStr);
	void DrawMap();
};