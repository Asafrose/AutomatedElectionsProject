#include "BallotBox.h"

#include <iostream>

using namespace std;

int BallotBox::_counter = 1;

BallotBox::BallotBox(const Address& address) : _address(address)
{
	_results = nullptr;
	_id = _counter++;
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

	return (double)_results->GetVotersCount() / (double)_civilians.GetCount();
}

Results& BallotBox::GetResults() const
{
	return *_results;
}

Civilians& BallotBox::GetCivilians()
{
	return _civilians;
}

void BallotBox::ClosePartyList(const Parties& parties)
{
	if (_results != nullptr)
	{
		return;
	}

	_results = new Results(parties);
}

void BallotBox::AddCivilian(Civilian* civilian)
{
	_civilians.Add(civilian);
}

void BallotBox::Show(bool showResults) const
{
	cout << "Ballot Box: ";
	cout << "id: " << _id << " address: ";
	cout << _address;

	if (showResults)
	{
		cout << "Results: " << endl;
		if (_results != nullptr)
		{
			_results->Show();
		}
		else
		{
			cout << "no results" << endl;
		}
	}
}

BallotBox::~BallotBox()
{
	delete _results;
}
