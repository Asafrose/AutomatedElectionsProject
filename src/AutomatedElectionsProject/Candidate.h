
#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Civilian.h"

class Candidate
{
private:
	Civilian& _civilian;
	int _rank;
public:
	void SetCandidate(const Civilian& civilian, int rank);
	Civilian& GetCivilian();
};


#endif // CANDIDATE_H
