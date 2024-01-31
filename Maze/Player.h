#pragma once
class Board;

class Player
{

public:
	void	Init(Board* board);
	void	Update(uint64 deltaTick);

	
public:
	Pos		GetPos() { return _pos; }
	void	SetPosition(Pos pos) { _pos = pos; }

private:
	Pos		_pos = { };
	int32	_dir = DIR_UP;
	Board*	_board = nullptr;

};

