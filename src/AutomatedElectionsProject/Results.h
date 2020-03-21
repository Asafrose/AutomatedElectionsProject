#ifndef RESULTS_H
#define RESULTS_H

#include "PartyResult.h"
#include "Parties.h"

class Results
{
private:
	int _votersCount;
	int _partyCount;
	PartyResult* _partyResults;

public:
	void Initialize(const Parties& parties);

	void AddVote(const Party& party);
	int GetVotersCount() const;
	void Show() const;
	void Free() const;
	void Aggregate(const Results& other) const;
};
#endif // RESULTS_H
