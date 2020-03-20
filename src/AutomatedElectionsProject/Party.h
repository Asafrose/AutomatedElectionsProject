#ifndef PARTY_H
#define PARTY_H

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
	void SetParty(
		int id,
		const char* _name,
		PoliticalStream _politicalStream,
		const Date& date);

	void Show();
	char* GetName() const;
	int GetId() const;
	void free() const;
};
#endif // PARTY_H
