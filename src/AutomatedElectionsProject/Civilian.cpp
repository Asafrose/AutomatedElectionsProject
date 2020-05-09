#define  _CRT_SECURE_NO_WARNINGS

#include "Civilian.h"
#include "BallotBox.h"
#include <cstring>
#include <iostream>

using namespace std;

Civilian::Civilian(const char* name, int id, const Date& birth) : _birth(birth)
{
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);

	_id = id;
	_balletBox = nullptr;
	_isVoted = false;
	_isQuarantined = false;
}

Civilian::Civilian(const Civilian& other) : Civilian(other._name, other._id, other._birth)
{
	_isQuarantined = other._isQuarantined;
	_balletBox = other.GetBallotBox();
}

char* Civilian::GetName() const
{
	return _name;
}

BallotBox* Civilian::GetBallotBox() const
{
	return _balletBox;
}

void Civilian::SetBallotBox(BallotBox* ballotBox)
{
	_balletBox = ballotBox;
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

 Civilian::~Civilian()
{
	delete[] _name;
}

ostream& operator<<(ostream& os, const Civilian& civilian)
{
	os << "Id: " << civilian._id << " Name: " << civilian._name << " Birth: " << civilian._birth << " IsQuarantined: " << civilian._isQuarantined << " IsVoted: " << civilian._isVoted;
	return os;
}

bool Civilian::GetIsQuarantined() const
{
	return _isQuarantined;
}

void Civilian::SetIsQuarantined(bool value)
{
	_isQuarantined = value;
}

bool Civilian::IsInArmy(const Date& electionsDate) const
{
	const int age = electionsDate.GetYear() - _birth.GetYear();

	return age >= 18 && age <= 21;
}

int Civilian::GetId() const
{
	return _id;
}

