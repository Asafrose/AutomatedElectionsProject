#ifndef BALLOTBOX_H
#define BALLOTBOX_H

#include <vector>

#include "Address.h"
#include "Civilian.h"
#include "Results.h"

class BallotBox
{
private:
	static int _counter;
	
	int _id;
	Address _address;
	vector<Civilian*> _civilians;
	Results* _results;
protected:
	Date _electionsDate;
	
	
public:
	BallotBox(const Address& address, const Date& electionsDate);
	BallotBox(ifstream& file,const Date& electionsDate);
	virtual ~BallotBox();
	
	Results& GetResults() const;
	int GetId() const ;
	vector<Civilian*>& GetCivilians();

	virtual bool CanAdd(Civilian& civilian) const;

	void ClosePartyList(const Array<Party*>& parties);
	void AddCivilian(Civilian* civilian);
	void AddVote(const Party& party) const;
	double GetVotingPercent() const;
	void Show(bool showResults) const;
	void virtual Save(ofstream& file) const;
	
};
#endif // BALLOTBOX_H
