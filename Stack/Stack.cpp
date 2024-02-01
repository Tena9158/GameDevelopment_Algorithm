#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

// Stack (LIFO Last-In-First-Out 후입 선출)

// <- [ ][ ][ ][ ]		자동차들이 지나가는중..
// 사고 ! [ ][ ][ ][	]	사고가 나서 차들을 뒤로 뺴야함
// [ ] [ ]  [ ]  [ ]	늦게 들어온 사람이 먼저 나가야함. -> 후입 선출

// 왜 굳이 알아야할까 ?

// 스택은 되돌리기(복원)의 기능을 가지고있음
// Ctrl + Z


template<typename T, typename Container = vector<T>>
class Stack
{
public:

public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	/*
	T pop()
	{
		// C# 스타일의 pop.
		// 이런식으로하면 굳이 top하고 pop를 분리할 필요가 없다. 그러나 성능 문제가 생길 수있음.
		// T 타입의 복사는 굉장히 무거울 수 있다.

		T ret = _data[_size - 1];
		_size--;
		return ret;
	}
	*/

	void pop()
	{
		_container.pop_back();
	}
	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	//list<T> list;
	Container _container;
};


int main()
{
	Stack<int, list<int>> s;


	// 삽입
	s.push(1);
	s.push(1);
	s.push(3);


	// 비었나 ?
	while (s.empty() == false)
	{
		// 최상위 원소
		int data = s.top();
		// 최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	int size = s.size();
	

}

