#define  _CRT_SECURE_NO_WARNINGS

#include "Civilian.h"
#include "BallotBox.h"
#include <cstring>
#include <iostream>

using namespace std;

void Civilian::Initialize(
	const char* name,
	int id,
	const Date& birth,
	BallotBox* balletBox)
{
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);

	_id = id;
	_birth = birth;
	_balletBox = balletBox;
	_isVoted = false;
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
	cout << " IsVoted: " << _isVoted;
}

void Civilian::Free() const
{
	delete[] _name;
}
