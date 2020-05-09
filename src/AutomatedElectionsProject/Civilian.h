#ifndef CIVILIAN_H
#define CIVILIAN_H

#include <ostream>
#include "Date.h"
#include "Party.h"

using namespace std;

class BallotBox;

class Civilian
{
	int _id;
	Date _birth;
	char* _name;

	BallotBox* _balletBox;
	bool _isVoted;

public:
	Civilian(const char* name, int id, const Date& birth, BallotBox* balletBox);
	Civilian(const Civilian& other);
	~Civilian();

	char* GetName() const;
	BallotBox* GetBallotBox() const;
	void Vote(const Party& party);

	friend ostream& operator<<(ostream& os, const Civilian& civilian);
};
#endif // CIVILIAN_H
