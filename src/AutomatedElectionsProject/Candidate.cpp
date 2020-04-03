#include "Candidate.h"
#include "Civilian.h"

Candidate::Candidate(Civilian* civilian, int rank)
{
	_civilian = new Civilian(*civilian);
	_rank = rank;
}

Candidate::~Candidate()
{
	delete _civilian;
}

Civilian& Candidate::GetCivilian() const
{
	return *_civilian;
}

int& Candidate::GetRank()
{
	return _rank;
}

