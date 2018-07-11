#pragma once

enum Color
{
	BLACK,
	BLUE,
	REEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE, 

};
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
	void Textcolor(int foreground, int background);


};