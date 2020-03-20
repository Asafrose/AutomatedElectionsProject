#include "Civilians.h"

void Civilians::AddCivilian(Civilian& civilian)
{
	if (_civilians == nullptr)
	{
		_civilians = new Civilian*[1];
		_physicalCount = 1;
	}
	else if (_count == _physicalCount)
	{
		Civilian** newArray = new Civilian*[2*_physicalCount];
		for (int i = 0; i < _count; ++i)
		{
			newArray[i] = _civilians[i];
		}
		delete[] _civilians;
		_civilians = newArray;
		_physicalCount *= 2;
	}

	_civilians[_count] = &civilian;
	_count++;
}

Civilian& Civilians::GetCivilian(int index) const
{
	return *_civilians[index];
}

int Civilians::GetCount() const
{
	return _count;
}

void Civilians::Free() const
{
	delete[] _civilians;
}


