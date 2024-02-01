#include <iostream>
#include <list>
using namespace std;
// Node
template<typename T>
class Node
{
public:
	Node() : _prev(nullptr), _next(nullptr), _data(T())
	{

	}
	Node(const& value) : _prev(nullptr), _next(nullptr), _data(value)
	{

	}
	

public:
	Node* _prev;
	Node* _next;
	T _data;
};

// Iterator
template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}
	Iterator(Node<T>* node) : _node(_node)
	{

	}
	
	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}


	// it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	// it--
	Iterator operator--()
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	// it*
	T* operator()
	{
		return _node->_data;
	}
	
	// ==
	bool operator==(const Iterator& other)
	{
		return _node == other._node;
	}

	// !=
	bool operator!=(const Iterator& other)
	{
		return _node != other._node;
	}

public:
	Node* _node;
};


// List
template<typename T>
class List
{
public:
	List() : size(0)
	{
		_head = new Node<T>();
		_tail = new Node<T>();
		_head->_prev = _tail;
		_tail->_next = _head;
	}
	~List()
	{
		while (_size > 0)
			// TODO

		delete _head;
		delete _tail;
	}

	void push_back(const T& value)
	{
		AddNode(_tail, value);
	}
	void pop_back()
	{

	}

private:
	Node<T>* AddNode(Node<T> before, const T& value)
	{
		Node<T>* newNode = new Node<T>(value);
		Node<T>* prevNode = before->_prev;

		prevNode->_next = newNode;
		newNode->_prev = prevNode;

		newNode->_next = before;
		before->_prev = newNode;

		_size++;

		return newNode;
	}

	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	using iterator = Iterator;

	iterator begin() { return iterator(_head->_next); }
	iterator end() { return iterator(_tail); }

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}
	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

private:
	Node<T> _head;
	Node<T> _tail;
	int _size;
};

int main_Test()
{
	List<int> li;
	List<int>::iterator eraseit;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseit = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}

	}

	li.pop_back();

	li.erase(eraseit);

	for (List<int>::iterator it = li.begin(); it != li.end(); it++)
	{
		cout << (*it) << endl;
	}

}
