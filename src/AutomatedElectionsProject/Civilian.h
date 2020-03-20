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
	void Initialize(
		const char* name,
		int id,
		const Date& birth,
		BallotBox* balletBox);

	BallotBox* GetBallotBox() const;
	void Vote(const Party& party);

	void Free() const;
};
#endif // CIVILIAN_H
