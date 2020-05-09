#define _CRT_SECURE_NO_WARNINGS

#include "Party.h"
#include <cstring>
#include <iostream>

using namespace std;

int Party::_counter = 1;

Party::Party(const char* name, PoliticalStream politicalStream, const Date& date) : _date(date)
{
	_id = _counter++;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_politicalStream = politicalStream;
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
	return _candidates.GetCount() > other._candidates.GetCount();
}

bool Party::operator<(Party& other) const
{
	return _candidates.GetCount() < other._candidates.GetCount();
}

bool Party::operator==(Party& other) const
{
	return _candidates.GetCount() == other._candidates.GetCount();
}

int Party::GetId() const
{
	return _id;
}

void Party::AddCandidate(Candidate* candidate)
{
	_candidates.Add(candidate);
	_candidates.Sort();
}

char* Party::GetName() const
{
	return _name;
}

Party::~Party()
{
	delete[] _name;
}
