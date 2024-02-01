#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

template<typename T, typename Container = vector<T>>
class Stack
{

public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

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

