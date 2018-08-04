#pragma once

class sParagraph;

class ParsingSystem
{
public:
	ParsingSystem();
	~ParsingSystem();
public:
	sParagraph* CSVParsing(const char* fileName, int* paragraphCount);
};

