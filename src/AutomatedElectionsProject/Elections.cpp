#include "Elections.h"

#include <iostream>

using namespace std;

bool Elections::IsActionValid(const char* actionName, bool isValidBeforeElections) const
{
	if ((isValidBeforeElections && _isElectionsDone) || (!isValidBeforeElections && !_isElectionsDone))
	{
		cout <<
			"Action Cannot be preformed in this election state [actionName=" <<
			actionName <<
			" isElectionsDone=" <<
			_isElectionsDone <<
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

void Elections::AddBallotBox(BallotBox& ballotBox)
{
	if (IsActionValid("AddBallotBox"))
	{
		_ballotBoxes.Add(ballotBox);
	}
}

void Elections::AddCandidate(Candidate& candidate, Party& party) const
{
	if (IsActionValid("AddCandidate"))
	{
		party.AddCandidate(candidate);
	}
}

void Elections::AddCivilian(Civilian& civilian) const
{
	if (IsActionValid("AddCivilian"))
	{
		civilian.GetBallotBox()->AddCivilian(civilian);
	}
}

void Elections::AddParty(Party& party)
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

bool Elections::GetIsElectionsDone() const
{
	return _isElectionsDone;
}

void Elections::ShowResults()
{
}
