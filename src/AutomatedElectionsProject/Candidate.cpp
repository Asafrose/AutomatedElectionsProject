#include "Candidate.h"
#include "Civilian.h"

Candidate::Candidate(Civilian* civilian, Party* party, int rank): Civilian(*civilian), _rank(rank), _party(party)
{
}

Party& Candidate::GetParty()
{
	return *_party;
}


int& Candidate::GetRank()
{
	return _rank;
}
