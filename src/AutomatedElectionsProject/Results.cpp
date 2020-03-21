#include "Results.h"

void Results::Initialize(const Parties& parties)
{
	_votersCount = 0;
	_partyCount = parties.GetPartiesCount();
	_partyResults = new PartyResult[_partyCount];

	for (int i = 0; i < _partyCount; i++)
	{
		Party party = parties.Get(i);
		_partyResults[party.GetId()].Initialize(party.GetName());
	}
}

void Results::AddVote(const Party& party)
{
	_partyResults[party.GetId()].AddVote();
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
		_partyResults[i].Show();
	}
}

void Results::Free() const
{
	for (int i = 0; i < _partyCount; ++i)
	{
		_partyResults[i].Free();
	}
	delete[] _partyResults;
}

void Results::Aggregate(const Results& other) const
{
	for (int i = 0; i < _partyCount; ++i)
	{
		_partyResults[i].Aggregate(other._partyResults[i]);
	}
}
