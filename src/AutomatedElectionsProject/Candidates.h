
#ifndef CANDIDATES_H
#define CANDIDATES_H

#include "Candidate.h"

class Candidates
{
private:
	Candidate** _candidates = nullptr;
	int _count = 0;

public:
	void Add(Candidate candidate);
	Candidate& Get(int index);
};
#endif // CANDIDATES_H
