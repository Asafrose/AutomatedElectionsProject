#ifndef PARTY_H
#define PARTY_H

#include "Date.h"
#include "Candidates.h"
#include "PoliticalStream.h"

class Party
{
	static int _counter;

private:
	int _id;
	char* _name;
	PoliticalStream _politicalStream;
	Date _date;
	Candidates _candidates;

public:
	Party(
		const char* name,
		PoliticalStream politicalStream,
		const Date& date);
	~Party();

	char* GetName() const;
	int GetId() const;


	void AddCandidate(Candidate* candidate);
	void Show() const;
};
#endif // PARTY_H
