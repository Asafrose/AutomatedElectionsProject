#include "CoronaBallotBox.h"

CoronaBallotBox::CoronaBallotBox(const Address& address, const Date& electionsDate): BallotBox(address, electionsDate)
{
}

CoronaBallotBox::CoronaBallotBox(ifstream& file, const Date& electionsDate) : BallotBox(file, electionsDate)
{
}

bool CoronaBallotBox::CanAdd(Civilian& civilian) const
{
	return !civilian.IsInArmy(_electionsDate) && civilian.GetIsQuarantined();
}
