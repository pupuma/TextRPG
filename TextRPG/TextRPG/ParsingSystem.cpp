#include "ParsingSystem.h"

#include <fstream>	
#include <queue>
#include <string>
#include <iostream>
#include <conio.h>

#include "sParagraph.h"
#include "sString.h"
#include "StringText.h"
#include "StringName.h"
#include "StringBranch.h"
#include "StringNext.h"
#include "StringQuit.h"


ParsingSystem::ParsingSystem()
{
}


ParsingSystem::~ParsingSystem()
{
}

sParagraph* ParsingSystem::CSVParsing(const char* fileName, int* paragraphCount)
{
	std::ifstream inFile(fileName);
	
	std::queue<std::string> q_data;
	std::string sBuffer;
	std::string sRecord;
	std::string textString;
	int iIndex = 0;
	int iLineNo = 0;
	eStringType iTextType;
	//int iCount = 0;
	int iParagraph = 0;

	if (!inFile.is_open())
	{
		std::cout << "File is Not Read" << std::endl;
	}

	// File Read
	getline(inFile, sBuffer);

	int paragraphIndex = 0;			// 현재 문단번호
	int prevParagraphIdx = -1;		// 이전 문단번호

	while (getline(inFile, sBuffer))
	{
		q_data.push(sBuffer);
		//std::cout << sBuffer << std::endl;

		iIndex = sBuffer.find(",");
		textString = sBuffer.substr(0, iIndex);
		paragraphIndex = stoi(textString);

		if (paragraphIndex != prevParagraphIdx)
		{
			prevParagraphIdx = paragraphIndex;
			(*paragraphCount)++;

		}

	}
	
	// 
	inFile.close();


	sParagraph* paragraphList = new sParagraph[(*paragraphCount)];

	// 초기화 ( 처음으로 ) 
	paragraphIndex = 0;
	prevParagraphIdx = -1;
	
	while (!q_data.empty())
	{
		sRecord = q_data.front().substr(0, q_data.front().size());

		//
		iIndex = sRecord.find(",");
		textString = sRecord.substr(0, iIndex);
		paragraphIndex = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		
		//
		iIndex = sRecord.find(",");
		textString = sRecord.substr(0, iIndex);
		iLineNo = stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());
		
		//
		iIndex = sRecord.find(",");
		textString = sRecord.substr(0, iIndex);
		iTextType = (eStringType)stoi(textString);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		//
		iIndex = sRecord.find(",");
		textString = sRecord.substr(0, iIndex);
		sRecord = sRecord.substr(iIndex + 1, sRecord.size());

		//
		if (paragraphIndex != prevParagraphIdx)
		{
			prevParagraphIdx = paragraphIndex;
			paragraphList[paragraphIndex]._currentNode = 0;		//초기화
																	//(*paragraphCount)++;
		}

		//
		sString* newString = 0;

		switch (iTextType)
		{
		case eStringType::TEXT:
			newString = new StringText();
			break;
		case eStringType::NAME:
			newString = new StringName();
			break;
		case eStringType::BRANCH:
			newString = new StringBranch();
			break;
		case eStringType::NEXT:
			newString = new StringNext();
			break;
		case eStringType::QUIT:
			newString = new StringQuit();
			break;
		}
		//
		newString->Init(iLineNo, iTextType, textString);
		paragraphList[paragraphIndex].AddStringToParagraph(newString);

		q_data.pop();


	}

	return paragraphList;
}