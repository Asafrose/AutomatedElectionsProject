#pragma once

class PartyResult
{
private:
	char* _name;
	int _votes;
	
public:
	bool Initialize(const char* name);
	void AddVote();
	void Show() const;
	bool Aggregate(const PartyResult& other);
	void Free() const;
};
