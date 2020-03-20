#ifndef ELECTIONS_H
#define ELECTIONS_H
#include "BallotBoxes.h"
#include "Date.h"
#include "Parties.h"

class Elections
{

private:
	bool _isElectionsDone;
	Date _date;
	Parties _parties;
	BallotBoxes _ballotBoxes;
	Results _results;
	
public:
	void Initialize();
	
	void AddBallotBox(BallotBox& ballotBox);
	void AddCandidate(Candidate& candidate, Party& party);
	void AddCivilian(Civilian& civilian);
	void AddParty(Party& party);

	Parties& GetParties();
	BallotBoxes& GetBallotBoxes();
	
	void PreformElections();
	void ShowResults();
};
#endif // ELECTIONS_H
