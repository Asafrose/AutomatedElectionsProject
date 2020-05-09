
#include  "BallotBox.h"

#ifndef MILITARYCORONABALLOTBOX_H
#define MILITARYCORONABALLOTBOX_H

class MilitaryCoronaBallotBox : public BallotBox
{
public:
	MilitaryCoronaBallotBox(const Address& address, const Date& electionsDate);
	bool CanAdd(Civilian* civilian) override;
	
};
#endif // MILITARYCORONABALLOTBOX_H
