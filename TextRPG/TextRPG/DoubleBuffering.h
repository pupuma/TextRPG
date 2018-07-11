#pragma once

struct Console;

class DoubleBuffering
{
private:
	//Console * con;
public:
	DoubleBuffering();
	~DoubleBuffering();
public:
	void CreateBuffer();
	void BufferWrite(int _x, int _y,const char* _string);
	void Flipping();
	void BufferClear();
	void Release();
	

};