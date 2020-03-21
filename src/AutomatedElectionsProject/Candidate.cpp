#include "Candidate.h"
#include "Civilian.h"

void Candidate::Initialize(Civilian* civilian, int rank)
{
	_civilian = civilian,
	_rank = rank;
}

Civilian& Candidate::GetCivilian() const
{
	return *_civilian;
}

void Candidate::Free() const
{
	_civilian->Free();
	delete _civilian;
}

