#include "BallotBox.h"

#include <iostream>

using namespace std;

void BallotBox::Initialize(const int& id, const Address& address)
{
	_results = nullptr;
	_address = address;
	_id = id;
}

void BallotBox::AddVote(const Party& party) const
{
	if (_results == nullptr)
	{
		return;
	}

	_results->AddVote(party);
}

double BallotBox::GetVotingPercent() const
{
	if (_results == nullptr)
	{
		return 0;
	}

	return static_cast<double>(_results->GetVotersCount()) / static_cast<double>(_civilians.GetCount());
}

Results& BallotBox::GetResults() const
{
	return *_results;
}

void BallotBox::ClosePartyList(const Parties& parties)
{
	if (_results != nullptr)
	{
		return;
	}

	_results = new Results;
	_results->Initialize(parties);
}

void BallotBox::AddCivilian(Civilian* civilian)
{
	_civilians.Add(civilian);
}

void BallotBox::Show() const
{
	cout << "id: " << _id << " address: ";
	_address.Show();
	cout << endl << "Results: " << endl;
	_results->Show();
}

void BallotBox::Free() const
{
	_address.Free();
	_civilians.Free();

	if (_results != nullptr)
	{
		_results->Free();
		delete _results;
	}
}
