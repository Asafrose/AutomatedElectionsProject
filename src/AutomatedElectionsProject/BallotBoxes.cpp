#include "BallotBoxes.h"

void BallotBoxes::Add(BallotBox* ballotBox)
{
	if (_array == nullptr)
	{
		_array = new BallotBox* [1];
		_physicalCount = 1;
	}
	else if (_count == _physicalCount)
	{
		BallotBox** newArray = new BallotBox* [_physicalCount * 2];
		for (int i = 0; i < _count; ++i)
		{
			newArray[i] = _array[i];
		}
		delete[] _array;
		_array = newArray;
		_physicalCount *= 2;
	}

	_array[_count] = ballotBox;
	_count++;
}

BallotBox& BallotBoxes::Get(int index) const
{
	return *_array[index];
}

int BallotBoxes::GetCount() const
{
	return _count;
}

void BallotBoxes::Free() const
{
	for (int i = 0; i < _count; ++i)
	{
		_array[i]->Free();
		delete _array[i];
	}
	delete[] _array;
}
