#define _CRT_SECURE_NO_WARNINGS

#include "Party.h"
#include <cstring>
#include <iostream>

#include "Exception.h"

using namespace std;

int CompareRanks(const void* candidate1, const void* candidate2)
{
	return ((Candidate*)candidate1)->GetRank() - ((Candidate*)candidate2)->GetRank();
}

int Party::_counter = 1;

Party::Party(const string& name, PoliticalStream politicalStream, const Date& date) noexcept(false) : _date(date), _name(name)
{
	if (Date::Now()-_date < Duration::FromDays(0))
	{
		throw Exception("party date cannot be in the future");
	}
	
	_id = _counter++;
	_politicalStream = politicalStream;
}

Party::Party(Party& other) : _id(other._id), _politicalStream(other._politicalStream), _date(other._date), _name(other.GetName())
{
}

void Party::Show() const
{
	cout << "Party ID: " << _id << " Party Name: " << _name << " Political Stream: ";

	switch (_politicalStream)
	{
	case Right:
		{
			cout << " Right ";
			break;
		}
	case Left:
		{
			cout << " Left ";
			break;
		}
	case Center:
		{
			cout << " Center ";
			break;
		}
	}
	cout << "Date Established: " << _date << endl;
}

bool Party::operator>(Party& other) const
{
	return _candidates.size() > other._candidates.size();
}

bool Party::operator<(Party& other) const
{
	return _candidates.size() < other._candidates.size();
}

bool Party::operator==(Party& other) const
{
	return _candidates.size() == other._candidates.size();
}

int Party::GetId() const
{
	return _id;
}

void Party::AddCandidate(Candidate& candidate)
{
	_candidates.push_back(candidate);
	qsort(&_candidates[0], _candidates.size(), sizeof(Candidate), CompareRanks);
}

string Party::GetName() const
{
	return _name;
}
