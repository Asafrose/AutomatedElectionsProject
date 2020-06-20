#ifndef PARTY_H
#define PARTY_H

#include <vector>

#include "Date.h"
#include "Candidate.h"
#include "PoliticalStream.h"

class Party
{
	static int _counter;

private:
	int _id;
	string _name;
	PoliticalStream _politicalStream;
	Date _date;
	vector<Candidate> _candidates;

public:
	Party(
		const string& name,
		PoliticalStream politicalStream,
		const Date& date);
	Party(Party& other);
	~Party() = default;

	string GetName() const;
	int GetId() const;


	void AddCandidate(Candidate& candidate);
	void Show() const;

	bool operator>(const Party& other) const;
	bool operator<(const Party& other) const;
	bool operator==(const Party& other) const;
};
#endif // PARTY_H
