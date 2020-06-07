#define _CRT_SECURE_NO_WARNINGS

#include "PartyResult.h"
#include <iostream>
#include <sstream>
#include "Exception.h"

using namespace std;

PartyResult::PartyResult(const string& name) noexcept(false) : _name(name)
{
	if (name.empty())
	{
		throw Exception("Invalid Party name");
	}
	
	
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

bool PartyResult::Aggregate(const PartyResult& other) noexcept(false)
{
	if (_name != other._name)
	{
		stringstream exceptionString; 
		exceptionString << "Cannot aggregate party results of different parties [this=" << _name << " other=" << other._name << "]\n";
		throw Exception(exceptionString.str());
	}
	
	_votes += other._votes;
	return true;
}


