#ifndef CIVILIAN_H
#define CIVILIAN_H

#include <ostream>
#include <vector>

#include "Date.h"

using namespace std;

class BallotBox;
class Party;

class Civilian
{
	int _id;
	Date _birth;
	string _name;

	BallotBox* _balletBox;
	bool _isVoted;
	bool _isQuarantined;

public:
	Civilian(const string& name, int id, const Date& birth) noexcept(false);
	Civilian(const Civilian& other);
	Civilian(ifstream& file, const vector<BallotBox*>& ballotBoxes);
	virtual ~Civilian();
	bool GetIsQuarantined() const;
	void SetIsQuarantined(bool value);
	bool IsInArmy(const Date& electionsDate) const;

	int GetId() const;
	Date GetBirth() const;
	string GetName() const;
	BallotBox* GetBallotBox() const;
	void SetBallotBox(BallotBox& ballotBox);
	void Save(ofstream& file) const;
	void Vote(const Party& party);

	friend ostream& operator<<(ostream& os, const Civilian& civilian);
};

#endif