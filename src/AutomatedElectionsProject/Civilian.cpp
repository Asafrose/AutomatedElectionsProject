#define  _CRT_SECURE_NO_WARNINGS

#include "Civilian.h"
#include "BallotBox.h"
#include <cstring>
#include <iostream>

using namespace std;

Civilian::Civilian(const char* name, int id, const Date& birth, BallotBox* balletBox) : _birth(birth)
{
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);

	_id = id;
	_balletBox = balletBox;
	_isVoted = false;
}

Civilian::Civilian(const Civilian& other) : Civilian(other._name, other._id, other._birth, other._balletBox)
{
}

char* Civilian::GetName() const
{
	return _name;
}

BallotBox* Civilian::GetBallotBox() const
{
	return _balletBox;
}

void Civilian::Vote(const Party& party)
{
	if (_isVoted)
	{
		return;
	}

	_balletBox->AddVote(party);
	_isVoted = true;
}

void Civilian::Show() const
{
	cout << "Id: " << _id << " Name: " << _name << " Birth: ";
	_birth.Show();
	cout << " IsVoted: " << _isVoted << endl;
}

Civilian::~Civilian()
{
	delete[] _name;
}
