#define  _CRT_SECURE_NO_WARNINGS

#include "Civilian.h"


#include <cstring>

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

void Civilian::Vote(const Party& party)
{
	if (_isVoted)
	{
		return;
	}
	
	_balletBox->AddVote(party);
	_isVoted = true;
}

void Civilian::Free() const
{
	delete[] _name;
}
