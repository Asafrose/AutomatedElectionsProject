#include "Civilians.h"

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

void Civilians::RemoveById(int civilianId)
{
	int index = 0;
	while (_array[index]->GetId() != civilianId)
	{
		index++;
	}

	for (; index < _count - 1; index++)
	{
		_array[index] = _array[index + 1];
	}

	_count--;
}

void Civilians::operator+=(Civilian* civilian)
{
	Add(civilian);
}

Civilians::Civilians() : _count(0), _physicalCount(0)
{
	_array = nullptr;
}

Civilians::~Civilians()
{
	for (int i = 0; i < _count; ++i)
	{
		delete _array[i];
	}
	delete[] _array;
}
