﻿#include "Civilians.h"

void Civilians::Add(Civilian* civilian)
{
	if (_array == nullptr)
	{
		_array = new Civilian*[1];
		_physicalCount = 1;
	}
	else if (_count == _physicalCount)
	{
		Civilian** newArray = new Civilian*[2 * _physicalCount];
		for (int i = 0; i < _count; ++i)
		{
			newArray[i] = _array[i];
		}
		delete[] _array;
		_array = newArray;
		_physicalCount *= 2;
	}

	_array[_count] = civilian;
	_count++;
}

Civilian& Civilians::Get(int index) const
{
	return *_array[index];
}

int Civilians::GetCount() const
{
	return _count;
}



Civilians::~Civilians()
{
	for (int i = 0; i < _count; ++i)
	{
		delete _array[i];
	}
	delete[] _array;
}
