#ifndef RESULTS_H
#define RESULTS_H

#include "PartyResult.h"
#include "Party.h"

class Results
{
private:
	int _votersCount;
	int _partyCount;
	PartyResult* _partyResult;
	
public:
	void Initialize(const Party* parties, int count);
	void AddVote(const Party& party);
	int GetVotersCount();
	void Show();
};
#endif // RESULTS_H
