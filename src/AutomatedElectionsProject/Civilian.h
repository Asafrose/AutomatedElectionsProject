#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Date.h"
#include "Party.h"

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
	void Show() const;
};
#endif // CIVILIAN_H
