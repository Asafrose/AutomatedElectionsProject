#ifndef BALLOTBOX_H
#define BALLOTBOX_H

#include "Civilians.h"
#include "Address.h"
#include "Results.h"

class BallotBox
{
private:
	int _id;
	Address& _address;
	Civilians _civilians;
	Results _results;
public:
	void Initialize(int id, const Address& address);
	void AddVote(const Party& party);
	double GetVotingPercent();
	void Show();
};
#endif // BALLOTBOX_H
