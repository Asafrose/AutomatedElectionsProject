
#ifndef CANDIDATE_H
#define CANDIDATE_H

#include "Civilian.h"

class Candidate
{
private:
	Civilian& _civilian;
	int _rank;
public:
	void Initialize(const Civilian& civilian, int rank);
	Civilian& GetCivilian() const;
};


#endif // CANDIDATE_H
