#ifndef BALLOTBOX_H
#define BALLOTBOX_H

#include "Civilians.h"
#include "Address.h"
#include "Results.h"

class BallotBox
{
private:
	int _id;
	Address _address;
	Civilians _civilians;
	Results* _results;
	
public:
	void Initialize(const int& id, const Address& address);
	Results& GetResults() const;
	
	void ClosePartyList(const Parties& parties);

	void AddCivilian(Civilian* civilian);
	void AddVote(const Party& party) const;
	double GetVotingPercent() const;
	void Show() const;
	void Free() const;
};
#endif // BALLOTBOX_H
