#include "MilitaryCoronaBallotBox.h"

MilitaryCoronaBallotBox::MilitaryCoronaBallotBox(const Address& address, const Date& electionsDate) :BallotBox(address, electionsDate)
{
}

bool MilitaryCoronaBallotBox::CanAdd(Civilian* civilian)
{
	return civilian->IsInArmy(_electionsDate) && civilian->GetIsQuarantined();
}
