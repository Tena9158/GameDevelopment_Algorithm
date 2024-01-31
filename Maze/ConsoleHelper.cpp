#include "pch.h"
#include "ConsoleHelper.h"


// This function moves the position of the cursor within the console window to specified coordinates(x, y).

void ConsoleHelper::SetCursorPosition(int32 x, int32 y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };


	SetConsoleCursorPosition(output, pos);
}

// The SetCursorColor function sets the text color within the console window to the specified ConsoleColor.

void ConsoleHelper::SetCursorColor(ConsoleColor color)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(output, static_cast<int16>(color));
}

// The ShowConsoleCursor function provides the ability to hide or show the cursor within the console window.

void ConsoleHelper::ShowConsoleCursor(bool flag)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(output, &cursorInfo);

	cursorInfo.bVisible = flag;

	SetConsoleCursorInfo(output, &cursorInfo);
}
