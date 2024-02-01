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
		// ������ �溸�� ������ ���� �� ������ üũ
		if (-capacity >= capacity)
			return;

		_capacity = capacity;

		// ���� �۾�
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
			// ���� �۾�
			int newCapcity = static_cast<int>(_capacity * 1.5f);

			// ���� ���� ���
			if (newCapcity == _capacity)
				newCapcity++;

			reserve(newCapcity);
		}
		// ������ ����
		_data[_size] = value;
		// ũ�� ����
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