#define  _CRT_SECURE_NO_WARNINGS

#include "Civilian.h"
#include "BallotBox.h"
#include <string>
#include <sstream>
#include "FileHelper.h"

#include "Exception.h"

using namespace std;

Civilian::Civilian(const string& name, int id, const Date& birth) noexcept(false) : _birth(birth), _name(name)
{
	if (id < 100000000 || id > 999999999)
	{
		stringstream stringStream;
		stringStream << "ID is not a 9-digit number [name=" << name << " ID=" << id << "]";
		throw Exception(stringStream.str());
	}
	if (Date::Now() - _birth < Duration::FromDays(0))
	{
		stringstream stringStream;
		stringStream << "Civilian birth cannot be in the future [name=" << name << " ID=" << id << " Birth=" << _birth
			<< "]";
		throw Exception(stringStream.str());
	}

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

Civilian::Civilian(ifstream& file, const vector<BallotBox*>& ballotBoxes) : _id(0), _birth(file), _isVoted(false),
                                                                      _isQuarantined(false)
{
	FileHelper::Read(_id, file);
	FileHelper::ReadString(_name, file);
	FileHelper::Read(_isQuarantined, file);
	int ballotBoxId;
	FileHelper::Read(ballotBoxId, file);
	_balletBox = ballotBoxes[ballotBoxId-1];
	_balletBox->AddCivilian(this);
}


Civilian::~Civilian()
{
}

string Civilian::GetName() const
{
	return _name;
}

BallotBox* Civilian::GetBallotBox() const
{
	return _balletBox;
}

void Civilian::SetBallotBox(BallotBox& ballotBox)
{
	_balletBox = &ballotBox;
}

void Civilian::Save(ofstream& file) const
{
	FileHelper::Write(_birth, file);
	FileHelper::Write(_id, file);
	FileHelper::WriteString(_name, file);
	FileHelper::Write(_isQuarantined, file);
	FileHelper::Write(_balletBox->GetId(), file);
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

ostream& operator<<(ostream& os, const Civilian& civilian)
{
	os << "Id: " << civilian._id << " Name: " << civilian._name << " Birth: " << civilian._birth << " IsQuarantined: "
		<< civilian._isQuarantined << " IsVoted: " << civilian._isVoted;
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
	Duration ageAtElections = electionsDate - _birth;

	return ageAtElections >= Duration::FromYears(18) && ageAtElections <= Duration::FromYears(21);
}

int Civilian::GetId() const
{
	return _id;
}

Date Civilian::GetBirth() const
{
	return _birth;
}
