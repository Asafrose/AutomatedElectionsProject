#include "Elections.h"

#include <iostream>

using namespace std;

bool Elections::IsActionValid(const char* actionName, bool isValidBeforeElections) const
{
	if ((isValidBeforeElections && _isElectionsOccured) || (!isValidBeforeElections && !_isElectionsOccured))
	{
		cout <<
			"Action Cannot be preformed in this election state [actionName=" <<
			actionName <<
			" isElectionsDone=" <<
			_isElectionsOccured <<
			"]" <<
			endl;
		return false;
	}

	return true;
}

void Elections::Initialize(const Date& date)
{
	if (IsActionValid("Initialize"))
	{
		_date = date;
	}
}

void Elections::AddBallotBox(BallotBox* ballotBox)
{
	if (IsActionValid("AddBallotBox"))
	{
		_ballotBoxes.Add(ballotBox);
	}
}

void Elections::AddCandidate(Candidate* candidate, Party& party) const
{
	if (IsActionValid("AddCandidate"))
	{
		party.AddCandidate(candidate);
	}
}

void Elections::AddCivilian(Civilian* civilian) const
{
	if (IsActionValid("AddCivilian"))
	{
		civilian->GetBallotBox()->AddCivilian(civilian);
	}
}

void Elections::AddParty(Party* party)
{
	if (IsActionValid("AddParty"))
	{
		_parties.Add(party);
	}
}

Parties& Elections::GetParties()
{
	return _parties;
}

BallotBoxes& Elections::GetBallotBoxes()
{
	return _ballotBoxes;
}

Date& Elections::GetElectionsDate()
{
	return _date;
}

bool Elections::IsElectionsOccured() const
{
	return _isElectionsOccured;
}


void Elections::ShowResults() const
{
	Results results;
	results.Initialize(_parties);

	for (int i = 0; i < _ballotBoxes.GetCount(); ++i)
	{
		BallotBox ballotBox = _ballotBoxes.Get(i);
		ballotBox.Show();
		cout << "\n\n";
		results.Aggregate(ballotBox.GetResults());
	}

	cout << "TotalResults:\n";
	results.Show();
	results.Free();
}

void Elections::ShowAllCivilians() const
{
	for (int i = 0; i < _ballotBoxes.GetCount(); ++i)
	{
		Civilians civilians = _ballotBoxes.Get(i).GetCivilians();
		for (int j = 0; j < civilians.GetCount(); ++j)
		{
			civilians.Get(j).Show();
			cout << endl;
		}
	}
}

void Elections::ShowAllParties() const
{
	for (int i = 0; i < _parties.GetCount(); ++i)
	{
		_parties.Get(i).Show();
		cout << "\n";
	}
}

void Elections::Free() const
{
	_ballotBoxes.Free();
	_parties.Free();
}

void Elections::ShowAllBallotBoxes() const
{
	cout << "*** Ballot Boxes : ***"<< endl;
	for(int i=0;i<_ballotBoxes.GetCount();i++)
	{
		_ballotBoxes.Get(i).Show();
		cout << endl;
	}
	cout << "*** End of List ***";
}

