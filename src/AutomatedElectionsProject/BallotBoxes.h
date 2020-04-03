#ifndef BALLOTBOXES_H
#define BALLOTBOXES_H

#include "BallotBox.h"

class BallotBoxes
{
private:
	BallotBox** _array = nullptr;
	int _count = 0;
	int _physicalCount = 0;

public:
	BallotBoxes() = default;
	~BallotBoxes();
	
	void Add(BallotBox* ballotBox);
	BallotBox& Get(int index) const;
	int GetCount() const;
};
#endif // BALLOTBOXES_H
