#include "Candidates.h"

#include <cstdlib>

int CompareCandidates(const void* a, const void* b)
{
	int candidateARank = (**(Candidate**)a).GetRank();
	int candidateBRank = (**(Candidate**)b).GetRank();

	return candidateARank > candidateBRank
		       ? 1
		       : candidateARank == candidateBRank
		       ? 0
		       : -1;
}

Candidates::~Candidates()
{
	for (int i = 0; i < _count; ++i)
	{
		delete _array[i];
	}
	delete[] _array;
}

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
	return *_array[index];
}

int Candidates::GetCount() const
{
	return _count;
}

void Candidates::Sort() const
{
	qsort(_array, _count, sizeof(Candidate*), CompareCandidates);
}
