#ifndef ELECTIONS_H
#define ELECTIONS_H
#include "Array.h"

#include "Date.h"
#include "Party.h"

class Elections
{
private:
	bool _isElectionsOccured;
	Date _date;
	Array<Party*> _parties;
	vector<BallotBox*> _ballotBoxes;
	vector<Civilian*> _civilians;

	bool IsActionValid(const string& actionName, bool isValidBeforeElections = true) const;

public:
	Elections(const Date& date);
	~Elections() = default;

	void AddBallotBox(BallotBox* ballotBox);
	void AddCandidate(Candidate& candidate, Party& party) const;
	void AddCivilian(Civilian* civilian) noexcept(false);
	void AddParty(Party* party);

	Date GetDate() const;
	Array<Party*>& GetParties();
	vector<BallotBox*>& GetBallotBoxes();
	void SetBallotBoxes(const vector<BallotBox*>& ballotBoxes);
	void SetCivilians(const vector<Civilian*>& civilians);
	vector<Civilian*>& GetCivilians();
	Date& GetElectionsDate();
	bool IsElectionsOccured() const;
	void ShowResults() const;
	void ShowAllCivilians() const;
	void ShowAllParties() const;
	void ShowAllBallotBoxes() const;
	void ShowAllValidBallotBoxes(Civilian& civilian) const;
	void StartElections();
};


#endif // ELECTIONS_H
