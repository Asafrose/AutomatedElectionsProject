#ifndef ELECTIONS_H
#define ELECTIONS_H
#include "BallotBoxes.h"
#include "Date.h"

class Elections
{
private:
	bool _isElectionsOccured;
	Date _date;
	Array<Party*> _parties;
	BallotBoxes _ballotBoxes;
	Civilians _civilians;

	bool IsActionValid(const char* actionName, bool isValidBeforeElections = true) const;

public:
	Elections(const Date& date);
	~Elections() = default;

	void AddBallotBox(BallotBox* ballotBox);
	void AddCandidate(Candidate* candidate, Party& party) const;
	void AddCivilian(Civilian* civilian) noexcept(false);
	void AddParty(Party* party);

	Array<Party*>& GetParties();
	BallotBoxes& GetBallotBoxes();
	Civilians& GetCivilians();
	Date& GetElectionsDate();
	bool IsElectionsOccured() const;
	void ShowResults() const;
	void ShowAllCivilians() const;
	void ShowAllParties() const;
	void ShowAllBallotBoxes() const;
	void ShowAllValidBallotBoxes(Civilian* civilian) const;
	void StartElections();
};


#endif // ELECTIONS_H
