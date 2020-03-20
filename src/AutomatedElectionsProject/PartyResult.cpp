#include "PartyResult.h"
#include <iostream>
using namespace std;

bool PartyResult::Initialize(const char* name)
{
	if (name == nullptr)
	{
		return false;
	}
	_name = name;
	_votes = 0;
	return true;
}


void PartyResult::AddVote()
{
	_votes++;
}


void PartyResult::Show() const
{
	cout << "Party: " << _name << " Votes: " << _votes << endl;
}

bool PartyResult::Aggregate(const PartyResult& other)
{
	if (strcmp(_name, other._name) != 0)
	{
		std::cout << "Cannot aggregate party results of different parties [this=";
	}
	return false;
}
