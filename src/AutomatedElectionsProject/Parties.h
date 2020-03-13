
#ifndef PARTIES_H
#define PARTIES_H

#include "Party.h"

class Parties
{
private:
	Party** _parties = nullptr;
	int _count = 0;

public:
	void Add(Party party);
	Party& Get(int index) const;
	int GetPartiesCount() const;
};
#endif // PARTIES_H
