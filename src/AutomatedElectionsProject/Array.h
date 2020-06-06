#ifndef ARRAY_H
#define ARRAY_H
#include <ostream>

#include "Exception.h"

using namespace std;

template<class TItem>
class Array
{
	unsigned int _physicalSize;
	unsigned int _logicalSize;
	char _delimiter;
	TItem* _arr;
public:
	Array(unsigned int size = 10, char delimiter = ' ') noexcept(false) : _physicalSize(size), _logicalSize(0), _delimiter(delimiter)
	{
		if (_physicalSize == 0)
		{
			throw Exception("size must be greater than 0");
		}
		
		_arr = new TItem[_physicalSize];
	}
	
	Array(const Array& other) : _arr(nullptr)
	{
		*this = other;
	}
	
	~Array()
	{
		delete[] _arr;
	}

	const Array& operator=(const Array& other)
	{	
		if (this != &other)
		{
			delete[] _arr;
			_physicalSize = other._physicalSize;
			_logicalSize = other._logicalSize;
			_delimiter = other._delimiter;
			_arr = new TItem[_physicalSize];
			for (int i = 0; i < _logicalSize; ++i)
			{
				_arr[i] = other._arr[i];
			}
		}
		return *this;
	}
	
	const Array& operator+=(const TItem& newVal)
	{
		if (_logicalSize == _physicalSize)
		{
			TItem* newArr = new TItem[_physicalSize * 2];
			for (int i = 0; i < _logicalSize; ++i)
			{
				newArr[i] = _arr[i];
			}
			delete[] _arr;
			_arr = newArr;
		}

		_arr[_logicalSize++] = newVal;

		return *this;
	}
	
	TItem& operator[](const int& index)
	{
		return _arr[index];
	}

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr._logicalSize; ++i)
		{
			os << arr._arr[i] << arr._delimiter;
		}
		return os;
	}
};
#endif // ARRAY_H
