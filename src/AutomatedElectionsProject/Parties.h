
#ifndef PARTIES_H
#define PARTIES_H

#include "Party.h"

class Parties
{
private:
	Party** _array = nullptr;
	int _count = 0;
	int _physicalCount = 0;

public:
	Parties() = default;
	~Parties();
	
	void Add(Party* party);
	Party& Get(int index) const;
	int GetCount() const;
};
#endif // PARTIES_H
