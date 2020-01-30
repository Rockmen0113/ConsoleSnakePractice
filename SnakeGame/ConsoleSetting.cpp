#include "pch.h"

#include "ConsoleSetting.h"

HANDLE ConsoleSetting::hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void ConsoleSetting::ShowCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), visible };
	SetConsoleCursorInfo(hStdOut, &cci);
}

void ConsoleSetting::SetColor(Color::ConsoleColor text, Color::ConsoleColor background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void ConsoleSetting::GotoXY(int X, int Y)
{
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}