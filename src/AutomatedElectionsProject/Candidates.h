
#ifndef CANDIDATES_H
#define CANDIDATES_H

#include "Candidate.h"

class Candidates
{
private:
	Candidate** _array = nullptr;
	int _count = 0;
	int _physicalCount = 0;

public:
	void AddCandidate(Candidate& civilian);
	Candidate& GetCandidate(int index) const;
	int GetCount() const;
	void Free() const;
};
#endif // CANDIDATES_H
