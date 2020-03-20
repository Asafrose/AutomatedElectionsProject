#include "Candidate.h"

void Candidate::Initialize(const Civilian& civilian, int rank)
{
	_civilian = civilian,
	_rank = rank;
}

Civilian& Candidate::GetCivilian() const
{
	return _civilian;
}

