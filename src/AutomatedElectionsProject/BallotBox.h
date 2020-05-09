#ifndef BALLOTBOX_H
#define BALLOTBOX_H

#include "Civilians.h"
#include "Address.h"
#include "Results.h"

class BallotBox
{
private:
	static int _counter;
	
	int _id;
	Address _address;
	Civilians _civilians;
	Results* _results;
protected:
	Date _electionsDate;
	
	
public:
	BallotBox(const Address& address, const Date& electionsDate);
	virtual ~BallotBox();
	
	Results& GetResults() const;
	Civilians& GetCivilians();

	virtual bool CanAdd(Civilian* civilian);

	void ClosePartyList(const Parties& parties);
	void AddCivilian(Civilian* civilian);
	void AddVote(const Party& party) const;
	double GetVotingPercent() const;
	void Show(bool showResults) const;
	
};
#endif // BALLOTBOX_H
