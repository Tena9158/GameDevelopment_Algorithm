#include <iostream>
#include <list>
using namespace std;

template<typename T>
class Node
{
public:
    Node() : _prev(nullptr), _next(nullptr), _data(T())
    {

    }

    Node(const T& value) : _prev(nullptr), _next(nullptr), _data(value)
    {

    }


public:
    // Node*의 경우 주소값이기에 아래와 같이 써도 상관없다
    Node* _prev; // 이전 노드
    Node* _next; // 다음 노드
    T _data; // 데이터

};

template<typename T>
class Iterator
{
public:
    Iterator() : _node(nullptr)
    {

    }

    Iterator(Node<T>* node) : _node(node)
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
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

    // *it
    T& operator*()
    {
        return _node->_data;
    }

    bool operator==(const Iterator& other)
    {
        return _node == other._node;
    }

    bool operator!=(const Iterator& other)
    {
        return _node != other._node;
    }


public:
    Node<T>* _node;
};

template<typename T>
class List
{

public:
    List() : _size(0)
    {
        // 더미 노드를 만들어서 따로 null 체크를 하지 않도록 만든다.
        // [head] <-> ... <-> [tail]
        _head = new Node<T>();
        _tail = new Node<T>();
        _head->_next = _tail;
        _tail->_prev = _head;

    }

    ~List()
    {
        while (_size > 0)
            pop_back();

        delete _head;
        delete _tail;
    }

    void push_back(const T& value)
    {
        AddNode(_tail, value);
    }
    void pop_back()
    {
        RemoveNode(_tail->_prev);
    }

private:
    // [head] <-> [1] <-> [prevNode] <-> [before] <-> [tail]
    // [head] <-> [1] <-> [prevNode] <-> [newNode] <-> [before] <-> [tail]

    Node<T>* AddNode(Node<T>* before, const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        Node<T>* prevNode = before->_prev;

        prevNode->_next = newNode;
        newNode->_prev = prevNode;

        before->_prev = newNode;
        newNode->_next = before;

        _size++;

        return newNode;
    }

    // [head] <-> [prevNode] <-> [node] <-> [nextNode] <-> [tail]
    // [head] <-> [prevNode] <-> [nextNode] <-> [tail]
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
    using iterator = Iterator<T>;

    iterator begin() { return iterator(_head->_next); }
    iterator end() { return iterator(_tail); }

    // it '앞'에 추가한다.
    // [before]
    // [newNode] <-> [before]
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
    Node<T>*    _head; // 시작 노드
    Node<T>*    _tail; // 끝 노드
    int         _size;
};

int main()
{
	// vector
// - push_back - O(1)
// - push_front - O(N)
// [0][0][0][0][0][ ]
// [X][0][0][0][0][0]

// li[3] = 3; -> Random Access X


    List<int> li;

    List<int>::iterator eraseit;
    // n번째 데이터를 찾는 것은 느린데, n번째 데이터를 삭제하는건 쉽다 ?
    // 중간에 있는 데이터를 삭제하는것은 마찬가지로 오랜 시간이 걸린다.
    // 대신, iterator를 이용해서 삭제할 값을 저장해두고, 해당 값을 삭제하는것은 상수 시간
    // 즉 리스트에서 삽입, 삭제가 빠르다는 것은 조건부적으로 맞는말이다.

    // [ ] <-> [ ] <-> [ ]
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            // (내가 넣어줄 위치 바로 다음, 값)
            // 반환값이 iterator이기에 저장이 가능하다.
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