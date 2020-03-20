#define _CRT_SECURE_NO_WARNINGS

#include "Party.h"
#include <cstring>
#include <iostream>

using namespace std;

void Party::SetParty(int id, const char* name, PoliticalStream politicalStream, const Date& date)
{
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_id = id;
	_politicalStream = politicalStream;
	_date = date;
}

void Party::Show()
{
	cout << "Party ID: " << _id << " Party Name: " << _name << "Political Stream: ";

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
	cout << "Date Established: ";
	_date.ShowDate();
}

int Party::GetId() const
{
	return _id;
}

void Party::AddCandidate(Candidate& candidate)
{
	_candidates.Add(candidate);
}

char* Party::GetName() const
{
	return _name;
}

void Party::Free() const
{
	delete _name;
}
