#include "PlayerGenerationScene.h"

#include <iostream>

#include "Character.h"
#include "DoubleBuffering.h"


PlayerGenerationScene::PlayerGenerationScene()
{
	isGamePlayerName = false;

	player = new Character();
	buffer = new DoubleBuffering();
	buffer->CreateBuffer();
}


PlayerGenerationScene::~PlayerGenerationScene()
{

}

void PlayerGenerationScene::Clear()
{
	buffer->BufferClear();

}

void PlayerGenerationScene::Update()
{
	buffer->BufferWrite(2, 1, "캐릭터 이름을 입력해 주세요 :");
	std::cin >> chText;
}

void PlayerGenerationScene::Render()
{

	buffer->BufferWrite(2, 2, "캐릭터 이름은 입니다.");
}

void PlayerGenerationScene::Flipping()
{
	buffer->Flipping();

}

void PlayerGenerationScene::Release()
{
	buffer->Release();
}
