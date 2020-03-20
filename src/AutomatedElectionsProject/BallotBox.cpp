#include "BallotBox.h"

#include <iostream>

using namespace std;

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
	
	return (double)_results->GetVotersCount() / (double)_civilians.GetCount();
}


void BallotBox::Initialize(const int& id, const Address& address)
{
	_results = nullptr;
	_address = address;
	_id = id;
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

void BallotBox::AddCivilian(Civilian& civilian)
{
	_civilians.AddCivilian(civilian);
}

void BallotBox::Show() const
{
	cout << "id: " << _id << " address: ";
	_address.Show();
	cout << endl << "results: " << endl;
	_results->Show();
}

void BallotBox::Free() const
{
	delete _results;
}
