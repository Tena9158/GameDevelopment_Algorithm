#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <stack>
using namespace std;


// Queue (FIFO First-In-First-Out 선입선출) 

// front << [1][2][3][4] << rear(back)
// 대기열 기능



// [ ][ ][ ][ ][ ]
template<typename T>
class ListQueue // 연결 리스트 방식의 Queue
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


// 데이터의 시작 위치를 유동적으로 바꿔서, 순환 방식으로 구현
// [_front/_back][ ][ ][ ][ ][ ][ ][ ][ ][ ] - 처음 상태
template<typename T>
class ArrayQueue // 연결 리스트 방식의 Queue
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
            int newSize = max(1, _size * 2);
            vector<T> newData;
            newData.resize(newSize);

            // 데이터 복사
            for (int i = 0; i < _size; i++)
            {
                // [_front][ ][ ][ ][_back][ ][ ][ ][ ][ ][][ ][ ][ ][ ][ ][ ][ ][ ][ ]
                // [_front][ ][ ][ ] [_back] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] [] []
                int index = (_front + i) % _container.size();
                newData[i] = _container[index];
            }

            _container.swap(newData);
            _front = 0;
            _back = _size;
        }

        // back 위치에 값을 넣는다.
        _container[_back] = value;
        // back이 나가지않고 순환하게 만들어준다.
        _back = (_back + 1) % _container.size(); 
        _size++; // 데이터의 개수
		
	}
	void pop()
	{
        // [ ][_front][ ][_back ][ ][ ][ ][ ][ ][ ]
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

