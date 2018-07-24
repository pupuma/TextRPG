#include "TitleScene.h"

#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "DoubleBuffering.h"


TitleScene::TitleScene()
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

TitleScene::~TitleScene()
{

}
void TitleScene::Clear()
{
	buffer->BufferClear();
}
void TitleScene::Update()
{
	//buffer->BufferClear();
	//buffer->Flipping();
	iKey = _getch();

	switch (iKey)
	{
	case eKey::LEFT:
		iMovingCurser--;
		break;
	case eKey::RIGHT:
		iMovingCurser++;
		break;
	case eKey::ENTER:
		break;
	}

	if (0 > iMovingCurser)
	{
		iMovingCurser = 0;
	}

	if (2 < iMovingCurser)
	{
		iMovingCurser = 2;
	}
}
void TitleScene::Render()
{
	
	
	{
		//
		//DoubleBuffering buffer;
		DrawMap();

		switch (iMovingCurser)
		{
		case 0:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
			break;
		case 1:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");
			break;
		case 2:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			break;
		default:
			buffer->BufferWrite(MAP_ADJ_Y + 3, MAP_Y + MAP_ADJ_Y + 5, " 새 로 하 기 ", eConsoleColor::WHITE, eConsoleColor::BLUE);
			buffer->BufferWrite(MAP_ADJ_Y + 13, MAP_Y + MAP_ADJ_Y + 5, " 이 어 하 기 ");
			buffer->BufferWrite(MAP_ADJ_Y + 23, MAP_Y + MAP_ADJ_Y + 5, " 끝 내 기 ");

			break;
		}

	}
	
}
void TitleScene::Flipping()
{
	buffer->Flipping();
}
void TitleScene::Release()
{
	buffer->Release();
}

void TitleScene::DrawMap()
{
	//DoubleBuffering buffer;

	int i = 0;
	for (i = 0; i < MAP_X; i++)
	{
		//GotoXY(MAP_ADJ_X + i, MAP_ADJ_Y, "■");
		buffer->BufferWrite(MAP_ADJ_X + i, MAP_ADJ_Y, "■");
	}

	for (i = (MAP_ADJ_Y + 1); i < (MAP_ADJ_Y + MAP_Y - 1); i++)
	{
		//GotoXY(MAP_ADJ_X, i, "■");
		buffer->BufferWrite(MAP_ADJ_X, i, "■");
		//GotoXY((MAP_ADJ_X + MAP_X - 1), i, "■");
		buffer->BufferWrite((MAP_ADJ_X + MAP_X - 1), i, "■");
	}

	for (i = 0; i < MAP_X; i++)
	{
		//GotoXY((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "■");.


		buffer->BufferWrite((MAP_ADJ_X + i), (MAP_ADJ_Y + MAP_Y - 1), "■");
	}

}

