#pragma once

class PartyResult
{
	const char* _name;
	int _votes;
public:
	bool Initialize(const char* name);
	void AddVote();
	void Show() const;
};
