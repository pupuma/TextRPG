#include "BeginningVillageScene.h"
#include "DoubleBuffering.h"
#include <conio.h>
#include <iostream>

BeginningVillageScene::BeginningVillageScene()
{
	
}

BeginningVillageScene::~BeginningVillageScene()
{

}

void BeginningVillageScene::Init(int _index)
{
	system("cls");
}

void BeginningVillageScene::Update()
{
	std::cout << "Test" << std::endl;
	_getch();
}
