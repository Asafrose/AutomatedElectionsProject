#ifndef MILITARYBALLOTBOX
#define MILITARYBALLOTBOX

#include "BallotBox.h"

class MilitaryBallotbox : public BallotBox
{
public:
	MilitaryBallotbox(const Address& address, const Date& electionsDate);
	bool CanAdd(Civilian& civilian) const override;
};




#endif