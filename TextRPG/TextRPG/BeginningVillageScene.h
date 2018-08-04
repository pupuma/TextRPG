#pragma once
#include "Scene.h"

class BeginningVillageScene
	:public Scene
{
private:

public:
	BeginningVillageScene();
	~BeginningVillageScene();
public:
	void Init(int _index);
	void Update();
	
};