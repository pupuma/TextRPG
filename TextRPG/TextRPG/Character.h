#pragma once


class Character
{
private:
	int iHp;
	int iMp;
	int iAttackPoint;
	int iGold;
public:
	Character();
	~Character();
public:
	virtual void Init(int _number) = 0;
	virtual int GetGold() = 0;
	virtual void SetGold(int _gold) = 0;
};

