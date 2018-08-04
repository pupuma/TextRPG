#pragma once
#include <string>
#include "SceneManager.h"

enum eStringType
{
	TEXT,
	NAME,
	BRANCH,
	NEXT,
	QUIT
};


class sString
{
private:
	std::string m_Text;
	eStringType m_Type;
	int m_Line;
public:
	sString();
	~sString();
public:
	sString* nextNode;
public:
	void Init(int _line, eStringType _type, std::string _text);
	void Print();
	virtual void Process(int* nextBranch, eScene _type, bool* isQuit);

};

