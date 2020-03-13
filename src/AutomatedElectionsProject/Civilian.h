#ifndef CIVILIAN_H
#define CIVILIAN_H

#include "Date.h"
#include "Party.h"

class BalletBox;

class Civilian
{
	int _id;
	Date _birth;
	char* _name;

	BalletBox* _balletBox;
	bool _isVoted;

public:
	void SetCivilian(
		const char* name,
		int id,
		Date birth,
		const BalletBox* balletBox);

	void Vote(Party party);
};
#endif // CIVILIAN_H
