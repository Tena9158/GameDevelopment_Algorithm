﻿#include "Engine/pch.h"
#include <iostream>
#include "Helper/ConsoleHelper.h"
#include "Board/Board.h"
#include "Player/Player.h"

Board board;
Player player;

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	board.Init(25, &player);
	player.Init(&board);


	uint64 lastTick = 0;
   while(true)
   {
#pragma region Frame Management
	   const uint64 currentTick = GetTickCount64();
	   const uint64 deltaTick = currentTick - lastTick;
	   lastTick = currentTick;
#pragma endregion

	   // Input

	   // Logic
	   player.Update(deltaTick);

	   // Rendering
	   board.Render();
   }
}