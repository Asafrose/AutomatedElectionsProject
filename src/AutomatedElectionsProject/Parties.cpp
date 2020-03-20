#include "Parties.h"

void Parties::Add(Party &party)
{
	if(_parties==nullptr)
	{
		_parties = new Party*[1];
		_physicalCount = 1;		
	}
	else if(_count==_physicalCount)
	{
		Party** newArray = new Party*[2 * _physicalCount];
		for(int i=0;i<_count;i++)
		{
			newArray[i] = _parties[i];
		}
		delete _parties;
		_parties = newArray;
		_physicalCount *= 2;
	}
	_parties[_count] = &party;
	_count++;
}

Party& Parties::Get(int index) const
{
//	if((0<=index)&&(index<=_count))
	
		
	
	return *_parties[index]; 
}

int Parties::GetPartiesCount() const
{
	return _count;
}


void Parties::free() const
{
	
}
