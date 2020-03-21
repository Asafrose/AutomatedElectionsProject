#ifndef ELECTIONS_H
#define ELECTIONS_H
#include "BallotBoxes.h"
#include "Date.h"
#include "Parties.h"

class Elections
{
private:
	bool _isElectionsOccured;
	Date _date;
	Parties _parties;
	BallotBoxes _ballotBoxes;

	bool IsActionValid(const char* actionName, bool isValidBeforeElections = true) const;

public:
	void Initialize(const Date& date);

	void AddBallotBox(BallotBox* ballotBox);
	void AddCandidate(Candidate& candidate, Party& party) const;
	void AddCivilian(Civilian& civilian) const;
	void AddParty(Party& party);

	Parties& GetParties();
	BallotBoxes& GetBallotBoxes();
	Date& GetElectionsDate();
	bool IsElectionsOccured() const;
	void ShowResults() const;
};


#endif // ELECTIONS_H
