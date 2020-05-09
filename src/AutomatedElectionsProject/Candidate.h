#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Civilian.h"


class Candidate : public Civilian
{
private:
	int _rank;
	Party* _party;
	
public:
	Candidate(Civilian* civilian,Party* party, int rank);

	Party& GetParty();
	int& GetRank();
};


#endif // CANDIDATE_H
