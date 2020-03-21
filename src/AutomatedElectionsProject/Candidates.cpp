#include "Candidates.h"

void Candidates::Add(Candidate* candidate)
{
	if (_array == nullptr)
	{
		_array = new Candidate* [1];
		_physicalCount = 1;
	}
	else if (_count == _physicalCount)
	{
		Candidate** newArray = new Candidate* [2 * _physicalCount];
		for (int i = 0; i < _count; ++i)
		{
			newArray[i] = _array[i];
		}
		delete[] _array;
		_array = newArray;
		_physicalCount *= 2;
	}

	_array[_count] = candidate;
	_count++;
}

Candidate& Candidates::Get(int index) const
{
	return  *_array[index];
}

int Candidates::GetCount() const
{
	return _count;
}

void Candidates::Free() const
{
	for (int i = 0; i < _count; ++i)
	{
		_array[i]->Free();
		delete _array[i];
	}
	delete[] _array;
}


