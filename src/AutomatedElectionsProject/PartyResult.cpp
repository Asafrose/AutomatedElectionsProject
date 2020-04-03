#define _CRT_SECURE_NO_WARNINGS

#include "PartyResult.h"
#include <iostream>

using namespace std;

PartyResult::PartyResult(const char* name)
{
	if (name == nullptr)
	{
		//future exception handaling
	}
	
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	
	_votes = 0;
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
		std::cout << "Cannot aggregate party results of different parties [this=" << _name << " other=" << other._name << "]\n";
		return false;
	}
	
	_votes += other._votes;
	return true;
}

PartyResult::~PartyResult()
{
	delete[] _name;
}
