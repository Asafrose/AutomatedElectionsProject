#include "BallotBox.h"
#include <fstream>
#include <iostream>
#include "FileHelper.h"
using namespace std;

int BallotBox::_counter = 1;



BallotBox::BallotBox(const Address& address, const Date& electionsDate) : _id(_counter++), _address(address),
                                                                          _results(nullptr),
                                                                          _electionsDate(electionsDate)
{
}

BallotBox::BallotBox(ifstream& file,const Date& electionsDate) : _address(file),_results(nullptr), _electionsDate(electionsDate)
{
	FileHelper::Read(_id, file);
	++_counter;
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
	if (_results->GetVotersCount() == 0)
	{
		return 0;
	}
	return (double)_results->GetVotersCount() / (double)_civilians.size();
}

Results& BallotBox::GetResults() const
{
	return *_results;
}

int BallotBox::GetId() const
{
	return _id;
}

vector<Civilian*>& BallotBox::GetCivilians()
{
	return _civilians;
}

bool BallotBox::CanAdd(Civilian& civilian) const
{
	return !civilian.IsInArmy(_electionsDate) && !civilian.GetIsQuarantined();
}

void BallotBox::ClosePartyList(const Array<Party*>& parties)
{
	if (_results != nullptr)
	{
		return;
	}

	_results = new Results(parties);
}

void BallotBox::AddCivilian(Civilian* civilian)
{
	if (!CanAdd(*civilian))
	{
		throw Exception("Cannot add civilian");
	}

	_civilians.push_back(civilian);
}

void BallotBox::Show(bool showResults) const
{
	cout << "Ballot Box: ";
	cout << "id: " << _id << " address: ";
	cout << _address << "  ";
	cout << "BallotBoxType: " << typeid(*this).name() + 6 << endl;

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

void BallotBox::Save(ofstream& file) const
{
	FileHelper::WriteString(typeid(*this).name(),file);
	_address.Save(file);
	FileHelper::Write(_id,file);
}

BallotBox::~BallotBox()
{
	delete _results;
}
