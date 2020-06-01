
#include "CoronaBallotBox.h"

CoronaBallotBox::CoronaBallotBox(const Address& address, const Date& electionsDate):BallotBox(address,electionsDate)
{	
}

bool CoronaBallotBox::CanAdd(Civilian* civilian)
{
	return !civilian->IsInArmy(_electionsDate) && civilian->GetIsQuarantined();
}


