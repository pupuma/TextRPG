#include "DoubleBuffering.h"

#include <windows.h>

#include "MainGame.h"

static int nBufferIndex;
static HANDLE hBuffer[2];

DoubleBuffering::DoubleBuffering()
{

}

DoubleBuffering::~DoubleBuffering()
{

}
void DoubleBuffering::CreateBuffer()
{
	CONSOLE_CURSOR_INFO cci;

	COORD size = { 120 , 50 };
	SMALL_RECT rect;

	rect.Left = 0;
	rect.Right = 120 ;
	rect.Top = 0;
	rect.Bottom = 50;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);
	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);
}

void DoubleBuffering::BufferWrite(int _x, int _y, const char* _string)
{
	DWORD dw;
	COORD CursorPosition = { _x * 2, _y };

	SetConsoleTextAttribute(hBuffer[nBufferIndex],7);

	SetConsoleCursorPosition(hBuffer[nBufferIndex], CursorPosition);
	WriteFile(hBuffer[nBufferIndex], _string, strlen(_string), &dw, NULL);
}

void DoubleBuffering::BufferWrite(int _x, int _y, const char* _string, eConsoleColor _fcolor, eConsoleColor _bcolor)
{
	DWORD dw;
	COORD CursorPosition = { _x * 2, _y };
	int color = _fcolor + _bcolor * 16;

	SetConsoleTextAttribute(hBuffer[nBufferIndex], color);

	SetConsoleCursorPosition(hBuffer[nBufferIndex], CursorPosition);
	WriteFile(hBuffer[nBufferIndex], _string, strlen(_string), &dw, NULL);
}


void DoubleBuffering::Flipping()
{
	Sleep(33);
	SetConsoleActiveScreenBuffer(hBuffer[nBufferIndex]);
	nBufferIndex = !nBufferIndex;
}

void DoubleBuffering::BufferClear()
{

	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nBufferIndex], ' ', 120 * 50, Coor, &dw);
}

void DoubleBuffering::Release()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}
