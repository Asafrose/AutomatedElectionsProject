#include "Candidate.h"
#include "Civilian.h"

void Candidate::Initialize(Civilian* civilian, int rank)
{
	_civilian = new Civilian;
	_civilian->Initialize(*civilian);
	_rank = rank;
}

Civilian& Candidate::GetCivilian() const
{
	return *_civilian;
}

int& Candidate::GetRank()
{
	return _rank;
}

void Candidate::Free() const
{
	_civilian->Free();
	delete _civilian;
}

