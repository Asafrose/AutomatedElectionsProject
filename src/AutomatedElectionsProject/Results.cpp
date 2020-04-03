#include "Results.h"

Results::Results(const Parties& parties)
{
	_votersCount = 0;
	_partyCount = parties.GetCount();
	_partyResults = new PartyResult*[_partyCount];

	for (int i = 0; i < _partyCount; i++)
	{
		Party party = parties.Get(i);
		_partyResults[party.GetId() - 1] = new PartyResult(party.GetName());
	}
}

void Results::AddVote(const Party& party)
{
	_partyResults[party.GetId() - 1]->AddVote();
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
		_partyResults[i]->Show();
	}
}

Results::~Results()
{
	for (int i = 0; i < _partyCount; ++i)
	{
		delete _partyResults[i];
	}
	delete[] _partyResults;
}

void Results::Aggregate(const Results& other)
{
	for (int i = 0; i < _partyCount; ++i)
	{
		_partyResults[i]->Aggregate(*other._partyResults[i]);
	}
	_votersCount += other._votersCount;
}
