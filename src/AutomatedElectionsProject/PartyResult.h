
#ifndef PARTYRESULT_H
#define PARTYRESULT_H
#include <string>
using namespace  std; 

class PartyResult
{
private:
	string _name;
	int _votes;
	
public:
	PartyResult(const string& name);
	~PartyResult() = default;
	
	void AddVote();
	void Show() const;
	bool Aggregate(const PartyResult& other);
};
#endif // PARTYRESULT_H
