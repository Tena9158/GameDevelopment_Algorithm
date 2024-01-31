#include "Engine/pch.h"
#include "Board/Board.h"
#include "Helper/ConsoleHelper.h"
#include "Player/Player.h"

const char* TILE = "■";

Board::Board()
{

}

Board::~Board()
{

}

void Board::Init(int32 size, Player* player)
{
	_size = size;
	_player = player;

	GenerateMap();
}


/// <summary>
/// 전체 보드판을 그려주는 함수.
/// </summary>
void Board::Render()
{
	ConsoleHelper::SetCursorPosition(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);


	for (int32 y = 0; y < 25; y++)
	{
		for (int32 x = 0; x < 25; x++)
		{
			ConsoleColor color = GetTileColor(Pos{ y, x });
			ConsoleHelper::SetCursorColor(color);

			cout << TILE;
		}
		cout << endl;
	}
}

/// <summary>
/// 랜덤한 맵을 그려주는 함수.
/// </summary>
void Board::GenerateMap()
{
	// Binary Tree 미로 생성 알고리즘
	// - Mazes For Programmers

	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[x][y] = TileType::EMPTY;
		}
	}

	RandomPathGenerator();
	
}

/// <summary>
/// 랜덤으로 우측, 혹은 아래로 길을 뚫는 작업을 하는 함수
/// </summary>
void Board::RandomPathGenerator()
{
	for (int32 y = 0; y < _size; y++)
	{
		for (int32 x = 0; x < _size; x++)
		{

			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (y == _size - 2 && x == _size - 2)
				continue;

			if (y == _size - 2)
			{
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}
			if (x == _size - 2)
			{
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			const int32 randValue = ::rand() % 2;

			if (randValue == 0)
			{
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[y + 1][x] = TileType::EMPTY;
			}
		}
	}
}

/// <summary>
/// 타일의 타입을 가져오는 함수.
/// 사이즈를 초과하거나, 사이즈가 너무 작은 경우엔 None 타입
/// </summary>
/// <param name="pos"></param>
/// <returns></returns>
TileType Board::GetTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size)
		return TileType::NONE;
	if (pos.y < 0 || pos.y >= _size)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

/// <summary>
/// 타일의 색을 가져오는 함수.
/// </summary>
/// <param name="pos"></param>
/// <returns></returns>
ConsoleColor Board::GetTileColor(Pos pos)
{
	if (_player && _player->GetPos() == pos)
		return ConsoleColor::YELLOW;


	if (GetExitPos() == pos)
		return ConsoleColor::BLUE;

	TileType tileType = GetTileType(pos);

	switch (tileType)
	{
		case TileType::EMPTY:
			return ConsoleColor::GREEN;
		case TileType::WALL:
			return ConsoleColor::RED;
	}

	return ConsoleColor::WHITE;
}
