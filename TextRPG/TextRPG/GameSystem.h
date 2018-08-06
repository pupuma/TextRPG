#pragma once
#include <string>
#include <vector>
#include <list>
#include "Item.h"
#include "Character.h"

class ParsingSystem;
enum eCharacterType
{
	PLAYER,
};

struct sData
{
	//ItemCode,ItemType,ItemName,ItemPrice, HP, MP,Lv,LevleUp, AttackPoint, Defensive, Str, DEX, INT, InfoText
	int iCodeInfo = 0;
	eItemType eTypeInfo;
	std::string sNameInfo;
	int iPriceInfo = 0;
	int iHpInfo = 0;
	int iMpInfo = 0;
	int iLvInfo = 0;
	int iLevelUpInfo = 0;
	int iAttackPointInfo = 0;
	int iDefensiveInfo = 0;
	int iStrInfo = 0;
	int iDexInfo = 0;
	int iIntInfo = 0;
	std::string sTextInfo;
};

class GameSystem
{
private:
	Character* _character;
	ParsingSystem* _parser;
	//std::vector < std::pair<std::pair<int, std::string>, std::string>> vRecveryInfo;
	//std::vector < std::pair<std::pair<int, std::string>, std::string>> vArmsInfo;
	//std::vector < std::pair<std::pair<int, std::string>, std::string>> vDefensiveInfo;
private:
	std::vector <sData> vRecveryInfo;
	std::vector <sData> vArmsInfo;
	std::vector <sData> vDefensiveInfo;
public:
	std::vector<sData> GetRecveryInfo() { return vRecveryInfo; }
	std::vector<sData> GetArmsInfo() { return vArmsInfo; }
	std::vector<sData> GetDefensiveInfo() { return vDefensiveInfo; }

private:
	GameSystem();
	~GameSystem();
private:
	static GameSystem* _instance;
public:
	static GameSystem* GetInstance();
public:
	void CharacterCreate(eCharacterType type);
	Character* GetCharacter() { return _character; }
	void PlayerInit(int _number);
	void SetPlayerName(std::string _name);
	void InitItemInfo();
	void FindinventoryInfoView(std::list<std::pair< std::string, int>>* vInventory, int _iSelect, sEquipment* _eq);
public:
	void Battle(Character* _player, Character* _monster, int _rand, int* nextBranch, bool* isQuit);

};

