
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
	void Add(Candidate* candidate);
	Candidate& Get(int index) const;
	int GetCount() const;
	void Free() const;
	void Sort() const;
};
#endif // CANDIDATES_H
