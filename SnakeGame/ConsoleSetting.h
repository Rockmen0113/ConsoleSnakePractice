#pragma once
#include "pch.h"
#include <windows.h>

namespace Color
{
	static enum ConsoleColor
	{
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
}

static class ConsoleSetting
{
private:
	static HANDLE hStdOut;
public:

	static void ShowCursor(bool visible);

	static void SetColor(Color::ConsoleColor text, Color::ConsoleColor background);

	static void GotoXY(int X, int Y);
};