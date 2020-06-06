#ifndef RESULTS_H
#define RESULTS_H

#include "PartyResult.h"
#include "Array.h"
#include "Party.h"

class Results
{
private:
	int _votersCount;
	int _partyCount;
	PartyResult** _partyResults;

public:
	Results(const Array<Party*>& parties);
	~Results();

	void AddVote(const Party& party);
	int GetVotersCount() const;
	void Show() const;
	void Aggregate(const Results& other);
};
#endif // RESULTS_H
