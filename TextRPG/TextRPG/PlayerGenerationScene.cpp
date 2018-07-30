#include "PlayerGenerationScene.h"

#include <iostream>

#include "Character.h"


PlayerGenerationScene::PlayerGenerationScene()
{
	isGamePlayerName = false;

	player = new Character();
	//buffer = new DoubleBuffering();
	//buffer->CreateBuffer();

}


PlayerGenerationScene::~PlayerGenerationScene()
{

}

void PlayerGenerationScene::Clear()
{
	//buffer->BufferClear();

}

void PlayerGenerationScene::Update()
{
//	{
		//buffer->BufferWrite(2, 1, "캐릭터 이름을 입력해 주세요 :");
		//std::cin >> chText;
//	}
	{
		// 다음 문자열을 업데이트 한다. 
	}
	
}

void PlayerGenerationScene::Render()
{
	//buffer->BufferWrite(2, 2, "캐릭터 이름은 입니다.");
	
	{
		//출력 한다. 
	}
}

void PlayerGenerationScene::Flipping()
{
	//buffer->Flipping();
}

void PlayerGenerationScene::Release()
{
	//buffer->Release();
}
