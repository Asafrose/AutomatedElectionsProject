#ifndef CIVILIAN_H
#define CIVILIAN_H

#include <ostream>
#include "Date.h"

using namespace std;

class BallotBox;
class Party;

class Civilian
{
	int _id;
	Date _birth;
	char* _name;

	BallotBox* _balletBox;
	bool _isVoted;
	bool _isQuarantined;

public:
	Civilian(const char* name, int id, const Date& birth);
	Civilian(const Civilian& other);
	virtual ~Civilian();
	bool GetIsQuarantined() const;
	void SetIsQuarantined(bool value);
	bool IsInArmy(const Date& electionsDate) const;

	int GetId() const;
	char* GetName() const;
	BallotBox* GetBallotBox() const;
	void SetBallotBox(BallotBox* ballotBox);
	void Vote(const Party& party);

	friend ostream& operator<<(ostream& os, const Civilian& civilian);
};

#endif