#include "BeginningVillageScene.h"
#include "DoubleBuffering.h"

BeginningVillageScene::BeginningVillageScene()
{
	MAP_X = 30;
	MAP_Y = 30;
	MAP_ADJ_X = 0;
	MAP_ADJ_Y = 0;
	//sztitle[15] = { "Hello World!!" };

	iMovingCurser = 0;

	iKey = 0;
	nDir = 1;
	x = (MAP_X - 5);
	buffer = new DoubleBuffering();
	buffer->CreateBuffer();
}

BeginningVillageScene::~BeginningVillageScene()
{

}

void BeginningVillageScene::Clear()
{
	buffer->BufferClear();
}

void BeginningVillageScene::Update()
{

}

void BeginningVillageScene::Render()
{
	ScreenView();
	OutPutScreenView();
	StateScreenView();
	SelectButtonScreenView();
	DefaultScreenView();
}

void BeginningVillageScene::Flipping()
{
	buffer->Flipping();
}

void BeginningVillageScene::Release()
{
	buffer->Release();
}

void BeginningVillageScene::DrawMap()
{

}

void BeginningVillageScene::ScreenView()
{
	int i = 0;

	for (i = 0; i < 60; i++)
	{
		buffer->BufferWrite(i, 30, "бс");
	}

	for (i = 0; i < 50; i++)
	{
		buffer->BufferWrite(40, i, "бс");

	}
}

void BeginningVillageScene::OutPutScreenView()
{

}

void BeginningVillageScene::StateScreenView()
{

}

void BeginningVillageScene::SelectButtonScreenView()
{

}

void BeginningVillageScene::DefaultScreenView()
{

}