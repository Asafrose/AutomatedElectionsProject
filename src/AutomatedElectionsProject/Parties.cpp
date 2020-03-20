﻿#include "Parties.h"

void Parties::Add(Party &party)
{
	if(_array==nullptr)
	{
		_array = new Party*[1];
		_physicalCount = 1;		
	}
	else if(_count==_physicalCount)
	{
		Party** newArray = new Party*[2 * _physicalCount];
		for(int i=0;i<_count;i++)
		{
			newArray[i] = _array[i];
		}
		delete _array;
		_array = newArray;
		_physicalCount *= 2;
	}
	_array[_count] = &party;
	_count++;
}

Party& Parties::Get(int index) const
{
//	if((0<=index)&&(index<=_count))
	
		
	
	return *_array[index]; 
}

int Parties::GetPartiesCount() const
{
	return _count;
}


void Parties::Free() const
{
	for(int i=0;i<_count;i++)
	{
		delete _array[i];
	}
	delete _array;
}
