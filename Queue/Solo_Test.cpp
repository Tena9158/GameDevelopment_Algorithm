#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stack>
using namespace std;

template<typename T>
class ListQueue
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}
	void pop()
	{
		_container.pop_front();
	}
	T& front()
	{
		_container.front();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }


private:
	list<T> _container;
};


template<typename T>
class ArrayQueue
{
	
public:
	ArrayQueue()
	{
		_container.resize(100);
	}
	void push(const T& value)
	{
		// 다 찼는지 체크
		if (_size == _container.size())
		{
			// 증설 작업
			int newsize = max(1, _size * 2);
			vector<T> newData;
			newData.resize(newsize);

			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size();
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;

		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}
	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}
	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }


private:
	vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};

int main()
{
	ArrayQueue<int> q;

	for (int i = 0; i < 100; i++)
		q.push(i);

	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();
}

