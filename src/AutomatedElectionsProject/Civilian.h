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
	void Initialize(const Civilian& other);

	char* GetName() const;
	BallotBox* GetBallotBox() const;
	void Vote(const Party& party);
	void Show() const;

	void Free() const;
};
#endif // CIVILIAN_H
