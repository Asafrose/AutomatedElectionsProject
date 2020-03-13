#pragma once

class PartyResult
{
	char* _name;
	int _votes;
public:
	void Initialize(const char* name);
	void AddVote();
	void Show();
};
