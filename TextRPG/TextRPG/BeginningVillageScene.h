#pragma once

class DoubleBuffering;



class BeginningVillageScene
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

	DoubleBuffering* buffer;

public:
	BeginningVillageScene();
	~BeginningVillageScene();
public:
	void Clear();
	void Update();
	void Render();
	void Flipping();
	void Release();
public:
	void DrawMap();
public:
	void ScreenView();
	void OutPutScreenView();
	void StateScreenView();
	void SelectButtonScreenView();
	void DefaultScreenView();
};