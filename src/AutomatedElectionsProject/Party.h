#ifndef PARTY_H
#define PARTY_H

#include "Date.h"
#include "Candidates.h"
#include "PoliticalStream.h"

class Party
{
private:
	int _id;
	char* _name;
	PoliticalStream _politicalStream;
	Date _date;
	Candidates _candidates;

public:
	void Initialize(
		int id,
		const char* name,
		PoliticalStream politicalStream,
		const Date& date);

	char* GetName() const;
	int GetId() const;


	void AddCandidate(Candidate* candidate);
	void Show();
	void Free() const;
};
#endif // PARTY_H
