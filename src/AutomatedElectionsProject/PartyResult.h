#pragma once

class PartyResult
{
private:
	char* _name;
	int _votes;
	
public:
	PartyResult(const char* name);
	~PartyResult();
	
	void AddVote();
	void Show() const;
	bool Aggregate(const PartyResult& other);
};
