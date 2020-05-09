
#include "CoronaBallotBox.h"

CoronaBallotbox::CoronaBallotbox(const Address& address, const Date& electionsDate):BallotBox(address,electionsDate)
{	
}

bool CoronaBallotbox::CanAdd(Civilian* civilian)
{
	return !civilian->IsInArmy(_electionsDate) && civilian->GetIsQuarantined();
}


