#include "Engine/pch.h"
#include "Player/Player.h"
#include "Board/Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// ������ ���������� ��� ����
	Pos dest = board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1, 0},	// Up
		Pos {0, -1},	// Left
		Pos {1,  0},	// Down
		Pos {0,  1}		// Right
	};

	while (pos != dest)
	{
		// 1. ���� �ٶ󺸴� ������ �������� ���������� �� �� �ִ��� Ȯ��.
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// ������ �������� 90�� ȸ��.
			_dir = newDir;
			// ������ �� �� ����.
			pos += front[_dir];
			// ��� ����
			_path.push_back(pos);
		}
		// 2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��.
		else if (CanGo(pos + front[_dir]))
		{
			// ������ �� �� ����
			pos += front[_dir];
			// ��� ����
			_path.push_back(pos);
		}
		else
		{
			// ���� �������� 90�� ȸ��
			_dir = (_dir + 1) % DIR_COUNT;
		/*	
		�ٷ� ������ �ִ� ������ �����ϴ� ��Ģ�� ����.
		switch (_dir)
			{
			case DIR_UP:
				_dir = DIR_LEFT;
				break;
			case DIR_LEFT:
				_dir = DIR_DOWN;
				break;
			case DIR_DOWN:
				_dir = DIR_RIGHT;
				break;
			case DIR_RIGHT:
				_dir = DIR_UP;
				break;
			}
		*/
		}
	}

}

void Player::Update(uint64 deltaTick)
{
	if (_pathindex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathindex];
		_pathindex++;
	}

}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}