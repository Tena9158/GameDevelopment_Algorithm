#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{

	}
	~Vector()
	{
		if (_data)
			delete[] _data;
	}


public:

	
	void reserve(int capacity)
	{
		// 예약한 방보다 기존의 방이 더 많은지 체크
		if (-capacity >= capacity)
			return;

		_capacity = capacity;

		// 증설 작업
		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)
			newData[i] = _data;

		if (_data)
			delete[] _data;

		_data = newData;
	}
	void push_back(const T& value)
	{

		if (_size == _capacity)
		{
			// 증설 작업
			int newCapcity = static_cast<int>(_capacity * 1.5f);

			// 값이 같은 경우
			if (newCapcity == _capacity)
				newCapcity++;

			reserve(newCapcity);
		}
		// 데이터 저장
		_data[_size] = value;
		// 크기 증가
		_size++;
	}
	T& operator[](const int pos) {}

	int size() { return _size; }
	int capacity() { return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}
			
	}


private:
	T* _data = nullptr;
	int _size = 0;
	int _capacity = 0;
};

int main()
{
	Vector<int> v;


	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}


	v.clear();
	cout << v.size() << " " << v.capacity() << endl;

}