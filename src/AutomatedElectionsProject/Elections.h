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
	Civilians _civilians;

	bool IsActionValid(const char* actionName, bool isValidBeforeElections = true) const;

public:
	void Initialize(const Date& date);

	void AddBallotBox(BallotBox* ballotBox);
	void AddCandidate(Candidate* candidate, Party& party) const;
	void AddCivilian(Civilian* civilian);
	void AddParty(Party* party);

	Parties& GetParties();
	BallotBoxes& GetBallotBoxes();
	Civilians& GetCivilians();
	Date& GetElectionsDate();
	bool IsElectionsOccured() const;
	void ShowResults() const;
	void ShowAllCivilians() const;
	void ShowAllParties() const;
	void Free() const;
	void ShowAllBallotBoxes() const;
	void StartElections();
};


#endif // ELECTIONS_H
