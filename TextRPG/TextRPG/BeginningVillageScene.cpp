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



