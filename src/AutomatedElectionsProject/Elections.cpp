#include "Elections.h"

#include <iostream>

#include "Exception.h"
#include "Results.h"
#include "BallotBox.h"

using namespace std;

bool Elections::IsActionValid(const string& actionName, bool isValidBeforeElections) const
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
		_ballotBoxes.push_back(ballotBox);
	}
}

void Elections::AddCandidate(Candidate& candidate, Party& party) const
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
		_civilians.push_back(civilian);
	}
}

void Elections::AddParty(Party* party)
{
	if (IsActionValid("AddParty"))
	{
		_parties += party;
	}
}

Date Elections::GetDate() const
{
	return _date;
}

Array<Party*>& Elections::GetParties()
{
	return _parties;
}

vector<BallotBox*>& Elections::GetBallotBoxes()
{
	return _ballotBoxes;
}

void Elections::SetBallotBoxes(const vector<BallotBox*>& ballotBoxes)
{
	_ballotBoxes = ballotBoxes;
}

void Elections::SetCivilians(const vector<Civilian*>& civilians)
{
	_civilians = civilians;
}

vector<Civilian*>& Elections::GetCivilians()
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

		for (int i = 0; i < _ballotBoxes.size(); ++i)
		{
			BallotBox* ballotBox = _ballotBoxes[i];
			ballotBox->Show(true);
			cout << "BallotBox Voting Percent: " << ballotBox->GetVotingPercent() * 100;
			cout << "\n\n";
			results.Aggregate(ballotBox->GetResults());
		}

		cout << "TotalResults:\n";
		results.Show();
		cout << "Total Voting Percent: " << (double)results.GetVotersCount() / _civilians.size() * 100 << endl;
	}
}


void Elections::ShowAllCivilians() const
{
	cout << "*** ShowAllCivilians Started ***" << endl;
	for (int i = 0; i < _civilians.size(); ++i)
	{
		cout << *_civilians[i] << endl;
	}
	cout << " *** ShowAllCivilians Finished ***" << endl;
}

void Elections::ShowAllParties() const
{
	cout << "*** ShowAllParties Started ***" << endl;
	for (int i = 0; i < _parties.GetSize(); ++i)
	{
		_parties[i]->Show();
	}
	cout << "*** ShowAllParties Finished ***" << endl;
}


void Elections::ShowAllBallotBoxes() const
{
	cout << "*** ShowAllBallotBoxes Started ***" << endl;
	for (int i = 0; i < _ballotBoxes.size(); i++)
	{
		_ballotBoxes[i]->Show(false);
	}
	cout << "*** ShowAllBallotBoxes Finished ***" << endl;
}

void Elections::ShowAllValidBallotBoxes(Civilian& civilian) const
{
	cout << "*** ShowAllValidBallotBoxes Started ***" << endl;
	for (int i = 0; i < _ballotBoxes.size(); i++)
	{
		if (_ballotBoxes[i]->CanAdd(civilian))
		{
			_ballotBoxes[i]->Show(false);
		}
	}
	cout << "*** ShowAllValidBallotBoxes Finished ***" << endl;
}


void Elections::StartElections()
{
	if (IsActionValid("StartElections"))
	{
		_isElectionsOccured = true;
		for (int i = 0; i < _ballotBoxes.size(); i++)
		{
			_ballotBoxes[i]->ClosePartyList(_parties);
		}
	}
}
