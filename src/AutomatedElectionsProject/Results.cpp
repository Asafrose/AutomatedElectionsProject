#include "Results.h"

void Results::Initialize(const Parties& parties)
{
	_votersCount = 0;
	_partyCount = parties.GetPartiesCount();
	_partyResult = new PartyResult[_partyCount];

	for (int i = 0; i < _partyCount; i++)
	{
		Party party = parties.Get(i);
		_partyResult[party.GetId()].Initialize(party.GetName());
	}
}

void Results::AddVote(const Party& party)
{
	_partyResult[party.GetId()].AddVote();
	_votersCount++;
}

int Results::GetVotersCount() const
{
	return _votersCount;
}

void Results::Show() const
{
	for (int i = 0; i < _partyCount; i++)
	{
		_partyResult[i].Show();
	}
}
