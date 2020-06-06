#include "Elections.h"

#include <iostream>

#include "Exception.h"

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

Elections::Elections(const Date& date): _date(date)
{
	if (_date - Date::Now() < Duration::FromDays(0))
	{
		throw Exception("election date is in the past");
	}
	
	_isElectionsOccured = false;
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

void Elections::AddCivilian(Civilian* civilian) noexcept(false)
{
	if (IsActionValid("AddNewCivilian"))
	{
		if (_date - civilian->GetBirth() < Duration::FromYears(18))
		{
			throw Exception("civilian will not be 18 in the date of the elections");
		}
		
		civilian->GetBallotBox()->AddCivilian(civilian);
		_civilians.Add(new Civilian(*civilian));
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

Civilians& Elections::GetCivilians()
{
	return _civilians;
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
	if (IsActionValid("ShowResults", false))
	{
		Results results(_parties);

		for (int i = 0; i < _ballotBoxes.GetCount(); ++i)
		{
			BallotBox& ballotBox = _ballotBoxes.Get(i);
			ballotBox.Show(true);
			cout << "BallotBox Voting Percent: " << ballotBox.GetVotingPercent() * 100;
			cout << "\n\n";
			results.Aggregate(ballotBox.GetResults());
		}

		cout << "TotalResults:\n";
		results.Show();
		cout << "Total Voting Percent: " << (double)results.GetVotersCount() / _civilians.GetCount() * 100 << endl;
	}
}


void Elections::ShowAllCivilians() const
{
	cout << "*** ShowAllCivilians Started ***" << endl;
	for (int i = 0; i < _civilians.GetCount(); ++i)
	{
		cout << _civilians.Get(i) << endl;
	}
	cout << " *** ShowAllCivilians Finished ***" << endl;
}

void Elections::ShowAllParties() const
{
	cout << "*** ShowAllParties Started ***" << endl;
	for (int i = 0; i < _parties.GetCount(); ++i)
	{
		_parties.Get(i).Show();
	}
	cout << "*** ShowAllParties Finished ***" << endl;
}


void Elections::ShowAllBallotBoxes() const
{
	cout << "*** ShowAllBallotBoxes Started ***" << endl;
	for (int i = 0; i < _ballotBoxes.GetCount(); i++)
	{
		_ballotBoxes.Get(i).Show(false);
	}
	cout << "*** ShowAllBallotBoxes Finished ***" << endl;
}

void Elections::ShowAllValidBallotBoxes(Civilian* civilian) const
{
	cout << "*** ShowAllValidBallotBoxes Started ***" << endl;
	for (int i = 0; i < _ballotBoxes.GetCount(); i++)
	{
		if (_ballotBoxes.Get(i).CanAdd(civilian))
		{
			_ballotBoxes.Get(i).Show(false);
		}
	}
	cout << "*** ShowAllValidBallotBoxes Finished ***" << endl;
}


void Elections::StartElections()
{
	if (IsActionValid("StartElections"))
	{
		_isElectionsOccured = true;
		for (int i = 0; i < _ballotBoxes.GetCount(); i++)
		{
			_ballotBoxes.Get(i).ClosePartyList(_parties);
		}
	}
}
