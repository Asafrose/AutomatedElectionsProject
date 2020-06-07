#include "Results.h"



Results::Results(const Array<Party*>& parties)
{
	_votersCount = 0;
	_partyCount = parties.GetSize();

	for (int i = 0; i < _partyCount; i++)
	{
		_partyResults.push_back(new PartyResult(parties[i]->GetName()));
	}
}

Results::Results(const Results& other): _votersCount(other._votersCount), _partyCount(other._partyCount)
{
	for (int i = 0; i < other._partyResults.size(); ++i)
	{
		_partyResults.push_back(new PartyResult(*other._partyResults[i]));
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
}

void Results::Aggregate(const Results& other) noexcept(false)
{
	for (int i = 0; i < _partyCount; ++i)
	{
		_partyResults[i]->Aggregate(*other._partyResults[i]);
	}
	_votersCount += other._votersCount;
}
