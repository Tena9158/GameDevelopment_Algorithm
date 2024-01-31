#include "Engine/pch.h"
#include "Helper/ConsoleHelper.h"


/// <summary>
/// This function moves the position of the cursor within the console window to specified coordinates(x, y).
/// 
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>

void ConsoleHelper::SetCursorPosition(int32 x, int32 y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };


	SetConsoleCursorPosition(output, pos);
}


/// <summary>
/// The SetCursorColor function sets the text color within the console window to the specified ConsoleColor.
/// 
/// </summary>
/// <param name="color"></param>
void ConsoleHelper::SetCursorColor(ConsoleColor color)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(output, static_cast<int16>(color));
}

/// <summary>
/// The ShowConsoleCursor function provides the ability to hide or show the cursor within the console window.
/// </summary>
/// <param name="flag"></param>

void ConsoleHelper::ShowConsoleCursor(bool flag)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(output, &cursorInfo);

	cursorInfo.bVisible = flag;

	SetConsoleCursorInfo(output, &cursorInfo);
}
