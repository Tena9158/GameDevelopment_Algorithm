#include <iostream>
#include <vector>
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

    // [ ][ ][ ][ ][ ][ ]
    // [ ][ ][ ][ ][ ]
    void push_back(const T& value)
    {
        // [ ][ ][ ][ ][ ] 모든 공간을 다 사용하고있는가 ?
        if (_size == _capacity)
        {
            // 증설 작업
            int newCapacity = static_cast<int>(_capacity * 1.5f);

            // 증설을 했음에도 값이 같은 경우 (0, 1일때)
            if (newCapacity == _capacity)
                newCapacity++;

            // 증설한 방 만큼 예약
            reserve(newCapacity);
        }

        // [ ][ ][ ][ ][ ]
        // 데이터 저장
        _data[_size] = value;

        // [ ][ ][ ][ ][ ][ ]
        // 데이터 개수 증가
        _size++;
    }
    
    void reserve(int capacity)
    {
        // 예약한 방 보다 기존의 방이 더 많은가 ?
        if (_capacity >= capacity)
            return;

        // 기존의 예약된 방의 개수를 새로운 개수로 변경시켜준다.
        _capacity = capacity;

        // 요청 받은 정보를 기반으로 방을 증설
        T* newData = new T[_capacity];

        // 데이터 복사
        for (int i = 0; i < _size; i++)
            newData[i] = _data[i];

        // 기존에 있던 정보는 삭제
        if (_data)
            delete[] _data;

        // 교체
        _data = newData;
    }

    T& operator[](const int pos) { return _data[pos]; }

    int size() { return _size; }
    int capacity() { return _capacity; }

    void clear()
    {
        if (_data)
        {
            // 실제로는 이런 상황일 때 new, delete와 같은 짝을 이용하지않는다.
            
            // malloc, free같은 할당자를 이용해서 메모리를 할당 받고,
            // 소멸자랑 생성자를 직접 위에다가 사용하는 식으로 만듦.

            delete[] _data;
            _data = new T[_capacity];
        }

        _size = 0;
    }

private:
    T*      _data = nullptr;
    int     _size = 0;
    int     _capacity = 0;
};

int main()
{
    vector<int> v;
    //Vector<int> v;

    // Size : 실질적으로 사용중인 데이터의 개수
    // Capacity : 예약한 데이터(여유분)의 개수. (약 1.5배씩 증가)
    
	// Resize : size의 크기를 증가시키나, 만약 size가 capacity를 초과한다면 capacity도 늘어나게 된다. 만약 이미 크기가 커진 상태에서 크기를 줄이게된다면, 줄인 크기 이전의 데이터들은 전부 날아가게된다.
	// Reserve : capacity의 크기를 특정 크기만큼 증설시켜준다.

    // 예약을 먼저 해두고 시작하면, capacity의 변화를 최소화시킬 수 있기에 더욱 효율적이다
    v.reserve(100);
    // v.resize(10);


    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
        cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
    }

    
    v.clear();
    cout << v.size() << " " << v.capacity() << endl;

}
