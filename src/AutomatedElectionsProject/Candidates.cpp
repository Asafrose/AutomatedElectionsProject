#include "Candidates.h"

void Candidates::AddCandidate(Candidate& civilian)
{
	if (_candidates == nullptr)
	{
		_candidates = new Candidate* [1];
		_physicalCount = 1;
	}
	else if (_count == _physicalCount)
	{
		Candidate** newArray = new Candidate* [2 * _physicalCount];
		for (int i = 0; i < _count; ++i)
		{
			newArray[i] = _candidates[i];
		}
		delete[] _candidates;
		_candidates = newArray;
		_physicalCount *= 2;
	}

	_candidates[_count] = &civilian;
	_count++;
}

Candidate& Candidates::GetCandidate(int index) const
{
	return  *_candidates[index];
}

int Candidates::GetCount() const
{
	return _count;
}

void Candidates::Free() const
{
	delete[] _candidates;
}


