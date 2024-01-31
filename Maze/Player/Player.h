#pragma once
class Board;

class Player
{
	enum
	{
		MOVE_TICK = 100
	};
public:
	void		Init(Board* board);
	void		Update(uint64 deltaTick);

	bool		CanGo(Pos pos);
	
public:
	Pos			GetPos() { return _pos; }
	void		SetPosition(Pos pos) { _pos = pos; }

private:
	Pos			_pos = { };
	int32		_dir = DIR_UP;
	Board*		_board = nullptr;

	vector<Pos> _path; // ��� ���� ����
	uint32		_pathindex; // ��� �ε���
	uint64		_sumTick = 0;

};
